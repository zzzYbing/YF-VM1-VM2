#include "dlg_control.h"
#include "ui_dlg_control.h"
#include <QMessageBox>
#include <QStandardPaths>
#pragma execution_character_set("UTF-8")
Dlg_Control::Dlg_Control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Control),
    tcpServer(new QTcpServer(this)),
    clientSocket(nullptr),
    isListening(false)
{
    ui->setupUi(this);

    connect(tcpServer, &QTcpServer::newConnection, this, [=]() {
        clientSocket = tcpServer->nextPendingConnection();
        connect(clientSocket, &QIODevice::readyRead, this, &Dlg_Control::onReadyRead);
    });
    initpage();
}

Dlg_Control::~Dlg_Control()
{
    if (DB.isOpen()) {
        DB.close();
    }
    delete ui;
}
void Dlg_Control::initpage()
{
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(QDir::currentPath()+"/book2.db");//打开数据库
    if (DB.open())
    {
        qDebug() << "Database opened successfully";
    }
    else
    {
        qDebug() << "无法打开数据库：" << DB.lastError().text();
    }
    QSqlQuery query("SELECT * FROM iport WHERE id = 1");
    if (query.next()){
        ui->le_ip->setText(query.value(0).toString());
        ui->le_port->setText(query.value(1).toString());
        on_btn_listen_clicked();
    }
}
void Dlg_Control::on_btn_listen_clicked()
{
    if (isListening) {
        tcpServer->close();
        isListening = false;
    } else {
        QString ipAddress = ui->le_ip->text();
        quint16 port = ui->le_port->text().toUInt();

        QHostAddress address(ipAddress);
        if (!tcpServer->listen(address, port)) {
            QMessageBox::critical(this, "Error", tcpServer->errorString());
            return;
        }

        isListening = true;
    }
    ui->btn_listen->setText(isListening ? "断开监听" : "监听");

}

void Dlg_Control::onReadyRead()
{
    if (clientSocket) {
        QByteArray data = clientSocket->readAll();
        QString command = QString::fromUtf8(data);

        // 处理指令
        if(command.contains("CM2_varname"))
        {
            // 解析指令内容
            QStringList parts = command.split(';');
            QString varName;
            QString varValue;

            for (const QString &part : parts) {
                if (part.startsWith("CM2_varname:")) {
                    varName = part.mid(12); // 去掉"varname:"前缀
                } else if (part.startsWith("varvalue:")) {
                    varValue = part.mid(9); // 去掉"varvalue:"前缀
                }
            }
            GlobalVariableModuleTool * pGlobalVarTool = GetGlobalVariableToolInstance();
            pGlobalVarTool->SetGlobalVar(varName.toUtf8().constData(),varValue.toUtf8().constData());
        }
        else if(command.contains("CM3_Params"))
        {
            QStringList parts = command.split('=');
            QStringList leftData = parts[0].remove("CM3_Params:(").remove(')').split(':');
            QStringList rightData = parts[1].remove('(').remove(')').split(':');
            GlobalVariableModuleTool * pGlobalVarTool = GetGlobalVariableToolInstance();
            for (int i = 0; i < 13; ++i) {
                pGlobalVarTool->SetGlobalVar(leftData[i].toUtf8().constData(),rightData[i].toUtf8().constData());
            }
        }
        else if(command.contains("CM4_solname"))
        {
            QString fileName = command.remove("CM4_solname:");
            QString path = QDir::currentPath()+"/Solution/"+fileName;

            try
            {
                s1->pVmSol = LoadSolution(path.toStdString().c_str(),"");
            }
            catch (CVmException vmex) {
                vmex.GetErrorCode();
                QMessageBox::warning(this, "ERROR", "方案不存在,请先发送方案");
            }
        }
        else if (command.contains("CM5_solname")) {
            QStringList parts = command.split(';');
            QString solname = parts[0].remove("CM5_solname:");
            QString filename = parts[1].remove("FileName:");
            QString path = QDir::currentPath() + "/Solution/" + filename;

            if (QFile::exists(path)) {
                QMessageBox::warning(this, "ERROR", "方案文件已存在");
            } else {
                DB = QSqlDatabase::addDatabase("QSQLITE");
                DB.setDatabaseName(QDir::currentPath()+"/book2.db");//打开数据库
                if (DB.open())
                {
                    qDebug() << "Database opened successfully";
                }
                else
                {
                    qDebug() << "无法打开数据库：" << DB.lastError().text();
                }
                QSqlQuery query;
                query.prepare("SELECT path FROM sol ORDER BY id DESC LIMIT 1");
                if (query.exec()) {
                    QString lastPath = "no";
                    if (query.next()) {
                        lastPath = query.value(0).toString();
                    }

                    // Check if lastPath is valid before copying
                    if (lastPath != "no" && QFile::exists(lastPath)) {
                        if (QFile::copy(lastPath, path)) {
                            query.prepare("INSERT INTO sol (name, path) VALUES (:name, :path)");
                            query.bindValue(":name", solname);
                            query.bindValue(":path", path);
                            if (query.exec()) {
                                QMessageBox::information(this, "Success", "方案文件处理成功");
                            } else {
                                QMessageBox::warning(this, "ERROR", "数据库插入失败");
                            }
                        } else {
                            QMessageBox::warning(this, "ERROR", "文件复制失败");
                        }
                    } else {
                        QMessageBox::warning(this, "ERROR", "上一个文件路径无效");
                    }
                } else {
                    QMessageBox::warning(this, "ERROR", "数据库查询失败");
                }
                if (DB.open())
                {
                    DB.close();
                }
            }
        }
        else
        {
            le_data = le_data + data;
            if(data.contains("----")){
                QMessageBox::warning(this, "ERROR", "开始保存文件");
                QStringList parts = le_data.split("----");
                QString fileDATA = parts[0];
                QString inst = parts[1];
                QString filename = inst.split(";")[0].split("/").last();
                QStringList module = inst.split(";");
                QString modulename;
                // 获取路径
                QString desktopPath = QDir::currentPath() + "/Model";
                QString filePath = QDir(desktopPath).filePath(filename);
                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    out << fileDATA;
                    file.close();
                    QMessageBox::warning(this, "ERROR", "保存成功");
                    IMVSHPFeatureMatchModuTool* HFMMT = nullptr;
                    for(int i = 1;i < module.size();i ++)
                    {
                        modulename = module[i];
                        HFMMT = (IMVSHPFeatureMatchModuTool*)(*s1->pVmSol)[modulename.toStdString().c_str()];
                        if (HFMMT) {
                            ModuleImportData md;
                            md.pData = new char[filePath.length() + 1];
                            std::strcpy(md.pData, filePath.toStdString().c_str()); // 设置文件路径
                            std::fill(std::begin(md.nReserved), std::end(md.nReserved), 0);
                            HFMMT->ImportModelData(&md,1);
                            delete[] md.pData;
                        }else{
                            QMessageBox::warning(this, tr("警告"), tr("无法找到模块: %1").arg(modulename));
                        }
                    }
                } else {
                    QMessageBox::warning(this, "ERROR", "保存失败");
                }
                le_data = "";
            }
        }
    }
}
void Dlg_Control::getiport()
{
    ip = ui->le_ip->text();
    port = ui->le_port->text();
}
