#include "stdafx.h"
#include "math.h"

#include"GammaCorrection.h"

void GammaCorrection(IppByteImage& img, double Gammacorr)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = limit((int)(pow(p[i] / 255.0, 1.0 / Gammacorr) * 255.0 + 0.499999));
	}
}