/****************************************************************************
**
** Namespace VmParamsRenderControlWinform generated by dumpcpp v5.9.9 using
** dumpcpp {d45f15af-107e-48f6-9aa9-973c047e11a1}

****************************************************************************/

#ifndef QAX_DUMPCPP_VMPARAMSRENDERCONTROLWINFORM_H
#define QAX_DUMPCPP_VMPARAMSRENDERCONTROLWINFORM_H

// Define this symbol to __declspec(dllexport) or __declspec(dllimport)
#ifndef VMPARAMSRENDERCONTROLWINFORM_EXPORT
#define VMPARAMSRENDERCONTROLWINFORM_EXPORT
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

namespace VmParamsRenderControlWinform {
	
// forward declarations
    struct CircleInE;
    struct EllipseInE;
    struct AnnularSectorInE;
    struct LineInE;
    struct RectangleInE;
    struct TextInE;
    struct ParamBaseIn;
    struct ImageBaseData;
    struct LoadGroInfo;
    struct LoadSolInfo;
    struct CircleInE;
    struct EllipseInE;
    struct AnnularSectorInE;
    struct LineInE;
    struct RectangleInE;
    struct TextInE;
    struct ParamBaseIn;
    struct ImageBaseData;
    struct LoadGroInfo;
    struct LoadSolInfo;

class VMPARAMSRENDERCONTROLWINFORM_EXPORT VmParamsRenderInterface : public QAxObject
{
public:
    VmParamsRenderInterface(IDispatch *subobject = 0, QAxObject *parent = 0)
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
     * @par 说明
     * 清空显示
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline void ClearDisplayView(int index);

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
     * 放大视图
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline void EnlargeView(int index);

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
     * 获取当前渲染图名称
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline QString GetSelectedImageDisplayName(int index);

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
     * 还原视图
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline void InitView(int index);

    /**
     * @par 说明
     * 导入独立Group
	 * @param pSol [in] Group信息结构体地址 结构体详见VmControlBaseInfo.h的GroupInputInfo
	 * @deprecated 弃用,推荐(SetParamsInfo(void * pParamData, const char * const strXmlPath)),绑定已导入的独立Group
     */
    inline qlonglong LoadIndependentGroup(qlonglong pSol);

    /**
     * @par 说明
     * 导入方案
	 * @param pSol [in] 方案信息结构体地址 结构体详见VmControlBaseInfo.h的SolutionInputInfo
     */
    inline qlonglong LoadSol(qlonglong pSol);

    /**
     * @par 说明
     * 保存原图
	 * @param fileName [in] 图像路径
     */
    inline void SaveOriginalImage(const QString& fileName);

    /**
     * @par 说明
     * 保存原图
	 * @param fileName [in] 图像路径
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline void SaveOriginalImage(const QString& fileName, int index);

    /**
     * @par 说明
     * 保存原图
	 * @param fileName [in] 图片路径
	 * @param jpgQuality [in] 图片质量 范围[1,100]，数值越大质量越高，默认值95
	 * @param index [in] 获取当前选中图像名称，双画面显示时可指定获取某个画面，默认为右侧输出画面，index从左到右为0，1
     */
    inline void SaveOriginalImage(const QString& fileName, int index, int jpgQuality);

    /**
     * @par 说明
     * 保存渲染图
	 * @param fileName [in] 图片路径
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
	* 多画面切换按钮是否可见
	* @param isShowable [in] 是否按钮显示
	*/
    inline void SetMultiImageButtonVisible(bool isVisible);

    /**
	* @par 说明
	* 流程、Group参数页中的添加、删除、编辑按钮是否可见
	* @param isEditable [in] 是否可见   true 按钮可见
	*/
    inline void SetParamTabEditable(bool isEditable);

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

    /**
     * @par 说明
     * 缩小视图
     */
    inline void ShrinkView(int index);

// meta object functions
    static const QMetaObject staticMetaObject;
    virtual const QMetaObject *metaObject() const { return &staticMetaObject; }
    virtual void *qt_metacast(const char *);
};

// Actual coclasses
class VMPARAMSRENDERCONTROLWINFORM_EXPORT VmParamsRenderControlWinform : public QAxWidget
{
public:
    VmParamsRenderControlWinform(QWidget *parent = 0, Qt::WindowFlags f = 0)
    : QAxWidget(parent, f)
    {
        setControl(QStringLiteral("{c6961180-1f47-41a2-82a6-d9811887f4f6}"));
    }

