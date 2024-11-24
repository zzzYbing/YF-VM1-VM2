#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "solution.h"
#include <QCheckBox>
#include <QPushButton>
#include <QSettings>
#include <QtDebug>
#include <QMessageBox>
#pragma execution_character_set("UTF-8")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_nativePage(nullptr)
    ,m_visionPage(nullptr)
    ,m_controlPage(nullptr)
    ,m_displayPage(nullptr)
{
    ui->setupUi(this);
    initPage();


    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName(QDir::currentPath()+"\\book.db");//打开数据库
    if (DB.open())
    {
        qDebug() << "Database opened successfully";
    }
    else
    {
        qDebug() << "无法打开数据库：" << DB.lastError().text();
    }
    ui->axWidget->dynamicCall("GetObjectPointer()");
    // 连接按钮的点击信号到槽函数
    connect(ui->btn_display, &QToolButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(m_displayPage);
    });

    connect(ui->btn_control, &QToolButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(m_controlPage);
    });

    connect(ui->btn_native, &QToolButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(m_nativePage);
    });

    connect(ui->btn_vision, &QToolButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentWidget(m_visionPage);
    });
    m_controlPage->s1 = m_nativePage->s1;
}

MainWindow::~MainWindow()
{
    if (DB.isOpen()) {
        DB.close();
    }
    delete m_nativePage;
    delete m_visionPage;
    delete m_controlPage;
    delete m_displayPage;
    delete ui;
}

void MainWindow::initPage()
{
    m_nativePage = new Dlg_Native(this);
    m_visionPage = new Dlg_Vision(this);
    m_controlPage = new Dlg_Control(this);
    m_displayPage = new Dlg_Display(this);

    ui->stackedWidget->addWidget(m_displayPage);
    ui->stackedWidget->addWidget(m_controlPage);
    ui->stackedWidget->addWidget(m_nativePage);
    ui->stackedWidget->addWidget(m_visionPage);

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_solution_clicked()
{
    solution  s1(this); // 传递当前窗口作为父窗口
    connect(&s1, &solution::solutionPathSelected, this, [this](const QString &path) {
        if (m_nativePage) {
            m_nativePage->setPath(path);
            m_controlPage->s1 = m_nativePage->s1;
        }
    });

    s1.exec();
}

void MainWindow::on_btn_save_clicked()
{
    if (m_nativePage) {
        int newData = m_nativePage->data ? 1 : 0;
        QSqlQuery query;
        query.prepare("UPDATE load SET data = :data WHERE id = 1");
        query.bindValue(":data", newData);
        if (query.exec()) {
            qDebug() << "Data updated successfully";
        } else {
            qDebug() << "Failed to update data:" << query.lastError().text();
        }
        int newData1 = m_nativePage->data1 ? 1 : 0;
        QSqlQuery query1;
        query1.prepare("UPDATE load SET data = :data WHERE id = 2");
        query1.bindValue(":data", newData1);
        if (query1.exec()) {
            qDebug() << "Data updated successfully";
        } else {
            qDebug() << "Failed to update data:" << query1.lastError().text();
        }
        QSettings settings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        QString appPath = QCoreApplication::applicationDirPath();
        // 替换路径中的正斜杠为反斜杠
        appPath.replace("/", "\\");
        if (newData1) {
//            cmd /c "cd /d D:\projects\Qt-project\VM1 && VMtest1.exe"
            QString command = QString("cmd /c \"cd /d %1 && VMtest1.exe\"").arg(appPath);
                settings.setValue("VMtest1", command);//D:\projects\Qt-project\VM1\VMtest1.exe

        } else {
            settings.remove("VMtest1");
        }
        QMessageBox::information(this,"成功","保存成功");
    } else {
        qDebug() << "m_nativePage is not initialized.";
        QMessageBox::information(this, "失败", "保存失败: m_nativePage 未初始化");
    }
}
