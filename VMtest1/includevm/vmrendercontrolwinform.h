/****************************************************************************
**
** Namespace VmRenderControlWinform generated by dumpcpp v5.9.9 using
** dumpcpp {c3987c98-720a-414d-86d0-0d46ce541623}

****************************************************************************/

#ifndef QAX_DUMPCPP_VMRENDERCONTROLWINFORM_H
#define QAX_DUMPCPP_VMRENDERCONTROLWINFORM_H

// Define this symbol to __declspec(dllexport) or __declspec(dllimport)
#ifndef VMRENDERCONTROLWINFORM_EXPORT
#define VMRENDERCONTROLWINFORM_EXPORT
#endif

#include <qaxobject.h>
#include <qaxwidget.h>
#include <qdatetime.h>
#include <qpixmap.h>
#include "ErrorCodeDefine.h"
#include "VmException.h"
#include "VmControlBaseInfo.h"

struct IDispatch;


// Referenced namespace
namespace System {
    class ISite;
}

namespace mscorlib {
    class _Type;
    class _EventHandler;
}

Q_DECLARE_OPAQUE_POINTER(System::ISite*)
Q_DECLARE_OPAQUE_POINTER(mscorlib::_Type*)
Q_DECLARE_OPAQUE_POINTER(mscorlib::_EventHandler*)

namespace VmRenderControlWinform {

// forward declarations
    struct ImageBaseData;
    struct RenderInput;
    struct PointInE;
    struct CircleInE;
    struct EllipseInE;
    struct AnnularSectorInE;
    struct LineInE;
    struct RectangleInE;
    struct TextInE;
    struct PointExOld;
    struct ImageBaseData;
    struct RenderInput;
    struct PointInE;
    struct CircleInE;
    struct EllipseInE;
    struct AnnularSectorInE;
    struct LineInE;
    struct RectangleInE;
    struct TextInE;
    struct PointExOld;

class VMRENDERCONTROLWINFORM_EXPORT VmRenderCtrlInterface : public QAxObject
{
public:
    VmRenderCtrlInterface(IDispatch *subobject = 0, QAxObject *parent = 0)
    : QAxObject((IUnknown*)subobject, parent)
    {
        internalRelease();
    }

    /**
     * @par 说明
     * 控制图层选择控件显示隐藏
	 * @param isImageComboBoxVisible [IN] 是否可视
     */
    inline void ChangeImageComboBoxVisibility(bool isImageComboBoxVisible);

    /**
     * @par 说明
     * 清空显示
     */
    inline void ClearDisplayView();

    /**
     * @brief 释放控件资源
	 * @remarks 控件销毁前调用一次
     */
    inline void Dispose();

    /**
     * @par 说明
     * 放大视图
     */
    inline void EnlargeView();

    /**
     * @par 说明
     * 初始化
	 * @return 内部信息
     */
    inline qlonglong GetObjectPointer();

    /**
     * @par 说明
     * 获取当前渲染图名称
     */
    inline QString GetSelectedImageDisplayName();

    /**
     * @par 说明
     * 隐藏坐标信息
     */
    inline void HideCoordinateInfo();

    /**
     * @par 说明
     * 还原视图
     */
    inline void InitView();

    /**
     * @par 说明
     * 保存原图
     */
    inline void SaveOriginalImage(const QString& fileName);

    /**
     * @par 说明
     * 保存原图
	 * @param fileName [in] 图片路径
	 * @param jpgQuality [in] 图片质量 范围[1,100]，数值越大质量越高，默认值95
     */
    inline void SaveOriginalImage(const QString& fileName, int jpgQuality);

    /**
     * @par 说明
     * 保存渲染图
     */
    inline void SaveRenderedImage(const QString& fileName);

    /**
     * @par 说明
     * 保存渲染图
	 * @param fileName [in] 图片路径
	 * @param jpgQuality [in] 图片质量 范围[1,100]，数值越大质量越高，默认值95
     */
    inline void SaveRenderedImage(const QString& fileName, int jpgQuality);

    /**
     * @par 说明
     * 设置扇环形数据
	 * @param pAnnularSector [in] 扇环信息
     */
    inline void SetAnnularSector(qlonglong pAnnularSector);

