#pragma once

#include "IppImage\IppImage.h"

void GetHistogram(IppByteImage& img, double histo[256]);
int GetMinGrayValue(IppByteImage& img);
int GetMaxGrayValue(IppByteImage& img);
float GetAvgValue(IppByteImage& img);
float GetStdValue(IppByteImage& img, float avg);