    VmParamsRenderControlWinform(VmParamsRenderInterface *iface)
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
    Method ClearDisplayView
    */
    inline void ClearDisplayView(int index);

    /*
    Method Dispose
    */
    inline void Dispose();

    /*
    Method EnlargeView
    */
    inline void EnlargeView();

    /*
    Method EnlargeView
    */
    inline void EnlargeView(int index);

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
    Method GetSelectedImageDisplayName
    */
    inline QString GetSelectedImageDisplayName(int index);

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
    Method InitView
    */
    inline void InitView(int index);

    /*
    Method LoadIndependentGroup
    */
    inline qlonglong LoadIndependentGroup(qlonglong pSol);

    /*
    Method LoadSol
    */
    inline qlonglong LoadSol(qlonglong pSol);

    /*
    Method SaveOriginalImage
    */
    inline void SaveOriginalImage(const QString& fileName);

    /*
    Method SaveOriginalImage
    */
    inline void SaveOriginalImage(const QString& fileName, int index);

    /*
    Method SaveOriginalImage
    */
    inline void SaveOriginalImage(const QString& fileName, int index, int jpgQuality);

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
    Method SetMultiImageButtonVisible
    */
    inline void SetMultiImageButtonVisible(bool isVisible);

    /*
    Method SetParamTabEditable
    */
    inline void SetParamTabEditable(bool isEditable);

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
    Method ShrinkView
    */
    inline void ShrinkView(int index);

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
#ifndef QAX_DUMPCPP_VMPARAMSRENDERCONTROLWINFORM_NOINLINES
inline int VmParamsRenderControlWinform::Handle() const
{
    QVariant qax_result = property("Handle");
    Q_ASSERT(qax_result.isValid());
    return *(int*)qax_result.constData();
}

inline System::ISite* VmParamsRenderControlWinform::Site() const
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
inline void VmParamsRenderControlWinform::SetSite(System::ISite* value){
    int typeId = qRegisterMetaType<System::ISite*>("System::ISite*", &value);
    setProperty("Site", QVariant(typeId, &value));
}

inline QString VmParamsRenderControlWinform::ToString() const
{
    QVariant qax_result = property("ToString");
    Q_ASSERT(qax_result.isValid());
    return *(QString*)qax_result.constData();
}

inline void VmParamsRenderControlWinform::ChangeImageComboBoxVisibility(bool isImageComboBoxVisible)
{
    void *_a[] = {0, (void*)&isImageComboBoxVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 35, _a);
}

inline void VmParamsRenderControlWinform::ClearDisplayView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 36, _a);
}

inline void VmParamsRenderControlWinform::ClearDisplayView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 37, _a);
}

inline void VmParamsRenderControlWinform::Dispose()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 38, _a);
}

inline void VmParamsRenderControlWinform::EnlargeView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 39, _a);
}

inline void VmParamsRenderControlWinform::EnlargeView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 40, _a);
}

inline bool VmParamsRenderControlWinform::Equals(const QVariant& obj)
{
    bool qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&obj};
    qt_metacall(QMetaObject::InvokeMetaMethod, 41, _a);
    return qax_result;
}

inline int VmParamsRenderControlWinform::GetHashCode()
{
    int qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 42, _a);
    return qax_result;
}

inline qlonglong VmParamsRenderControlWinform::GetObjectPointer()
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 43, _a);
    return qax_result;
}

inline QString VmParamsRenderControlWinform::GetSelectedImageDisplayName()
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 44, _a);
    return qax_result;
}

inline QString VmParamsRenderControlWinform::GetSelectedImageDisplayName(int index)
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 45, _a);
    return qax_result;
}

inline mscorlib::_Type* VmParamsRenderControlWinform::GetType()
{
    mscorlib::_Type* qax_result = 0;
#ifdef QAX_DUMPCPP_MSCORLIB_H
    qRegisterMetaType<mscorlib::_Type*>("mscorlib::_Type*", &qax_result);
    qRegisterMetaType<mscorlib::_Type>("mscorlib::_Type", qax_result);
#endif
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 46, _a);
    return qax_result;
}