    /**
     * @par 说明
     * 设置扇环形数据
	 * @param pAnnularSector [in] 扇环信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetAnnularSector(qlonglong pAnnularSector, bool isAddShape);

    /**
     * @par 说明
     * 设置控件背景图
     * @param Value [in] 背景图(小于100*100)绝对路径或#十六进制颜色码
     */
    inline void SetBackground(const QString& value);

    /**
     * @par 说明
     * 设置圆形数据
	 * @param pCircle [in] 圆形数据
     */
    inline void SetCircle(qlonglong pCircle);

    /**
     * @par 说明
     * 设置圆形数据
	 * @param pCircle [in] 圆形数据
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetCircle(qlonglong pCircle, bool isAddShape);

    /**
     * @par 说明
     * 设置椭圆数据
	 * @param pCircle [in] 椭圆数据
     */
    inline void SetEllipse(qlonglong pEllipse);

    /**
     * @par 说明
     * 设置椭圆数据
	 * @param pCircle [in] 椭圆数据
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetEllipse(qlonglong pEllipse, bool isAddShape);

    /**
     * @par 说明
     * 设置图像数据
	 * @param pImgData 图像数据
     */
    inline void SetImageSourceData(qlonglong pImgData);

    /**
     * @par 说明
     * 设置直线数据
	 * @param pLine [in] 直线信息
     */
    inline void SetLine(qlonglong pLine);

    /**
     * @par 说明
     * 设置直线数据
	 * @param pLine [in] 直线信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetLine(qlonglong pLine, bool isAddShape);

    /**
     * @par 说明
     * 设置渲染配置信息
	 * @param pData [in] 渲染配置信息
     */
    inline void SetParamsInfo(qlonglong pData);

    /**
     * @par 说明
     * 设置点集数据
	 * @param pPointSet [in] 点集信息
     */
    inline void SetPointSet(qlonglong pPointSet);

    /**
     * @par 说明
     * 设置点集数据
	 * @param pPointSet [in] 点集信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetPointSet(qlonglong pPointSet, bool isAddShape);

    /**
     * @par 说明
     * 设置多边形数据
	 * @param pPolygon [in] 多边形
     */
    inline void SetPolygon(qlonglong pPolygon);

    /**
     * @par 说明
     * 设置多边形数据
	 * @param pPolygon [in] 多边形
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetPolygon(qlonglong pPolygon, bool isAddShape);

     /**
     * @par 说明
     * 设置折线数据
	 * @param pPolyline [in] 折线信息
     */
    inline void SetPolyline(qlonglong pPolyline);

     /**
     * @par 说明
     * 设置折线数据
	 * @param pPolyline [in] 折线信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetPolyline(qlonglong pPolyline, bool isAddShape);

    /**
     * @par 说明
     * 设置矩形数据
	 * @param pRectangle [in] 矩形信息
     */
    inline void SetRectangle(qlonglong pRectangle);

    /**
     * @par 说明
     * 设置矩形数据
	 * @param pRectangle [in] 矩形信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetRectangle(qlonglong pRectangle, bool isAddShape);

    /**
    * @par 说明
    * 设置渲染条件：当设置条件status和模块状态值一致时才刷新
    */
    inline void SetRenderCondition(RenderSatus status);

    /**
    * @par 说明
    * 设置渲染间隔(ms)，用于减低渲染频率。设置后，执行结束触发渲染时先校验距离上一次渲染的时间是否已超过设置的间隔时间，已超过则正常渲染，未超过则跳过此次渲染
	* @param pMillseconds [IN] 间隔时间(ms)
    */
    inline void SetRenderInterval(int pMillseconds);

     /**
     * @par 说明
     * 设置文本数据
	 * @param pText [in] 文本信息
     */
    inline void SetText(qlonglong pText);

     /**
     * @par 说明
     * 设置文本数据
	 * @param pText [in] 文本信息
	 * @param isAddShape [in] false 立即绘制  true 在下次刷新渲染时自动绘制
     */
    inline void SetText(qlonglong pText, bool isAddShape);

    /**
     * @par 说明
     * 显示坐标信息
     */
    inline void ShowCoordinateInfo();

