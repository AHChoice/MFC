// ColorGroupBox.cpp : 实现文件
//

#include "stdafx.h"
#include "ColorGroupBox.h"


// CColorGroupBox

IMPLEMENT_DYNAMIC(CColorGroupBox, CStatic)

CColorGroupBox::CColorGroupBox()
{
	m_color = RGB(87,165,213);//初始化颜色为红色
	CreateDefaultFont();
}

CColorGroupBox::CColorGroupBox(CFont *pFont)
{
	m_color = RGB(130, 135, 144);//初始化颜色为红色
	
	//m_color = RGB(255, 0, 0);//初始化颜色为红色
	if (NULL == pFont)
	{
		CreateDefaultFont();
	}
	else
	{
		LOGFONT logFont;
		pFont->GetLogFont(&logFont);//获取逻辑字体


		m_Font.CreateFont(logFont.lfHeight, logFont.lfWidth, logFont.lfEscapement, logFont.lfOrientation,
			logFont.lfWeight, logFont.lfItalic, logFont.lfUnderline, logFont.lfStrikeOut,
			logFont.lfCharSet, logFont.lfOutPrecision, logFont.lfClipPrecision, logFont.lfQuality,
			logFont.lfPitchAndFamily, logFont.lfFaceName);//创建新的字体
	}
	
}

void CColorGroupBox::CreateDefaultFont()
{
	m_Font.CreatePointFont(100, _T("微软雅黑"));
}

CColorGroupBox::~CColorGroupBox()
{
}


BEGIN_MESSAGE_MAP(CColorGroupBox, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CColorGroupBox::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//获取矩形范围
	CRect rcClient;
	GetClientRect(&rcClient);

	//创建画笔
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, m_color);
	
	//选入画笔
	dc.SelectObject(pen);
	dc.SelectStockObject(NULL_BRUSH);//只画一个矩形边框，不使用画刷擦除矩形内的图形

	dc.SelectObject(m_Font);

	CString strText;

	GetWindowText(strText);
	rcClient.top = 7;//矩形的位置向下移动一些，给文本留一些位置
	dc.Rectangle(rcClient);
    
	//显示文本
	CWnd *pParent = GetParent();
	if(NULL != pParent)
	{
		COLORREF colorRef = pParent->GetDC()->GetPixel(1, 1);//根据父窗口像素点的颜色来获取父窗口的背景颜色
		dc.SetBkColor(colorRef);//设置文本的背景颜色为父窗口的背景颜色	
	}
	
	dc.TextOut(10, 0,strText);
}

//设置GroupBox的边框颜色，并立即重绘出来
void CColorGroupBox::SetBorderColor(COLORREF colorRef)
{
	m_color = colorRef;
	Invalidate();//使矩形无效，重绘
}
