// YuePring.h: interface for the CYuePrint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_YUEPRINT_H__DD011A5C_BB2D_461C_97D2_7C8E17D3FAA5__INCLUDED_)
#define AFX_YUEPRINT_H__DD011A5C_BB2D_461C_97D2_7C8E17D3FAA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class _declspec(dllexport) CYuePrint  
{
public:
	CFont *pOldFont;

	int lineInterval;

	int x;
	int y;

private:
	CDC *pdc;
	HDC hdcprint;

public:
	CYuePrint();
	virtual ~CYuePrint();
public:
	int initPrint();
	int beginPrint();
	int printString(int size,CString strText,int cx=0,int cy=0);
	int printLine(int size,CString strText,int cx=0,int cy=0);
	void printImg(int SRCID,int cx=0,int cy=0);
	void endPrint();

private:
	int max_cy;
};

#endif // !defined(AFX_YUEPRINT_H__DD011A5C_BB2D_461C_97D2_7C8E17D3FAA5__INCLUDED_)
