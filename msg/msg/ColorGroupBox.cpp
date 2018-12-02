// ColorGroupBox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ColorGroupBox.h"


// CColorGroupBox

IMPLEMENT_DYNAMIC(CColorGroupBox, CStatic)

CColorGroupBox::CColorGroupBox()
{
	m_color = RGB(87,165,213);//��ʼ����ɫΪ��ɫ
	CreateDefaultFont();
}

CColorGroupBox::CColorGroupBox(CFont *pFont)
{
	m_color = RGB(130, 135, 144);//��ʼ����ɫΪ��ɫ
	
	//m_color = RGB(255, 0, 0);//��ʼ����ɫΪ��ɫ
	if (NULL == pFont)
	{
		CreateDefaultFont();
	}
	else
	{
		LOGFONT logFont;
		pFont->GetLogFont(&logFont);//��ȡ�߼�����


		m_Font.CreateFont(logFont.lfHeight, logFont.lfWidth, logFont.lfEscapement, logFont.lfOrientation,
			logFont.lfWeight, logFont.lfItalic, logFont.lfUnderline, logFont.lfStrikeOut,
			logFont.lfCharSet, logFont.lfOutPrecision, logFont.lfClipPrecision, logFont.lfQuality,
			logFont.lfPitchAndFamily, logFont.lfFaceName);//�����µ�����
	}
	
}

void CColorGroupBox::CreateDefaultFont()
{
	m_Font.CreatePointFont(100, _T("΢���ź�"));
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

	//��ȡ���η�Χ
	CRect rcClient;
	GetClientRect(&rcClient);

	//��������
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, m_color);
	
	//ѡ�뻭��
	dc.SelectObject(pen);
	dc.SelectStockObject(NULL_BRUSH);//ֻ��һ�����α߿򣬲�ʹ�û�ˢ���������ڵ�ͼ��

	dc.SelectObject(m_Font);

	CString strText;

	GetWindowText(strText);
	rcClient.top = 7;//���ε�λ�������ƶ�һЩ�����ı���һЩλ��
	dc.Rectangle(rcClient);
    
	//��ʾ�ı�
	CWnd *pParent = GetParent();
	if(NULL != pParent)
	{
		COLORREF colorRef = pParent->GetDC()->GetPixel(1, 1);//���ݸ��������ص����ɫ����ȡ�����ڵı�����ɫ
		dc.SetBkColor(colorRef);//�����ı��ı�����ɫΪ�����ڵı�����ɫ	
	}
	
	dc.TextOut(10, 0,strText);
}

//����GroupBox�ı߿���ɫ���������ػ����
void CColorGroupBox::SetBorderColor(COLORREF colorRef)
{
	m_color = colorRef;
	Invalidate();//ʹ������Ч���ػ�
}
