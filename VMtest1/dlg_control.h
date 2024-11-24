#ifndef DLG_CONTROL_H
#define DLG_CONTROL_H

#include <QDialog>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>  // 添加消息框头文件
#include "setcl.h"
namespace Ui {
class Dlg_Control;
}

class Dlg_Control : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Control(QWidget *parent = nullptr);
    ~Dlg_Control();
    QString path;
    void initTable();
    void setPath(const QString &newPath);
    solution *s1;
public slots:
    void loadDataFromDatabase();
private slots:
    void on_addButton_clicked();

    void on_sendButton_clicked();

    void on_saveButton_clicked();

    void on_checkButton_clicked();

    void on_connectButton_clicked();

    void on_copyButton_clicked();

private:
    Ui::Dlg_Control *ui;
    QVector<QTcpSocket*> tcpClients;  // 存储所有TCP客户端
    QSqlDatabase DB;  // 定义数据库名称

    QString fileName;//文件名字
    qint64 fileSize;//文件大小
    qint64 sendSize;//已经发送文件的大小

};

#endif // DLG_CONTROL_H