inline void VmParamsRenderControlWinform::HideCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 48, _a);
}

inline void VmParamsRenderControlWinform::InitView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 49, _a);
}

inline void VmParamsRenderControlWinform::InitView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 50, _a);
}

inline qlonglong VmParamsRenderControlWinform::LoadIndependentGroup(qlonglong pSol)
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&pSol};
    qt_metacall(QMetaObject::InvokeMetaMethod, 51, _a);
    return qax_result;
}

inline qlonglong VmParamsRenderControlWinform::LoadSol(qlonglong pSol)
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&pSol};
    qt_metacall(QMetaObject::InvokeMetaMethod, 52, _a);
    return qax_result;
}

inline void VmParamsRenderControlWinform::SaveOriginalImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 53, _a);
}

inline void VmParamsRenderControlWinform::SaveOriginalImage(const QString& fileName, int index)
{
    void *_a[] = {0, (void*)&fileName, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 54, _a);
}

inline void VmParamsRenderControlWinform::SaveOriginalImage(const QString& fileName, int index, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&index, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 55, _a);
}

inline void VmParamsRenderControlWinform::SaveRenderedImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 56, _a);
}

inline void VmParamsRenderControlWinform::SaveRenderedImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 57, _a);
}

inline void VmParamsRenderControlWinform::SetAnnularSector(qlonglong pAnnularSector)
{
    void *_a[] = {0, (void*)&pAnnularSector};
    qt_metacall(QMetaObject::InvokeMetaMethod, 58, _a);
}

inline void VmParamsRenderControlWinform::SetAnnularSector(qlonglong pAnnularSector, bool isAddShape)
{
    void *_a[] = {0, (void*)&pAnnularSector, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 59, _a);
}

inline void VmParamsRenderControlWinform::SetBackground(const QString& value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 60, _a);
}

inline void VmParamsRenderControlWinform::SetCircle(qlonglong pCircle)
{
    void *_a[] = {0, (void*)&pCircle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 61, _a);
}

inline void VmParamsRenderControlWinform::SetCircle(qlonglong pCircle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pCircle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 62, _a);
}

inline void VmParamsRenderControlWinform::SetEllipse(qlonglong pEllipse)
{
    void *_a[] = {0, (void*)&pEllipse};
    qt_metacall(QMetaObject::InvokeMetaMethod, 63, _a);
}

inline void VmParamsRenderControlWinform::SetEllipse(qlonglong pEllipse, bool isAddShape)
{
    void *_a[] = {0, (void*)&pEllipse, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 64, _a);
}

inline void VmParamsRenderControlWinform::SetImageSourceData(qlonglong pImgData)
{
    void *_a[] = {0, (void*)&pImgData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 65, _a);
}

inline void VmParamsRenderControlWinform::SetLine(qlonglong pLine)
{
    void *_a[] = {0, (void*)&pLine};
    qt_metacall(QMetaObject::InvokeMetaMethod, 66, _a);
}

inline void VmParamsRenderControlWinform::SetLine(qlonglong pLine, bool isAddShape)
{
    void *_a[] = {0, (void*)&pLine, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 67, _a);
}

inline void VmParamsRenderControlWinform::SetMultiImageButtonVisible(bool isVisible)
{
    void *_a[] = {0, (void*)&isVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 68, _a);
}

inline void VmParamsRenderControlWinform::SetParamTabEditable(bool isEditable)
{
    void *_a[] = {0, (void*)&isEditable};
    qt_metacall(QMetaObject::InvokeMetaMethod, 69, _a);
}

inline void VmParamsRenderControlWinform::SetParamsInfo(qlonglong pData)
{
    void *_a[] = {0, (void*)&pData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 70, _a);
}

inline void VmParamsRenderControlWinform::SetPointSet(qlonglong pPointSet)
{
    void *_a[] = {0, (void*)&pPointSet};
    qt_metacall(QMetaObject::InvokeMetaMethod, 71, _a);
}

inline void VmParamsRenderControlWinform::SetPointSet(qlonglong pPointSet, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPointSet, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 72, _a);
}

inline void VmParamsRenderControlWinform::SetPolygon(qlonglong pPolygon)
{
    void *_a[] = {0, (void*)&pPolygon};
    qt_metacall(QMetaObject::InvokeMetaMethod, 73, _a);
}

