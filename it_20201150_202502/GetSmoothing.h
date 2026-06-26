#pragma once
#include "IppImage\IppImage.h"

void GetHisto(IppByteImage& img, double histo[256]);
void GetSum( double histo[256], double sum[256]);
void GetSmooth(IppByteImage& img, double sum[256], double smooth[256]);