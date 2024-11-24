/***************************************************************************************************
 *
 * 版权信息：版权所有 (c) 2020, 杭州海康机器人技术有限公司, 保留所有权利
 *
 * 文件名称： VmControlBaseInfo.h
 * 摘    要: VM形状类声明
 *
 * 日    期：2020-10-29 19:24:30
 * 备    注：新建
 ****************************************************************************************************/
#ifndef CVMCONTROLBASEINFO_H__ // 2020-10-29 19:24:30
#define CVMCONTROLBASEINFO_H__

 // float Opacity 范围[0,1]，0-透明，1-不透明
 // int Color 32位带符号整数，由a、r、g、b通过移位运算后累加得到
 // int FillColor 32位带符号整数，由a、r、g、b通过移位运算后累加得到，只支持IRect、ICircle、IAnnularSector
 // float StrokeThickness 只支持IRect、ICircle、IAnnularSector、ILine、IPolygon、IPolyline

enum RenderSatus {	
	RenderSatus_NG = 0, //模块状态为NG时刷新渲染
    RenderSatus_OK = 1, //模块状态为OK时刷新渲染
    RenderSatus_ALL = 2 //所有模块状态都刷新渲染
};

 // 浮点型点信息结构
typedef struct PointFEx_ {
	float   X;        // X
	float   Y;        // Y
	float Opacity;    // 透明度
	int Color;        // 颜色
	int FillColor;    // 填充色
	float StrokeThickness; // 粗细
} PointFEx;

 // 点集
typedef struct PointSet_
{
	int PointNum;            // 点数量
	PointFEx * pstPointList; // 点集
	float Opacity;           // 透明度
	int Color;               // 颜色
	int FillColor;           // 填充色
	float StrokeThickness;   // 粗细
} PointSet;

// 多边形
typedef struct PolygonEx_
{
	int PolygonPointNum;            // 点数量
	PointFEx * PolygonPointListPtr; // 点集
	float Opacity;                  // 透明度
	int Color;                      // 颜色
	int FillColor;                  // 填充色
	float StrokeThickness;          // 粗细
} PolygonEx;

// 折线
typedef struct PolylineEx_
{
	int PolylinePointNum;            // 点数量
	PointFEx * PolylinePointListPtr; // 点集
	float Opacity;                   // 透明度
	int Color;                       // 颜色
	int FillColor;                   // 填充色
	float StrokeThickness;           // 粗细
} PolylineEx;

// 圆形
typedef struct CircleEx_
{
	float CenterX;         // X
	float CenterY;         // Y
	float MajorRadius;     // 主要半径
	float MinorRadius;     // 辅助半径
	float Opacity;         // 透明度
	int Color;             // 颜色
	int FillColor;         // 填充色
	float StrokeThickness; // 粗细
} CircleEx;

// 椭圆形
typedef struct EllipseEx_
{
    float CenterX;         // X
    float CenterY;         // Y
    float MajorRadius;	   // 长半轴
    float MinorRadius;	   // 短半轴
    float Angle;	       // 角度
    float Opacity;         // 透明度
    int Color;             // 颜色
    int FillColor;         // 填充色
    float StrokeThickness; // 粗细
} EllipseEx;

// 扇环形
typedef struct AnnulusEx_
{
	float CenterX;         // X
	float CenterY;         // Y
	float OuterRadius;     // 外环半径
	float InnerRadius;     // 内环半径
	float StartAngle;      // 起始角度
	float AngleRange;      // 角度范围
	float Opacity;         // 透明度
	int Color;             // 颜色
	int FillColor;         // 填充色
	float StrokeThickness; // 粗细
} AnnulusEx;

// 直线段
typedef struct LineEx_
{
	float StartPointX;     // 起点X
	float StartPointY;     // 起点Y
	float EndPointX;       // 终点X
	float EndPointY;       // 终点Y
	float Opacity;         // 透明度
	int Color;             // 颜色
	int FillColor;         // 填充色
	float StrokeThickness; // 粗细
} LineEx;

// 矩形/平行四边形
typedef struct RectangleEx_
{
	float CenterX;         // X
	float CenterY;         // Y
	float Width;           // 宽
	float Height;          // 高
	float Angle;           // 角度
	float SkewAngle;       // 斜切角度
	float Opacity;         // 透明度
	int Color;             // 颜色
	int FillColor;         // 填充色
	float StrokeThickness; // 粗细
} RectangleEx;

// 文本
typedef struct Text_
{
	char Content[4096];    // 文本信息
	float PositionX;       // X
	float PositionY;       // Y
	float Width;           // 宽
	float Height;          // 高
	int FontSize;          // 字体大小
	float Opacity;         // 透明度
	int Color;             // 颜色
	int FillColor;         // 填充色
	float StrokeThickness; // 粗细
} Text;

// 形状
typedef struct Shape_
{
	float Opacity;             //范围[0,1]，0-透明，1-不透明
	int Color;                 //32位带符号整数，由a、r、g、b通过移位运算后累加得到
	int FillColor;             //32位带符号整数，由a、r、g、b通过移位运算后累加得到，只支持IRect、ICircle、IAnnularSector
	float StrokeThickness;     //只支持IRect、ICircle、IAnnularSector、ILine、IPolygon、IPolyline
}Shape;

/***************************************** 参数配置控件 ***************************************/
// 参数配置信息
typedef struct ParamBaseEx_
{
	char XmlPath[780];    // XML路径
	void * Handle;        // 内部句柄
	unsigned int ModuId;  // 模块ID
	unsigned int TimeOut; // 超时
}ParamBaseEx;

/***************************************** 流程配置控件 ***************************************/
// 方案基础信息
typedef struct SolutionBaseEx_
{
	char strSolPath[780]; // 方案路径
	char strPassword[32]; // 方案密码
	unsigned int nReserved[4]; // 保留字段
}SolutionBaseEx;

/***************************************** QT 新增数据结构 ***************************************/
typedef struct GroupInputInfo_
{
    char strSolPath[780]; // 方案路径
    char strPassword[32]; // 方案密码
}GroupInputInfo;

typedef struct ParamCtrlInput__
{
    void * Handle;
    unsigned int ModuId;
} ParamCtrlInput;

typedef struct SolutionInputInfo_
{
	char strSolPath[780]; // 方案路径
	char strPassword[32]; // 方案密码
}SolutionInputInfo;

#endif // CVMCONTROLBASEINFO_H__