inline void VmParamsRenderControlWinform::SetPolygon(qlonglong pPolygon, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolygon, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 74, _a);
}

inline void VmParamsRenderControlWinform::SetPolyline(qlonglong pPolyline)
{
    void *_a[] = {0, (void*)&pPolyline};
    qt_metacall(QMetaObject::InvokeMetaMethod, 75, _a);
}

inline void VmParamsRenderControlWinform::SetPolyline(qlonglong pPolyline, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolyline, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 76, _a);
}

inline void VmParamsRenderControlWinform::SetRectangle(qlonglong pRectangle)
{
    void *_a[] = {0, (void*)&pRectangle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 77, _a);
}

inline void VmParamsRenderControlWinform::SetRectangle(qlonglong pRectangle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pRectangle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 78, _a);
}

inline void VmParamsRenderControlWinform::SetRenderCondition(RenderSatus status)
{
    void *_a[] = {0, (void*)&status};
    qt_metacall(QMetaObject::InvokeMetaMethod, 79, _a);
}

inline void VmParamsRenderControlWinform::SetRenderInterval(int pMillseconds)
{
    void *_a[] = {0, (void*)&pMillseconds};
    qt_metacall(QMetaObject::InvokeMetaMethod, 80, _a);
}

inline void VmParamsRenderControlWinform::SetText(qlonglong pText)
{
    void *_a[] = {0, (void*)&pText};
    qt_metacall(QMetaObject::InvokeMetaMethod, 82, _a);
}

inline void VmParamsRenderControlWinform::SetText(qlonglong pText, bool isAddShape)
{
    void *_a[] = {0, (void*)&pText, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 83, _a);
}

inline void VmParamsRenderControlWinform::ShowCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 84, _a);
}

inline void VmParamsRenderControlWinform::ShrinkView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 85, _a);
}

inline void VmParamsRenderControlWinform::ShrinkView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 86, _a);
}

inline void VmParamsRenderControlWinform::add_Disposed(mscorlib::_EventHandler* value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 87, _a);
}

inline void VmParamsRenderControlWinform::remove_Disposed(mscorlib::_EventHandler* value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 88, _a);
}


inline void VmParamsRenderInterface::ChangeImageComboBoxVisibility(bool isImageComboBoxVisible)
{
    void *_a[] = {0, (void*)&isImageComboBoxVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 8, _a);
}

inline void VmParamsRenderInterface::ClearDisplayView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 9, _a);
}

inline void VmParamsRenderInterface::ClearDisplayView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 10, _a);
}

inline void VmParamsRenderInterface::Dispose()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 11, _a);
}

inline void VmParamsRenderInterface::EnlargeView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 12, _a);
}

inline void VmParamsRenderInterface::EnlargeView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 13, _a);
}

inline qlonglong VmParamsRenderInterface::GetObjectPointer()
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 14, _a);
    return qax_result;
}

inline QString VmParamsRenderInterface::GetSelectedImageDisplayName()
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result};
    qt_metacall(QMetaObject::InvokeMetaMethod, 15, _a);
    return qax_result;
}

inline QString VmParamsRenderInterface::GetSelectedImageDisplayName(int index)
{
    QString qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 16, _a);
    return qax_result;
}

inline void VmParamsRenderInterface::HideCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 17, _a);
}

inline void VmParamsRenderInterface::InitView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 18, _a);
}

inline void VmParamsRenderInterface::InitView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 19, _a);
}

inline qlonglong VmParamsRenderInterface::LoadIndependentGroup(qlonglong pSol)
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&pSol};
    qt_metacall(QMetaObject::InvokeMetaMethod, 20, _a);
    return qax_result;
}

inline qlonglong VmParamsRenderInterface::LoadSol(qlonglong pSol)
{
    qlonglong qax_result;
    void *_a[] = {(void*)&qax_result, (void*)&pSol};
    qt_metacall(QMetaObject::InvokeMetaMethod, 21, _a);
    return qax_result;
}

inline void VmParamsRenderInterface::SaveOriginalImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 22, _a);
}

inline void VmParamsRenderInterface::SaveOriginalImage(const QString& fileName, int index)
{
    void *_a[] = {0, (void*)&fileName, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 23, _a);
}

inline void VmParamsRenderInterface::SaveOriginalImage(const QString& fileName, int index, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&index, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 24, _a);
}