    /**
     * @par 说明
     * 缩小视图
     */
    inline void ShrinkView();

// meta object functions
    static const QMetaObject staticMetaObject;
    virtual const QMetaObject *metaObject() const { return &staticMetaObject; }
    virtual void *qt_metacast(const char *);
};

// Actual coclasses
class VMRENDERCONTROLWINFORM_EXPORT VmRenderControlWinform : public QAxWidget
{
public:
    VmRenderControlWinform(QWidget *parent = 0, Qt::WindowFlags f = 0)
    : QAxWidget(parent, f)
    {
        setControl(QStringLiteral("{313241a6-62f9-464b-bede-f514827e2f4b}"));
    }

    VmRenderControlWinform(VmRenderCtrlInterface *iface)
    : QAxWidget()
    {
        initializeFrom(iface);
        delete iface;
    }

    /*
    Property Handle
    */
    inline int Handle() const; //Returns the value of Handle

    /*
    Property Site
    */
    inline System::ISite* Site() const; //Returns the value of Site
    inline void SetSite(System::ISite* value); //Sets the value of the Site property

    /*
    Property ToString
    */
    inline QString ToString() const; //Returns the value of ToString

    /*
    Method ChangeImageComboBoxVisibility
    */
    inline void ChangeImageComboBoxVisibility(bool isImageComboBoxVisible);

    /*
    Method ClearDisplayView
    */
    inline void ClearDisplayView();

    /*
    Method Dispose
    */
    inline void Dispose();

    /*
    Method EnlargeView
    */
    inline void EnlargeView();

    /*
    Method Equals
    */
    inline bool Equals(const QVariant& obj);

    /*
    Method GetHashCode
    */
    inline int GetHashCode();

    /*
    Method GetObjectPointer
    */
    inline qlonglong GetObjectPointer();

    /*
    Method GetSelectedImageDisplayName
    */
    inline QString GetSelectedImageDisplayName();

    /*
    Method GetType
    */
    inline mscorlib::_Type* GetType();

    /*
    Method HideCoordinateInfo
    */
    inline void HideCoordinateInfo();

    /*
    Method InitView
    */
    inline void InitView();

    /*
    Method SaveOriginalImage
    */
    inline void SaveOriginalImage(const QString& fileName);

    /*
    Method SaveOriginalImage
    */
    inline void SaveOriginalImage(const QString& fileName, int jpgQuality);

    /*
    Method SaveRenderedImage
    */
    inline void SaveRenderedImage(const QString& fileName);

    /*
    Method SaveRenderedImage
    */
    inline void SaveRenderedImage(const QString& fileName, int jpgQuality);

    /*
    Method SetAnnularSector
    */
    inline void SetAnnularSector(qlonglong pAnnularSector);

    /*
    Method SetAnnularSector
    */
    inline void SetAnnularSector(qlonglong pAnnularSector, bool isAddShape);

    /*
    Method SetBackground
    */
    inline void SetBackground(const QString& value);

    /*
    Method SetCircle
    */
    inline void SetCircle(qlonglong pCircle);

    /*
    Method SetCircle
    */
    inline void SetCircle(qlonglong pCircle, bool isAddShape);

    /*
    Method SetEllipse
    */
    inline void SetEllipse(qlonglong pEllipse);

    /*
    Method SetEllipse
    */
    inline void SetEllipse(qlonglong pEllipse, bool isAddShape);

    /*
    Method SetImageSourceData
    */
    inline void SetImageSourceData(qlonglong pImgData);

    /*
    Method SetLine
    */
    inline void SetLine(qlonglong pLine);

    /*
    Method SetLine
    */
    inline void SetLine(qlonglong pLine, bool isAddShape);

    /*
    Method SetParamsInfo
    */
    inline void SetParamsInfo(qlonglong pData);

    /*
    Method SetPointSet
    */
    inline void SetPointSet(qlonglong pPointSet);

    /*
    Method SetPointSet
    */
    inline void SetPointSet(qlonglong pPointSet, bool isAddShape);

    /*
    Method SetPolygon
    */
    inline void SetPolygon(qlonglong pPolygon);

    /*
    Method SetPolygon
    */
    inline void SetPolygon(qlonglong pPolygon, bool isAddShape);

    /*
    Method SetPolyline
    */
    inline void SetPolyline(qlonglong pPolyline);

