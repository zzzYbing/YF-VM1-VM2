#include "dlg_control.h"
#include "ui_dlg_control.h"
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QMessageBox>
#pragma execution_character_set("UTF-8")
Dlg_Control::Dlg_Control(QWidget *parent) :
    QDialog(parent),
    s1(new solution(this)),
    ui(new Ui::Dlg_Control)
{
    ui->setupUi(this);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(QDir::currentPath()+"\\book.db");//打开数据库
    if (DB.open())
    {
        qDebug() << "Database opened successfully";
        loadDataFromDatabase();
    }
    else
    {
        qDebug() << "无法打开数据库：" << DB.lastError().text();
    }
    initTable();
}

Dlg_Control::~Dlg_Control()
{
    if (DB.isOpen()) {
        DB.close();
    }
    for (QTcpSocket* socket : tcpClients) {
        socket->disconnectFromHost();
        socket->deleteLater();
    }
    delete ui;

}
void Dlg_Control::initTable()
{
    ui->tableWidget->setColumnHidden(6, true); // 隐藏第七列，索引从0开始
    // 设置固定宽度的列
    ui->tableWidget->setColumnWidth(0, 80);

    // 获取表头对象
    QHeaderView *header = ui->tableWidget->horizontalHeader();

    // 对所有列设置为均匀分布
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        if (i != 0) {
            header->setSectionResizeMode(i, QHeaderView::Stretch);
        } else {
            header->setSectionResizeMode(i, QHeaderView::Fixed);
        }
    }

}

void Dlg_Control::on_addButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    QCheckBox *checkBox = new QCheckBox();
    QLineEdit *ipEdit = new QLineEdit();
    QLineEdit *portEdit = new QLineEdit();
    QPushButton *connectButton = new QPushButton("连接");
    QLineEdit *sendEdit = new QLineEdit();
    QPushButton *setbtn = new QPushButton("设置");
    QPushButton *delbtn = new QPushButton("删除");

    ui->tableWidget->setCellWidget(rowCount, 0, checkBox);
    ui->tableWidget->setCellWidget(rowCount, 1, ipEdit);
    ui->tableWidget->setCellWidget(rowCount, 2, portEdit);
    ui->tableWidget->setCellWidget(rowCount, 3, connectButton);
    ui->tableWidget->setCellWidget(rowCount, 4, setbtn);
    ui->tableWidget->setCellWidget(rowCount, 5, delbtn);
    ui->tableWidget->setCellWidget(rowCount, 6, sendEdit);
    sendEdit->setText("111");
    // 连接删除按钮的点击信号
    connect(delbtn, &QPushButton::clicked, [this, rowCount]() {
        ui->tableWidget->removeRow(rowCount);
    });
    // 设置按钮事件
    connect(setbtn, &QPushButton::clicked,[this,sendEdit]()
    {
        setcl  sl(sendEdit->text(),this,s1); // 传递当前窗口作为父窗口
        sl.exec();
        connect(&sl, &setcl::dataUpdated, [sendEdit](const QString &data) {
            sendEdit->setText(data);
        });
        sl.deleteLater(); // 对话框结束后删除
    });
    // 连接按钮的点击信号
    connect(connectButton, &QPushButton::clicked, [this, connectButton, ipEdit, portEdit, sendEdit, checkBox]() {
        if (connectButton->text() == "连接")
        {
            QTcpSocket *socket = new QTcpSocket(this);
            QString ip = ipEdit->text();
            quint16 port = portEdit->text().toUShort();
            socket->setProperty("ip", ip);  // 设置 IP 地址属性
            socket->connectToHost(ip, port);

            if (socket->waitForConnected()) {
                tcpClients.append(socket);
                socket->setProperty("sendEdit", QVariant::fromValue(sendEdit));
                socket->setProperty("checkBox", QVariant::fromValue(checkBox));
                connectButton->setText("断开");
            } else {
                QMessageBox::warning(this, "ERROR", "连接失败");
                socket->deleteLater();
            }
        }
        else if (connectButton->text() == "断开")
        {
            QString currentIp = ipEdit->text();  // 获取当前行的 IP 地址
            for (int i = 0; i < tcpClients.size(); ++i) {
                QTcpSocket* socket = tcpClients[i];
                if (socket->property("ip").toString() == currentIp) {  // 根据 IP 地址匹配
                    socket->disconnectFromHost();
                    socket->deleteLater();
                    tcpClients.remove(i);
                    break;  // 找到并断开后退出循环
                }
            }
            connectButton->setText("连接");
        }
    });
}

void Dlg_Control::on_sendButton_clicked()
{
    const int chunkSize = 1024 * 1024; // 1MB chunk size

    for (QTcpSocket* socket : tcpClients) {
        QLineEdit *sendEdit = socket->property("sendEdit").value<QLineEdit*>();
        QCheckBox *checkBox = socket->property("checkBox").value<QCheckBox*>();

        if (checkBox->isChecked() && sendEdit) {
            QString data = sendEdit->text();
            if (data.contains("CM1")) {
                QStringList parts = data.split(";");
                if (parts.size() > 1) {
                    QString filePathPart = parts[0];
                    QString filePath = filePathPart.split(":")[1] + ":" + filePathPart.split(":")[2]; // 从指令中获取文件路径

                    QFile file(filePath);
                    if (file.open(QIODevice::ReadOnly)) {
                        qint64 fileSize = file.size();
                        qint64 bytesSent = 0;

                        while (bytesSent < fileSize) {
                            QByteArray chunk = file.read(chunkSize);
                            socket->write(chunk);
                            socket->flush();
                            bytesSent += chunk.size();
                        }

                        file.close();

                        // 发送分隔符和数据的剩余部分
                        socket->write("----");
                        socket->flush();
                    } else {
                        qWarning() << "Failed to open file:" << file.errorString();
                    }
                } else {
                    socket->write(data.toUtf8());
                    socket->flush();
                }
            }
            socket->write(data.toUtf8());
            socket->flush();
        }
    }
}

