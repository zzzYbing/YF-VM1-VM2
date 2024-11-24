#include "setcl.h"
#include "ui_setcl.h"

#include <QSqlError>
#include <QCheckBox>

setcl::setcl(const QString &initialLink,QWidget *parent,solution *s1) :
    QDialog(parent),
    link(initialLink),
    ui(new Ui::setcl),
    s1(s1)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(1, 200);
    if(link.contains("CM1"))
    {
        ui->CM1->setChecked(true);
    }
    else if(link.contains("CM2"))
    {
        ui->CM2->setChecked(true);
    }
    else if(link.contains("CM3"))
    {
        ui->CM3->setChecked(true);
    }
    else if(link.contains("CM4"))
    {
        ui->CM4->setChecked(true);
    }
    else if(link.contains("CM5"))
    {
        ui->CM5->setChecked(true);
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+"\\book.db");  // 数据库路径
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the database." << db.lastError().text();
        return;
    }
    inittableWidget();
    initc_var();
    initsol();
}

setcl::~setcl()
{
    if(true == ui->CM1->isChecked())
    {
        QString cm1_path = ui->path->text();
        link = "CM1_path:"+cm1_path;
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(row, 0)); // 假设复选框在第0列
            QLabel *moduleNameEdit = qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row, 1)); // 假设模块名称在第1列

            if (checkBox && checkBox->isChecked()) {
                QString moduleName = moduleNameEdit->text();
                link = link+";"+moduleName; // 这里将模块名称赋给 link
            }
        }
    }
    else if(true == ui->CM2->isChecked())
    {
        link = "CM2_varname:"+ui->c_var->currentText()+";varvalue:"+ui->v_var->text();
    }
    else if(true == ui->CM3->isChecked())
    {
        //        CMD3_Params:(a:b:c:d:xizui1:xizui2:xizui3:xizui4:STAngle:STPX:STPY:STX:STY)=(0:2:3:4:1:1:0:0:0:0:0:0:0)

        bool b = true;
        GlobalVariableModuleTool * pGlobalVarTool = GetGlobalVariableToolInstance();
        for (int i= 0; i <5; ++i) {
            try {
                pGlobalVarTool->GetGlobalVar(strParam[i],strVal[i]);
            } catch (CVmException vmex) {
                vmex.GetErrorCode();
                b = false;
                break;
            }
        }
        if(b){
            link = "CM3_Params:(a:b:c:d:xizui1:xizui2:xizui3:xizui4:STAngle:STPX:STPY:STX:STY)=("+
                    ui->le_1->text()+":"+ui->le_2->text()+":"+ui->le_3->text()+":"+ui->le_4->text()+":"+
                    QString::number(ui->cb_1->isChecked())+":"+QString::number(ui->cb_2->isChecked())+":"+
                    QString::number(ui->cb_3->isChecked())+":"+QString::number(ui->cb_4->isChecked())+":"+
                    QString::fromUtf8(strVal[0])+":"+QString::fromUtf8(strVal[1])+":"+QString::fromUtf8(strVal[2])+":"+
                    QString::fromUtf8(strVal[3])+":"+QString::fromUtf8(strVal[4])+")";
        }else{
            link = "";
        }
    }
    else if(true == ui->CM4->isChecked())
    {
        int s_i = ui->s_switch->currentIndex();
        QString paths_s = paths[s_i];
        QFileInfo fileInfo(paths_s);
        QString fileName = fileInfo.fileName();
        link = "CM4_solname:"+fileName;
    }
    else if(true == ui->CM5->isChecked())
    {
        int s_i = ui->s_send->currentIndex();
        QString paths_s = paths[s_i];
        QFileInfo fileInfo(paths_s);
        QString fileName = fileInfo.fileName();
        link = "CM5_solname:"+ui->s_send->currentText()+";FileName:"+fileName;
    }
    else
    {
        link = "";
    }
    emit dataUpdated(link);
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}

void setcl::on_btn_load_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("VM方案 (*.hpmxml)"));
    if (!filePath.isEmpty()) {
        ui->path->setText(filePath);
    }
}
void setcl::initc_var()
{
    ui->c_var->clear();
    if(s1->pVmSol == nullptr)
    {
    }
    else
    {
    GlobalVariableModuleTool * pGlobalVarTool = GetGlobalVariableToolInstance();
    GlobalVarInfoList * gl = pGlobalVarTool->GetAllGlobalVar();
    for (int i = 0;i < gl->nCount;++i) {
        GlobalVarInfo itg = gl->stGlobalValue[i];
        ui->c_var->addItem(itg.strValueName);
    }
    }
}
void setcl::initsol()
{
    ui->s_switch->clear();
    ui->s_send->clear();
    names.clear();
    paths.clear();

    QSqlQuery query("SELECT name, path FROM sol");
    if (query.exec())
    {
        while (query.next()){
            QString name = query.value(0).toString();
            QString path = query.value(1).toString();

            names.append(name);
            paths.append(path);

            ui->s_switch->addItem(name);
            ui->s_send->addItem(name);
        }
    }
}
void setcl::inittableWidget()
{
    if(s1->pVmSol == nullptr)
    {
    }
    else
    {
        ui->tableWidget->setRowCount(0);
        ProcessInfoList* pl = s1->pVmSol->GetAllProcedureList();
        ModuleInfoList* ml = s1->pVmSol->GetAllModuleList();
        for (unsigned int i = 0;i < ml->nNum; ++i) {
            ModuInfo itm = ml->astModuleInfo[i];
            QString hh = "IMVSHPFeatureMatchModu";
            if(itm.strModuleName == hh)
            {
                for (unsigned int j = 0;j < pl->nNum; ++j) {
                    ProcessInfo itp = pl->astProcessInfo[j];
                    if(itm.nProcessID == itp.nProcessID)
                    {
                        int rowCount = ui->tableWidget->rowCount();
                        ui->tableWidget->insertRow(rowCount);

                        QString itp_name = itp.strProcessName;
                        QString itm_name = itm.strDisplayName;
                        QString m_p = itp_name+"."+itm_name;

                        QCheckBox *checkBox = new QCheckBox();
                        QLabel *lb = new QLabel(m_p);

                        ui->tableWidget->setCellWidget(rowCount, 0, checkBox);
                        ui->tableWidget->setCellWidget(rowCount, 1, lb);
                    }
                }
            }
        }
    }
}
