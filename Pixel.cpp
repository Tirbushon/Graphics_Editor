#include "Pixel.h"

Pixel::Pixel() {
	pixelValue = 0;
	maximumValue = 0;
	red = 0;
	green = 0;
	blue = 0;
}

Pixel::Pixel(const int _pixelValue) {
	pixelValue = _pixelValue;
}

Pixel::Pixel(const int _pixelValue, const int _maximumValue) {
	pixelValue = _pixelValue;
	maximumValue = _maximumValue;
}

Pixel::Pixel(const int _maximumValue, const int _red, const int _green, const int _blue) {
	maximumValue = _maximumValue;
	red = _red;
	green = _green;
	blue = _blue;
}

void Pixel::setPixelValue(const unsigned char _pixelValue) {
	pixelValue = _pixelValue;
}

void Pixel::setRed(const int _red) {
	red = _red;
}

void Pixel::setGreen(const int _green) {
	green = _green;
}

void Pixel::setBlue(const int _blue) {
	blue = _blue;
}

unsigned char Pixel::getPixelValue() const {
	return this->pixelValue;
}

int Pixel::getMaximumValue() const {
	return this->maximumValue;
}

int Pixel::getRed() const {
	return this->red;
}

int Pixel::getGreen() const {
	return this->green;
}

int Pixel::getBlue() const {
	return this->blue;
}