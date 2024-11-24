#ifndef DLG_NATIVE_H
#define DLG_NATIVE_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "m_set.h"  // Include m_set header
#include "solution.h"
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "VMException.h"
#include "setcl.h"
using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;

namespace Ui {
class Dlg_Native;
}

class Dlg_Native : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Native(QWidget *parent = nullptr);
    ~Dlg_Native();

    QString queryString;
    QString path;
    int data;
    int data1;
    solution *s1;
    void setPath(const QString &newPath);
private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

    void on_cb_on_off_stateChanged(int arg1);

private:
    Ui::Dlg_Native *ui;
    QSqlDatabase DB;//定义数据库名称

};
#endif // DLG_NATIVE_H
