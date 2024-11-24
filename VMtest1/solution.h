#ifndef SOLUTION_H
#define SOLUTION_H

#include <QDialog>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
#include "setsol.h"
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
class solution;
}

class solution : public QDialog
{
    Q_OBJECT

public:
    explicit solution(QWidget *parent = nullptr);
    ~solution();

    IVmSolution * pVmSol;
    void inittable();
signals:
    void solutionPathSelected(const QString &path);  // 添加此信号
public slots:
    void loadDataFromDatabase();

    void copyFile(int row); 
private slots:

    void on_btn_add_clicked();

    void on_btn_save_clicked();

private:
    Ui::solution *ui;
    QSqlDatabase db;
    setsol s1;
    void addRowToTable(const QString &name, const QString &path);
};

#endif // SOLUTION_H
