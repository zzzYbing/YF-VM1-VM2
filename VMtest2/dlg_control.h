#ifndef DLG_CONTROL_H
#define DLG_CONTROL_H

#include "solution.h"

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "IVmSolution.h"
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
class Dlg_Control;
}

class Dlg_Control : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Control(QWidget *parent = nullptr);
    ~Dlg_Control();
    solution *s1;
    QString le_data = "";
    void getiport();
    QString ip;
    QString port;
    void initpage();
private slots:
    void on_btn_listen_clicked();

    void onReadyRead();
private:
    Ui::Dlg_Control *ui;
    QTcpServer *tcpServer;         // TCP服务器对象
    QTcpSocket *clientSocket;      // 客户端连接对象
    bool isListening;              // 是否正在监听
    QSqlDatabase DB;//定义数据库名称
};

#endif // DLG_CONTROL_H
