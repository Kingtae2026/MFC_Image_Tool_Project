#include "stdafx.h"
#include "ImageToolSecChk.h"

int ImageToolSecChk(int InputCode)
{
	FILE* rfp = NULL;
	char OrgCode[9];
	int res, i, ChkCode, flag = 1;

	res = fopen_s(&rfp, "ImageTool.sec", "rb");
	if (res != 0)
	{
		AfxMessageBox(_T(">>> ERR #0: Reading File Open Error"));
		return 0;
	}

	fread(OrgCode, 1, 8, rfp);
	fclose(rfp);

	for (i = 0; i < 8; i++)
	{
		OrgCode[i] += 38;
	}

	ChkCode = atoi(OrgCode);

	if (ChkCode == InputCode)
		return 1;
	else
		return 0;
}