#include "m_set.h"
#include "ui_m_set.h"
#include <QListWidgetItem>
#include <QDebug>
#include <cstring>
#include<QFileDialog>
#include <QCheckBox>
#include <QMessageBox>
#pragma execution_character_set("UTF-8")
m_set::m_set(QWidget *parent, solution *sol) :
    QDialog(parent),
    ui(new Ui::m_set),
    s1(sol)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(1, 200);
    initTableW();

}

m_set::~m_set()
{
    delete ui;
}

void m_set::on_btn_load_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("VM方案 (*.hpmxml)"));
    if (!filePath.isEmpty()) {
        ui->path->setText(filePath);
    }
}
void m_set::initTableW()
{
    if(s1->pVmSol == nullptr)
    {
    }
    else{
        // 清空现有行
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

void m_set::on_btn_sub_clicked()
{
    bool success = false;
    IMVSHPFeatureMatchModuTool* HFMMT = nullptr;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        // 获取当前行的 QCheckBox 和 QLabel
        QCheckBox *checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(row, 0));
        QLabel *label = qobject_cast<QLabel*>(ui->tableWidget->cellWidget(row, 1));
        if (checkBox && checkBox->isChecked() && label) {
            QString moduleName = label->text();
            try {
                HFMMT = (IMVSHPFeatureMatchModuTool*)(*s1->pVmSol)[moduleName.toStdString().c_str()];
                if (HFMMT) {
                    ModuleImportData md;
                    QString filePath = ui->path->text();
                    md.pData = new char[filePath.length() + 1];
                    std::strcpy(md.pData, filePath.toStdString().c_str()); // 设置文件路径
                    std::fill(std::begin(md.nReserved), std::end(md.nReserved), 0);
                    HFMMT->ImportModelData(&md,1);
                    delete[] md.pData;
                    success = true; // 标记为成功
                }
                else{
                    QMessageBox::warning(this, tr("警告"), tr("无法找到模块: %1").arg(moduleName));
                }
            } catch (CVmException vmex) {
                QMessageBox::warning(this, tr("警告"), tr("无法找到模块: %1").arg(moduleName));
            }
        }
    }
    if (success) {
        // 显示成功的弹窗
        QMessageBox::information(this, tr("成功"), tr("模型导入成功"));
    }
}
