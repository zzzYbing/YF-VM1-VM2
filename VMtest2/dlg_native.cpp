#include "dlg_native.h"
#include "ui_dlg_native.h"
#include "m_set.h"
#pragma execution_character_set("UTF-8")
#include <QMessageBox>
#include <QSettings>
Dlg_Native::Dlg_Native(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Native),
    s1(new solution(this))
{
    ui->setupUi(this);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(QDir::currentPath()+"\\book2.db");//打开数据库
    if (DB.open())
    {
        qDebug() << "Database opened successfully";
    }
    else
    {
        qDebug() << "无法打开数据库：" << DB.lastError().text();
    }
    QSqlQuery query("SELECT data FROM load WHERE id = 1");
    if (query.next()) {
        data = query.value(0).toInt();
        ui->checkBox->setChecked(data == 1);
        if(1==data)
        {
            // 查询 `sol` 表以获取路径
            QSqlQuery solQuery("SELECT path FROM sol LIMIT 1");
            if (solQuery.next()) {
                QString path = solQuery.value(0).toString();
                s1->pVmSol = LoadSolution(path.toStdString().c_str(), "");
            }
            else
            {
                QMessageBox::warning(this, "ERROR", "加载方案失败");
            }
        }
    }
    QSqlQuery query1("SELECT data FROM load WHERE id = 2");
    if (query1.next()) {
        data1 = query1.value(0).toInt();
        ui->cb_on_off->setChecked(data1 == 1);
    }
}

Dlg_Native::~Dlg_Native()
{
    if (DB.isOpen()) {
        DB.close();
    }
    delete ui;
}

void Dlg_Native::on_checkBox_stateChanged(int arg1)
{
    data = ui->checkBox->isChecked() ? 1 : 0;
}

void Dlg_Native::on_pushButton_clicked()
{
    m_set *dialog = new m_set(this, s1);
    dialog->exec();
}
void Dlg_Native::setPath(const QString &newPath)
{
    path = newPath;
    s1->pVmSol = LoadSolution(path.toStdString().c_str(), "");
}

void Dlg_Native::on_cb_on_off_stateChanged(int arg1)
{
    data1 = ui->cb_on_off->isChecked() ? 1:0;
}

