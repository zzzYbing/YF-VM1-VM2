#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "dlg_display.h"
#include "dlg_control.h"
#include "dlg_native.h"
#include "dlg_vision.h"
#include "solution.h"
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "VMException.h"
using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initPage();
    QString queryString;
private slots:
    void on_btn_solution_clicked();

    void on_btn_save_clicked();
signals:
    void solutionPath(const QString &path);  // 添加此信号
private:
    Ui::MainWindow *ui;
    QSqlDatabase DB;//定义数据库名称
    solution s1;

    Dlg_Native *m_nativePage;
    Dlg_Vision *m_visionPage;
    Dlg_Control *m_controlPage;
    Dlg_Display *m_displayPage;

};
#endif // MAINWINDOW_H
