#include "stdafx.h"
#include "GetStretching.h"

int GetMin(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	int min = 255;

	for (int i = 0; i < size; i++)
	{
		if (min > p[i])
		{
			min = p[i];
		}

	}
	return min;
}

int GetMax(IppByteImage& img)
{

	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		if (max < p[i])
		{
			max = p[i];
		}
	}
	return max;
}

void GetStretching(IppByteImage& img, int max, int min)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (int)(((static_cast<float>(p[i]-min)/(max-min))*255) + 0.499999);
		if (max == min) {
			p[i] = 0;
			continue;
		}
	}
}