    /*
    Method SetPolyline
    */
    inline void SetPolyline(qlonglong pPolyline, bool isAddShape);

    /*
    Method SetRectangle
    */
    inline void SetRectangle(qlonglong pRectangle);

    /*
    Method SetRectangle
    */
    inline void SetRectangle(qlonglong pRectangle, bool isAddShape);

    /*
    Method SetRenderCondition
    */
    inline void SetRenderCondition(RenderSatus status);

    /*
    Method SetRenderInterval
    */
    inline void SetRenderInterval(int pMillseconds);

    /*
    Method SetText
    */
    inline void SetText(qlonglong pText);

    /*
    Method SetText
    */
    inline void SetText(qlonglong pText, bool isAddShape);

    /*
    Method ShowCoordinateInfo
    */
    inline void ShowCoordinateInfo();

    /*
    Method ShrinkView
    */
    inline void ShrinkView();

    /*
    Method add_Disposed
    */
    inline void add_Disposed(mscorlib::_EventHandler* value);

    /*
    Method remove_Disposed
    */
    inline void remove_Disposed(mscorlib::_EventHandler* value);

// meta object functions
    static const QMetaObject staticMetaObject;
    virtual const QMetaObject *metaObject() const { return &staticMetaObject; }
    virtual void *qt_metacast(const char *);
};

// member function implementation
#ifndef QAX_DUMPCPP_VMRENDERCONTROLWINFORM_NOINLINES
inline int VmRenderControlWinform::Handle() const
{
    QVariant qax_result = property("Handle");
    Q_ASSERT(qax_result.isValid());
    return *(int*)qax_result.constData();
}

inline System::ISite* VmRenderControlWinform::Site() const
{
#ifdef QAX_DUMPCPP_SYSTEM_H
    System::ISite* qax_pointer = 0;
    qRegisterMetaType<System::ISite*>("System::ISite*", &qax_pointer);
    qRegisterMetaType<System::ISite>("System::ISite", qax_pointer);
    QVariant qax_result = property("Site");
    if (!qax_result.constData()) return 0;
    Q_ASSERT(qax_result.isValid());
    return *(System::ISite**)qax_result.constData();
#else
    return 0; // foreign namespace not included
#endif
}
inline void VmRenderControlWinform::SetSite(System::ISite* value){
    int typeId = qRegisterMetaType<System::ISite*>("System::ISite*", &value);
    setProperty("Site", QVariant(typeId, &value));
}

inline QString VmRenderControlWinform::ToString() const
{
    QVariant qax_result = property("ToString");
    Q_ASSERT(qax_result.isValid());
    return *(QString*)qax_result.constData();
}

inline void VmRenderControlWinform::ChangeImageComboBoxVisibility(bool isImageComboBoxVisible)
{
    void *_a[] = {0, (void*)&isImageComboBoxVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 35, _a);
}

inline void VmRenderControlWinform::ClearDisplayView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 36, _a);
}

inline void VmRenderControlWinform::Dispose()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 37, _a);
}

inline void VmRenderControlWinform::EnlargeView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 38, _a);
}

inline bool VmRenderControlWinform::Equals(const QVariant& obj)
{
    bool qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&obj};
    qt_metacall(QMetaObject::InvokeMetaMethod, 39, _a);
    return qax_result;
}

inline int VmRenderControlWinform::GetHashCode()
{
    int qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 40, _a);
    return qax_result;
}

inline qlonglong VmRenderControlWinform::GetObjectPointer()
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 41, _a);
    return qax_result;
}

inline QString VmRenderControlWinform::GetSelectedImageDisplayName()
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 42, _a);
    return qax_result;
}

inline mscorlib::_Type* VmRenderControlWinform::GetType()
{
    mscorlib::_Type* qax_result = 0;
#ifdef QAX_DUMPCPP_MSCORLIB_H
    qRegisterMetaType<mscorlib::_Type*>("mscorlib::_Type*", &qax_result);
    qRegisterMetaType<mscorlib::_Type>("mscorlib::_Type", qax_result);
#endif
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 43, _a);
    return qax_result;
}

inline void VmRenderControlWinform::HideCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 45, _a);
}

