#include "stdafx.h"

#include"GreyTransform.h"

void GreyTransform(IppByteImage& img, double CoefA, double CoefB)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit((int)(((p[i]*CoefA)+CoefB) + 0.499999));
	}
}