#include "stdafx.h"

#include"DivdConst.h"

void DivdConst(IppByteImage& img, double divdc)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit((int)((p[i] / divdc) + 0.499999));
	}
}