inline void VmRenderControlWinform::InitView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 46, _a);
}

inline void VmRenderControlWinform::SaveOriginalImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 47, _a);
}

inline void VmRenderControlWinform::SaveOriginalImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 48, _a);
}

inline void VmRenderControlWinform::SaveRenderedImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 49, _a);
}

inline void VmRenderControlWinform::SaveRenderedImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 50, _a);
}

inline void VmRenderControlWinform::SetAnnularSector(qlonglong pAnnularSector)
{
    void *_a[] = {0, (void*)&pAnnularSector};
    qt_metacall(QMetaObject::InvokeMetaMethod, 51, _a);
}

inline void VmRenderControlWinform::SetAnnularSector(qlonglong pAnnularSector, bool isAddShape)
{
    void *_a[] = {0, (void*)&pAnnularSector, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 52, _a);
}

inline void VmRenderControlWinform::SetBackground(const QString& value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 53, _a);
}

inline void VmRenderControlWinform::SetCircle(qlonglong pCircle)
{
    void *_a[] = {0, (void*)&pCircle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 54, _a);
}

inline void VmRenderControlWinform::SetCircle(qlonglong pCircle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pCircle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 55, _a);
}

inline void VmRenderControlWinform::SetEllipse(qlonglong pEllipse)
{
    void *_a[] = {0, (void*)&pEllipse};
    qt_metacall(QMetaObject::InvokeMetaMethod, 56, _a);
}

inline void VmRenderControlWinform::SetEllipse(qlonglong pEllipse, bool isAddShape)
{
    void *_a[] = {0, (void*)&pEllipse, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 57, _a);
}

inline void VmRenderControlWinform::SetImageSourceData(qlonglong pImgData)
{
    void *_a[] = {0, (void*)&pImgData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 58, _a);
}

inline void VmRenderControlWinform::SetLine(qlonglong pLine)
{
    void *_a[] = {0, (void*)&pLine};
    qt_metacall(QMetaObject::InvokeMetaMethod, 59, _a);
}

inline void VmRenderControlWinform::SetLine(qlonglong pLine, bool isAddShape)
{
    void *_a[] = {0, (void*)&pLine, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 60, _a);
}

inline void VmRenderControlWinform::SetParamsInfo(qlonglong pData)
{
    void *_a[] = {0, (void*)&pData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 61, _a);
}

inline void VmRenderControlWinform::SetPointSet(qlonglong pPointSet)
{
    void *_a[] = {0, (void*)&pPointSet};
    qt_metacall(QMetaObject::InvokeMetaMethod, 62, _a);
}

inline void VmRenderControlWinform::SetPointSet(qlonglong pPointSet, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPointSet, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 63, _a);
}

inline void VmRenderControlWinform::SetPolygon(qlonglong pPolygon)
{
    void *_a[] = {0, (void*)&pPolygon};
    qt_metacall(QMetaObject::InvokeMetaMethod, 64, _a);
}

inline void VmRenderControlWinform::SetPolygon(qlonglong pPolygon, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolygon, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 65, _a);
}

inline void VmRenderControlWinform::SetPolyline(qlonglong pPolyline)
{
    void *_a[] = {0, (void*)&pPolyline};
    qt_metacall(QMetaObject::InvokeMetaMethod, 66, _a);
}

inline void VmRenderControlWinform::SetPolyline(qlonglong pPolyline, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolyline, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 67, _a);
}

inline void VmRenderControlWinform::SetRectangle(qlonglong pRectangle)
{
    void *_a[] = {0, (void*)&pRectangle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 68, _a);
}

inline void VmRenderControlWinform::SetRectangle(qlonglong pRectangle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pRectangle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 69, _a);
}

inline void VmRenderControlWinform::SetRenderCondition(RenderSatus status)
{
    void *_a[] = {0, (void*)&status};
    qt_metacall(QMetaObject::InvokeMetaMethod, 70, _a);
}

inline void VmRenderControlWinform::SetRenderInterval(int pMillseconds)
{
    void *_a[] = {0, (void*)&pMillseconds};
    qt_metacall(QMetaObject::InvokeMetaMethod, 71, _a);
}

