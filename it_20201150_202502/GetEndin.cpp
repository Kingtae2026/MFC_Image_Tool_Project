#include "stdafx.h"

#include "GetEndin.h"

void GetEndin(IppByteImage& img, int High, int Low)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		if (p[i] <= Low)
		{
			p[i] = 0;
		}
		else if (p[i] >= High)
		{
			p[i] = 255;
		}
		else
		{
			p[i] = (int)(static_cast<float>((p[i] - Low) * 255) / (High - Low) + 0.499999);
		}
		
	}
}