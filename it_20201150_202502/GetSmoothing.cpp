#include "stdafx.h"
#include "GetSmoothing.h"

void GetHisto(IppByteImage& img, double histo[256])
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	int cnt[256] = { 0 };
	for (int i = 0; i < size; i++)
	{
		cnt[p[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		histo[i] = static_cast<double>((double)cnt[i] / (double)size);
	}
}

void GetSum( double histo[256], double sum[256])
{
	sum[0] = histo[0];

	for (int i = 1; i < 256; i++)
	{
		sum[i] = sum[i - 1] + histo[i];
	}
}

void GetSmooth(IppByteImage& img, double sum[256], double smooth[256])
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	for (int i = 0; i < 256; i++)
	{
		smooth[i] = sum[i] * 255;
	}

	for (int i = 0; i < size; i++)
	{
		int v = (int)(smooth[p[i]] + 0.499999);
		if (v < 0) v = 0;
		if (v > 255) v = 255;
		p[i] = (BYTE)v;
	}

}