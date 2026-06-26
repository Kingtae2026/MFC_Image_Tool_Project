#include "stdafx.h"
#include "GetHistogram.h"

void GetHistogram(IppByteImage& img, double histo[256])
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

int GetMinGrayValue(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	int min =  255;

	for (int i = 0; i < size; i++)
	{
		if (min > p[i])
		{
			min = p[i];
		}
		
	}
	return min;
}

int GetMaxGrayValue(IppByteImage& img)
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

float GetAvgValue(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	int sum = 0;
	float avgvalue = 0;

	for (int i = 0; i < size; i++)
	{
		sum += p[i];
	}

	avgvalue = (float)sum / size;
	avgvalue = (float)((int)((avgvalue + 0.0499999) * 10.) / 10.);

	return avgvalue;
}

float GetStdValue(IppByteImage& img, float avgvalue)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();
	float sum = 0., dif;
	double stdvalue = 0;

	for (int i = 0; i < size; i++)
	{
		dif = ((float)p[i] - avgvalue);
		dif = dif * dif;
		sum += dif;
	}
	stdvalue = sum / ((float)size);
	stdvalue = sqrt(stdvalue);
	stdvalue = (float)((int)((stdvalue + 0.049999) * 10.) / 10.);
	return stdvalue;
}