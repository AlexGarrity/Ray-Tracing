#pragma once

#include <vector>
// TODO:  Remove this from the file format header and put it in a separate IO header
#include <fstream>

#include "RGB.h"

class PPM
{
public:
	PPM() = default;
	PPM(uint64_t uWidth, uint64_t uHeight);
	
	void addPixel(const RGB &pixel, uint64_t x, uint64_t y);
	void writeToFile(const char* pchFilePath);

	std::vector<RGB> arrRGBGetPixelArray() const;
	uint64_t uGetWidth() const { return _uWidth; }
	uint64_t uGetHeight() const { return _uHeight; }

	std::vector<RGB> _arrRGBPixelData;
	uint64_t _uWidth = 0, _uHeight = 0;
};

