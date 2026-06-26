#pragma once

#include "IppImage\IppImage.h"

int GetMin(IppByteImage& img);
int GetMax(IppByteImage& img);
void GetStretching(IppByteImage& img, int max, int min);