inline void VmParamsRenderInterface::SaveRenderedImage(const QString& fileName)
{
    void *_a[] = {0, (void*)&fileName};
    qt_metacall(QMetaObject::InvokeMetaMethod, 25, _a);
}

inline void VmParamsRenderInterface::SaveRenderedImage(const QString& fileName, int jpgQuality)
{
	if (jpgQuality > 100 || jpgQuality <= 0)
    {
        throw CVmException(IMVS_EC_PARAM);
    }
    void *_a[] = {0, (void*)&fileName, (void*)&jpgQuality};
    qt_metacall(QMetaObject::InvokeMetaMethod, 26, _a);
}

inline void VmParamsRenderInterface::SetAnnularSector(qlonglong pAnnularSector)
{
    void *_a[] = {0, (void*)&pAnnularSector};
    qt_metacall(QMetaObject::InvokeMetaMethod, 27, _a);
}

inline void VmParamsRenderInterface::SetAnnularSector(qlonglong pAnnularSector, bool isAddShape)
{
    void *_a[] = {0, (void*)&pAnnularSector, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 28, _a);
}

inline void VmParamsRenderInterface::SetBackground(const QString& value)
{
    void *_a[] = {0, (void*)&value};
    qt_metacall(QMetaObject::InvokeMetaMethod, 29, _a);
}

inline void VmParamsRenderInterface::SetCircle(qlonglong pCircle)
{
    void *_a[] = {0, (void*)&pCircle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 30, _a);
}

inline void VmParamsRenderInterface::SetCircle(qlonglong pCircle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pCircle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 31, _a);
}

inline void VmParamsRenderInterface::SetEllipse(qlonglong pEllipse)
{
    void *_a[] = {0, (void*)&pEllipse};
    qt_metacall(QMetaObject::InvokeMetaMethod, 32, _a);
}

inline void VmParamsRenderInterface::SetEllipse(qlonglong pEllipse, bool isAddShape)
{
    void *_a[] = {0, (void*)&pEllipse, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 33, _a);
}

inline void VmParamsRenderInterface::SetImageSourceData(qlonglong pImgData)
{
    void *_a[] = {0, (void*)&pImgData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 34, _a);
}

inline void VmParamsRenderInterface::SetLine(qlonglong pLine)
{
    void *_a[] = {0, (void*)&pLine};
    qt_metacall(QMetaObject::InvokeMetaMethod, 35, _a);
}

inline void VmParamsRenderInterface::SetLine(qlonglong pLine, bool isAddShape)
{
    void *_a[] = {0, (void*)&pLine, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 36, _a);
}

inline void VmParamsRenderInterface::SetMultiImageButtonVisible(bool isVisible)
{
    void *_a[] = {0, (void*)&isVisible};
    qt_metacall(QMetaObject::InvokeMetaMethod, 37, _a);
}

inline void VmParamsRenderInterface::SetParamTabEditable(bool isEditable)
{
    void *_a[] = {0, (void*)&isEditable};
    qt_metacall(QMetaObject::InvokeMetaMethod, 38, _a);
}

inline void VmParamsRenderInterface::SetParamsInfo(qlonglong pData)
{
    void *_a[] = {0, (void*)&pData};
    qt_metacall(QMetaObject::InvokeMetaMethod, 39, _a);
}

inline void VmParamsRenderInterface::SetPointSet(qlonglong pPointSet)
{
    void *_a[] = {0, (void*)&pPointSet};
    qt_metacall(QMetaObject::InvokeMetaMethod, 40, _a);
}

inline void VmParamsRenderInterface::SetPointSet(qlonglong pPointSet, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPointSet, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 41, _a);
}

inline void VmParamsRenderInterface::SetPolygon(qlonglong pPolygon)
{
    void *_a[] = {0, (void*)&pPolygon};
    qt_metacall(QMetaObject::InvokeMetaMethod, 42, _a);
}

inline void VmParamsRenderInterface::SetPolygon(qlonglong pPolygon, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolygon, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 43, _a);
}

inline void VmParamsRenderInterface::SetPolyline(qlonglong pPolyline)
{
    void *_a[] = {0, (void*)&pPolyline};
    qt_metacall(QMetaObject::InvokeMetaMethod, 44, _a);
}

