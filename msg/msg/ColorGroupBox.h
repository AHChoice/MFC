#pragma once


// CColorGroupBox

class CColorGroupBox : public CStatic
{
	DECLARE_DYNAMIC(CColorGroupBox)

public:
	CColorGroupBox(CFont *pFont);//���Ե���������캯���������Լ�������
	CColorGroupBox();
	virtual ~CColorGroupBox();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void SetBorderColor(COLORREF colorRef);//����GroupBox�ı߿���ɫ���������ػ����

private:
	void CreateDefaultFont();//����Ĭ�ϵ�����

private:
	COLORREF m_color;//�߿���ɫ
	CFont m_Font;    //����


};


