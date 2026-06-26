// CGammaCorrectionDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageTool.h"
#include "afxdialogex.h"
#include "CGammaCorrectionDlg.h"


// CGammaCorrectionDlg 대화 상자

IMPLEMENT_DYNAMIC(CGammaCorrectionDlg, CDialogEx)

CGammaCorrectionDlg::CGammaCorrectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAMMA_CORRECTION, pParent)
	, m_dGammaCorr(0)
{

}

CGammaCorrectionDlg::~CGammaCorrectionDlg()
{
}

void CGammaCorrectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_GAMMACORR_EDIT, m_dGammaCorr);
	DDV_MinMaxDouble(pDX, m_dGammaCorr, 0.0, 10.0);
}


BEGIN_MESSAGE_MAP(CGammaCorrectionDlg, CDialogEx)
	ON_EN_CHANGE(IDC_GAMMACORR_EDIT, &CGammaCorrectionDlg::OnEnChangeGammacorrEdit)
END_MESSAGE_MAP()


// CGammaCorrectionDlg 메시지 처리기


BOOL CGammaCorrectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CGammaCorrectionDlg::OnEnChangeGammacorrEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
}
