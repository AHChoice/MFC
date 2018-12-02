#pragma once


// CColorGroupBox

class CColorGroupBox : public CStatic
{
	DECLARE_DYNAMIC(CColorGroupBox)

public:
	CColorGroupBox(CFont *pFont);//可以调用这个构造函数来创建自己的字体
	CColorGroupBox();
	virtual ~CColorGroupBox();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void SetBorderColor(COLORREF colorRef);//设置GroupBox的边框颜色，并立即重绘出来

private:
	void CreateDefaultFont();//创建默认的字体

private:
	COLORREF m_color;//边框颜色
	CFont m_Font;    //字体


};