inline void VmParamsRenderInterface::SetPolyline(qlonglong pPolyline, bool isAddShape)
{
    void *_a[] = {0, (void*)&pPolyline, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 45, _a);
}

inline void VmParamsRenderInterface::SetRectangle(qlonglong pRectangle)
{
    void *_a[] = {0, (void*)&pRectangle};
    qt_metacall(QMetaObject::InvokeMetaMethod, 46, _a);
}

inline void VmParamsRenderInterface::SetRectangle(qlonglong pRectangle, bool isAddShape)
{
    void *_a[] = {0, (void*)&pRectangle, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 47, _a);
}

inline void VmParamsRenderInterface::SetRenderCondition(RenderSatus status)
{
    void *_a[] = {0, (void*)&status};
    qt_metacall(QMetaObject::InvokeMetaMethod, 48, _a);
}

inline void VmParamsRenderInterface::SetRenderInterval(int pMillseconds)
{
    void *_a[] = {0, (void*)&pMillseconds};
    qt_metacall(QMetaObject::InvokeMetaMethod, 49, _a);
}

inline void VmParamsRenderInterface::SetText(qlonglong pText)
{
    void *_a[] = {0, (void*)&pText};
    qt_metacall(QMetaObject::InvokeMetaMethod, 50, _a);
}

inline void VmParamsRenderInterface::SetText(qlonglong pText, bool isAddShape)
{
    void *_a[] = {0, (void*)&pText, (void*)&isAddShape};
    qt_metacall(QMetaObject::InvokeMetaMethod, 51, _a);
}

inline void VmParamsRenderInterface::ShowCoordinateInfo()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 52, _a);
}

inline void VmParamsRenderInterface::ShrinkView()
{
    void *_a[] = {0};
    qt_metacall(QMetaObject::InvokeMetaMethod, 53, _a);
}

inline void VmParamsRenderInterface::ShrinkView(int index)
{
    void *_a[] = {0, (void*)&index};
    qt_metacall(QMetaObject::InvokeMetaMethod, 54, _a);
}



#endif

}

QT_BEGIN_NAMESPACE

namespace QtMetaTypePrivate {
template<>
struct QMetaTypeFunctionHelper<VmParamsRenderControlWinform::VmParamsRenderControlWinform, /* Accepted */ true> {
    static void Destruct(void *t)
    {
        Q_UNUSED(t)
        static_cast<VmParamsRenderControlWinform::VmParamsRenderControlWinform*>(t)->VmParamsRenderControlWinform::~VmParamsRenderControlWinform();
    }
    static void *Construct(void *where, const void *t)
    {
        Q_ASSERT(!t);
        Q_UNUSED(t)
        return new (where) VmParamsRenderControlWinform::VmParamsRenderControlWinform;
    }
#ifndef QT_NO_DATASTREAM
    static void Save(QDataStream &stream, const void *t) { stream << *static_cast<const VmParamsRenderControlWinform::VmParamsRenderControlWinform*>(t); }
    static void Load(QDataStream &stream, void *t) { stream >> *static_cast<VmParamsRenderControlWinform::VmParamsRenderControlWinform*>(t); }
#endif // QT_NO_DATASTREAM
};

template<>
struct QMetaTypeFunctionHelper<VmParamsRenderControlWinform::VmParamsRenderInterface, /* Accepted */ true> {
    static void Destruct(void *t)
    {
        Q_UNUSED(t)
        static_cast<VmParamsRenderControlWinform::VmParamsRenderInterface*>(t)->VmParamsRenderControlWinform::VmParamsRenderInterface::~VmParamsRenderInterface();
    }
    static void *Construct(void *where, const void *t)
    {
        Q_ASSERT(!t);
        Q_UNUSED(t)
        return new (where) VmParamsRenderControlWinform::VmParamsRenderInterface;
    }
#ifndef QT_NO_DATASTREAM
    static void Save(QDataStream &stream, const void *t) { stream << *static_cast<const VmParamsRenderControlWinform::VmParamsRenderInterface*>(t); }
    static void Load(QDataStream &stream, void *t) { stream >> *static_cast<VmParamsRenderControlWinform::VmParamsRenderInterface*>(t); }
#endif // QT_NO_DATASTREAM
};

} // namespace QtMetaTypePrivate
QT_END_NAMESPACE

#endif

