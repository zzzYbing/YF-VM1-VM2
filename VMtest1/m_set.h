#ifndef M_SET_H
#define M_SET_H

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
#include "IVmHPFeatureMatch.h"
#include "IVmImageSource.h"

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;

using namespace VisionMasterSDK::GlobalVariableModule;
using namespace VisionMasterSDK::GlobalCameraModule;
using namespace VisionMasterSDK::CommManagerModule;
using namespace VisionMasterSDK::LightControlModule;
using namespace VisionMasterSDK::DataQueueModule;
using namespace VisionMasterSDK::IMVSHPFeatureMatchModu;
using namespace VisionMasterSDK::ImageSourceModule;


namespace Ui {
class m_set;
}

class m_set : public QDialog
{
    Q_OBJECT

public:
    explicit m_set(QWidget *parent = nullptr, solution *sol = nullptr);
    ~m_set();

private slots:
    void on_btn_load_clicked();
    void initTableW();
    void on_btn_sub_clicked();

private:
    Ui::m_set *ui;
    solution *s1;
};

#endif // M_SET_H
