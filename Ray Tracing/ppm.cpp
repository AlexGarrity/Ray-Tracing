#include "PPM.h"

PPM::PPM(uint64_t uWidth, uint64_t uHeight)
{
	_uHeight = uHeight;
	_uWidth = uWidth;
	_arrRGBPixelData.resize(_uHeight * _uWidth);
}

void PPM::addPixel(const RGB& pixel, uint64_t x, uint64_t y)
{
	uint64_t position = (y * _uWidth) + x;
	_arrRGBPixelData[position] = pixel;
	_arrRGBPixelData[position].recalculateIntegers();
}

void PPM::writeToFile(const char* pchFilePath)
{
	std::ofstream writer;
	writer.open(pchFilePath, std::ios::out);
	writer << "P3\n" << _uWidth << " " << _uHeight << "\n255\n";
	for (RGB p : _arrRGBPixelData) {
		writer << p << "\n";
	}
	writer.close();
}

std::vector<RGB> PPM::arrRGBGetPixelArray() const
{
	return _arrRGBPixelData;
}
