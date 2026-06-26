// CSubConstDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CSubConstDlg.h"


// CSubConstDlg 대화 상자

IMPLEMENT_DYNAMIC(CSubConstDlg, CDialogEx)

CSubConstDlg::CSubConstDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUB_CONST, pParent)
	, m_nSubConst(0)
{

}

CSubConstDlg::~CSubConstDlg()
{
}

void CSubConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUBCONST_EDIT, m_nSubConst);
	DDV_MinMaxInt(pDX, m_nSubConst, 0, 255);
}


BEGIN_MESSAGE_MAP(CSubConstDlg, CDialogEx)
END_MESSAGE_MAP()


// CSubConstDlg 메시지 처리기


BOOL CSubConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