inline void VmRenderControlWinform::SetText(qlonglong pText)
{
    void *_a[] = {0, (void*)&pText};
    qt_metacall(QMetaObject::InvokeMetaMethod, 73, _a);
}

inline void VmRenderControlWinform::SetText(qlonglong pText, bool isAddShape)
{
    void *_a[] = {0, (void*)&pText, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 74, _a);
}

inline void VmRenderControlWinform::ShowCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 75, _a);
}

inline void VmRenderControlWinform::ShrinkView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 76, _a);
}

inline void VmRenderControlWinform::add_Disposed(mscorlib::_EventHandler* value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 77, _a);
}

inline void VmRenderControlWinform::remove_Disposed(mscorlib::_EventHandler* value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 78, _a);
}


inline void VmRenderCtrlInterface::ChangeImageComboBoxVisibility(bool isImageComboBoxVisible)
{
    void *_a[] = {0, (void*)&isImageComboBoxVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 8, _a);
}

inline void VmRenderCtrlInterface::ClearDisplayView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 9, _a);
}

inline void VmRenderCtrlInterface::Dispose()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 10, _a);
}

inline void VmRenderCtrlInterface::EnlargeView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 11, _a);
}

inline qlonglong VmRenderCtrlInterface::GetObjectPointer()
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 12, _a);
    return qax_result;
}

inline QString VmRenderCtrlInterface::GetSelectedImageDisplayName()
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 13, _a);
    return qax_result;
}

inline void VmRenderCtrlInterface::HideCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 14, _a);
}

inline void VmRenderCtrlInterface::InitView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 15, _a);
}

inline void VmRenderCtrlInterface::SaveOriginalImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 16, _a);
}

inline void VmRenderCtrlInterface::SaveOriginalImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 17, _a);
}

inline void VmRenderCtrlInterface::SaveRenderedImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 18, _a);
}

inline void VmRenderCtrlInterface::SaveRenderedImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 19, _a);
}

inline void VmRenderCtrlInterface::SetAnnularSector(qlonglong pAnnularSector)
{
    void *_a[] = {0, (void*)&pAnnularSector};
    qt_metacall(QMetaObject::InvokeMetaMethod, 20, _a);
}

inline void VmRenderCtrlInterface::SetAnnularSector(qlonglong pAnnularSector, bool isAddShape)
{
    void *_a[] = {0, (void*)&pAnnularSector, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 21, _a);
}

inline void VmRenderCtrlInterface::SetBackground(const QString& value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 22, _a);
}

inline void VmRenderCtrlInterface::SetCircle(qlonglong pCircle)
{
    void *_a[] = {0, (void*)&pCircle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 23, _a);
}

inline void VmRenderCtrlInterface::SetCircle(qlonglong pCircle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pCircle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 24, _a);
}

inline void VmRenderCtrlInterface::SetEllipse(qlonglong pEllipse)
{
    void *_a[] = {0, (void*)&pEllipse};
    qt_metacall(QMetaObject::InvokeMetaMethod, 25, _a);
}

inline void VmRenderCtrlInterface::SetEllipse(qlonglong pEllipse, bool isAddShape)
{
    void *_a[] = {0, (void*)&pEllipse, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 26, _a);
}

inline void VmRenderCtrlInterface::SetImageSourceData(qlonglong pImgData)
{
    void *_a[] = {0, (void*)&pImgData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 27, _a);
}

inline void VmRenderCtrlInterface::SetLine(qlonglong pLine)
{
    void *_a[] = {0, (void*)&pLine};
    qt_metacall(QMetaObject::InvokeMetaMethod, 28, _a);
}

inline void VmRenderCtrlInterface::SetLine(qlonglong pLine, bool isAddShape)
{
    void *_a[] = {0, (void*)&pLine, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 29, _a);
}

inline void VmRenderCtrlInterface::SetParamsInfo(qlonglong pData)
{
    void *_a[] = {0, (void*)&pData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 30, _a);
}

inline void VmRenderCtrlInterface::SetPointSet(qlonglong pPointSet)
{
    void *_a[] = {0, (void*)&pPointSet};
    qt_metacall(QMetaObject::InvokeMetaMethod, 31, _a);
}

inline void VmRenderCtrlInterface::SetPointSet(qlonglong pPointSet, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPointSet, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 32, _a);
}

