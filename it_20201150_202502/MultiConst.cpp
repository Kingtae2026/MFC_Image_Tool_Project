#include "stdafx.h"

#include"MultiConst.h"

void MultiConst(IppByteImage& img, double multic)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit((int)(p[i] * multic+0.499999));
	}
}