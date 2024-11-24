#ifndef SETCL_H
#define SETCL_H

#include <QDialog>
#include "solution.h"
#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "VMException.h"

#include "IVmCommManager.h"
#include "IVmGlobalVariable.h"
#include "IVmGlobalCamera.h"
#include "IVmLightControl.h"
#include "IVmDataQueue.h"
#include "IVmImageSource.h"


using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;
using namespace VisionMasterSDK::ImageSourceModule;

using namespace VisionMasterSDK::GlobalVariableModule;
using namespace VisionMasterSDK::GlobalCameraModule;
using namespace VisionMasterSDK::CommManagerModule;
using namespace VisionMasterSDK::LightControlModule;
using namespace VisionMasterSDK::DataQueueModule;

namespace Ui {
class setcl;
}

class setcl : public QDialog
{
    Q_OBJECT
signals:
    void dataUpdated(const QString &data);
public:
    explicit setcl(const QString &initialLink,QWidget *parent = nullptr,solution *s1 = nullptr);
    ~setcl();
    QString link;
    QString path;
    QStringList names;
    QStringList paths;
    const char *strParam[5] = {"STAngle", "STPX", "STPY", "STX", "STY"};
    char strVal[5][8192] = {{0}};
    void inittableWidget();
    void initc_var();
    void initsol();
private slots:
    void on_btn_load_clicked();

private:
    Ui::setcl *ui;
    solution *s1;
    QSqlDatabase db;
};

#endif // SETCL_H