inline void VmRenderCtrlInterface::SetPolygon(qlonglong pPolygon)
{
    void *_a[] = {0, (void*)&pPolygon};
    qt_metacall(QMetaObject::InvokeMetaMethod, 33, _a);
}

inline void VmRenderCtrlInterface::SetPolygon(qlonglong pPolygon, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolygon, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 34, _a);
}

inline void VmRenderCtrlInterface::SetPolyline(qlonglong pPolyline)
{
    void *_a[] = {0, (void*)&pPolyline};
    qt_metacall(QMetaObject::InvokeMetaMethod, 35, _a);
}

inline void VmRenderCtrlInterface::SetPolyline(qlonglong pPolyline, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolyline, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 36, _a);
}

inline void VmRenderCtrlInterface::SetRectangle(qlonglong pRectangle)
{
    void *_a[] = {0, (void*)&pRectangle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 37, _a);
}

inline void VmRenderCtrlInterface::SetRectangle(qlonglong pRectangle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pRectangle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 38, _a);
}

inline void VmRenderCtrlInterface::SetRenderCondition(RenderSatus status)
{
    void *_a[] = {0, (void*)&status};
    qt_metacall(QMetaObject::InvokeMetaMethod, 39, _a);
}

inline void VmRenderCtrlInterface::SetRenderInterval(int pMillseconds)
{
    void *_a[] = {0, (void*)&pMillseconds};
    qt_metacall(QMetaObject::InvokeMetaMethod, 40, _a);
}

inline void VmRenderCtrlInterface::SetText(qlonglong pText)
{
    void *_a[] = {0, (void*)&pText};
    qt_metacall(QMetaObject::InvokeMetaMethod, 41, _a);
}

inline void VmRenderCtrlInterface::SetText(qlonglong pText, bool isAddShape)
{
    void *_a[] = {0, (void*)&pText, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 42, _a);
}

inline void VmRenderCtrlInterface::ShowCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 43, _a);
}

inline void VmRenderCtrlInterface::ShrinkView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 44, _a);
}



#endif

}

QT_BEGIN_NAMESPACE

namespace QtMetaTypePrivate {
template<>
struct QMetaTypeFunctionHelper<VmRenderControlWinform::VmRenderControlWinform, /* Accepted */ true> {
    static void Destruct(void *t)
    {
        Q_UNUSED(t)
        static_cast<VmRenderControlWinform::VmRenderControlWinform*>(t)->VmRenderControlWinform::~VmRenderControlWinform();
    }
    static void *Construct(void *where, const void *t)
    {
        Q_ASSERT(!t);
        Q_UNUSED(t)
        return new (where) VmRenderControlWinform::VmRenderControlWinform;
    }
#ifndef QT_NO_DATASTREAM
    static void Save(QDataStream &stream, const void *t) { stream << *static_cast<const VmRenderControlWinform::VmRenderControlWinform*>(t); }
    static void Load(QDataStream &stream, void *t) { stream >> *static_cast<VmRenderControlWinform::VmRenderControlWinform*>(t); }
#endif // QT_NO_DATASTREAM
};

template<>
struct QMetaTypeFunctionHelper<VmRenderControlWinform::VmRenderCtrlInterface, /* Accepted */ true> {
    static void Destruct(void *t)
    {
        Q_UNUSED(t)
        static_cast<VmRenderControlWinform::VmRenderCtrlInterface*>(t)->VmRenderControlWinform::VmRenderCtrlInterface::~VmRenderCtrlInterface();
    }
    static void *Construct(void *where, const void *t)
    {
        Q_ASSERT(!t);
        Q_UNUSED(t)
        return new (where) VmRenderControlWinform::VmRenderCtrlInterface;
    }
#ifndef QT_NO_DATASTREAM
    static void Save(QDataStream &stream, const void *t) { stream << *static_cast<const VmRenderControlWinform::VmRenderCtrlInterface*>(t); }
    static void Load(QDataStream &stream, void *t) { stream >> *static_cast<VmRenderControlWinform::VmRenderCtrlInterface*>(t); }
#endif // QT_NO_DATASTREAM
};

} // namespace QtMetaTypePrivate
QT_END_NAMESPACE

#endif

