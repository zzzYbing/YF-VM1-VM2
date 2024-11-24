#ifndef DLG_VISION_H
#define DLG_VISION_H

#include <QDialog>
#include <QDebug>

#include "IVmSolution.h"
#include "IVmProcedure.h"
#include "VMException.h"

using namespace VisionMasterSDK;
using namespace VisionMasterSDK::VmSolution;
using namespace VisionMasterSDK::VmProcedure;

namespace Ui {
class Dlg_Vision;
}

class Dlg_Vision : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Vision(QWidget *parent = nullptr);
    ~Dlg_Vision();

private:
    Ui::Dlg_Vision *ui;
};

#endif // DLG_VISION_H