void Dlg_Control::loadDataFromDatabase()
{
    QSqlQuery query("SELECT ip, port FROM iport");
    if (query.exec())
    {
        while (query.next())
        {
            QString ip = query.value(0).toString();
            QString port = query.value(1).toString();

            int rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);

            QCheckBox *checkBox = new QCheckBox();
            QLineEdit *ipEdit = new QLineEdit(ip);
            QLineEdit *portEdit = new QLineEdit(port);
            QPushButton *connectButton = new QPushButton("连接");
            QLineEdit *sendEdit = new QLineEdit();
            QPushButton *setbtn = new QPushButton("设置");
            QPushButton *delbtn = new QPushButton("删除");

            ui->tableWidget->setCellWidget(rowCount, 0, checkBox);
            ui->tableWidget->setCellWidget(rowCount, 1, ipEdit);
            ui->tableWidget->setCellWidget(rowCount, 2, portEdit);
            ui->tableWidget->setCellWidget(rowCount, 3, connectButton);
            ui->tableWidget->setCellWidget(rowCount, 4, setbtn);
            ui->tableWidget->setCellWidget(rowCount, 5, delbtn);
            ui->tableWidget->setCellWidget(rowCount, 6, sendEdit);

            connect(delbtn, &QPushButton::clicked, [this, rowCount]() {
                ui->tableWidget->removeRow(rowCount);
            });
            // 设置按钮事件
            connect(setbtn, &QPushButton::clicked,[this,sendEdit]()
            {
                setcl  sl(sendEdit->text(),this,s1); // 传递当前窗口作为父窗口
                sl.exec();
                connect(&sl, &setcl::dataUpdated, [sendEdit](const QString &data) {
                    sendEdit->setText(data);
                });
                sl.deleteLater(); // 对话框结束后删除
            });
            connect(connectButton, &QPushButton::clicked, [this, connectButton, ipEdit, portEdit, sendEdit, checkBox]() {
                if (connectButton->text() == "连接")
                {
                    QTcpSocket *socket = new QTcpSocket(this);
                    QString ip = ipEdit->text();
                    quint16 port = portEdit->text().toUShort();
                    socket->setProperty("ip", ip);  // 设置 IP 地址属性
                    socket->connectToHost(ip, port);

                    if (socket->waitForConnected()) {
                        tcpClients.append(socket);
                        socket->setProperty("sendEdit", QVariant::fromValue(sendEdit));
                        socket->setProperty("checkBox", QVariant::fromValue(checkBox));
                        connectButton->setText("断开");
                    } else {
                        QMessageBox::warning(this, "ERROR", "连接失败");
                        socket->deleteLater();
                    }
                }
                else if (connectButton->text() == "断开")
                {
                    QString currentIp = ipEdit->text();  // 获取当前行的 IP 地址
                    for (int i = 0; i < tcpClients.size(); ++i) {
                        QTcpSocket* socket = tcpClients[i];
                        if (socket->property("ip").toString() == currentIp) {  // 根据 IP 地址匹配
                            socket->disconnectFromHost();
                            socket->deleteLater();
                            tcpClients.remove(i);
                            break;  // 找到并断开后退出循环
                        }
                    }
                    connectButton->setText("连接");
                }
            });
        }
    }
    else
    {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}


void Dlg_Control::on_saveButton_clicked()
{
    QSqlQuery query(DB);

    // 开始事务
    query.exec("BEGIN TRANSACTION");

    // 清空表数据
    query.exec("DELETE FROM iport");

    // 遍历所有行
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QLineEdit* ipEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(i, 1));
        QLineEdit* portEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(i, 2));

        if (ipEdit && portEdit) {
            QString ip = ipEdit->text();
            QString port = portEdit->text();

            query.prepare("INSERT INTO iport (ip, port) VALUES (:ip, :port)");
            query.bindValue(":ip", ip);
            query.bindValue(":port", port);

            if (!query.exec()) {
                qDebug() << "Failed to insert data:" << query.lastError().text();
            }
        }
    }

    // 提交事务
    query.exec("COMMIT");
    QMessageBox::information(this,"成功","保存成功");
}

void Dlg_Control::on_checkButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QCheckBox* checkBox = qobject_cast<QCheckBox*>(ui->tableWidget->cellWidget(i, 0));
        if (checkBox) {
            checkBox->setChecked(true);
        }
    }
}

void Dlg_Control::on_connectButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    for (int i = 0; i < rowCount; ++i) {
        QPushButton* connectButton = qobject_cast<QPushButton*>(ui->tableWidget->cellWidget(i, 3));
        if (connectButton && connectButton->text() == "连接") {
            // 模拟点击连接按钮
            connectButton->click();
        }
    }
}

void Dlg_Control::on_copyButton_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount == 0) {
        return; // 如果没有行，直接返回
    }

    // 获取第一行的 sendEdit 文本
    QLineEdit* sendEdit0 = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(0, 6));

    QString senddata = sendEdit0->text();

    // 遍历所有行，将第一行的 sendEdit 文本复制到其他行的 sendEdit
    for (int i = 0; i < rowCount; ++i) {
        QLineEdit* sendEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(i, 6));
        if (sendEdit) {
            sendEdit->setText(senddata);
        }
    }
}
