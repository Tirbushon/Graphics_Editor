#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Pixel
{
private:
	// for pbm format
	unsigned char pixelValue;
	// used in pgm and ppm format
	int maximumValue;
	// for ppm format
	int red ;
	int green;
	int blue;
public:
	Pixel();
	// ctor for a single pixel in pbm format
	Pixel(const int);
	// ctor for a single pixel in pgm format
	Pixel(const int, const int);
	// ctor for a single pixel in ppm format
	Pixel(const int, const int, const int, const int);

	void setPixelValue(const unsigned char);
	void setRed(const int);
	void setGreen(const int);
	void setBlue(const int);

	unsigned char getPixelValue() const;
	int getMaximumValue() const;
	int getRed() const;
	int getGreen() const;
	int getBlue() const;


};

