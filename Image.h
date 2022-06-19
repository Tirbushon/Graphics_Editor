#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Image
{
public:
	Image(const std::string);
	virtual ~Image();

	virtual void rotate(std::string) {};
	virtual void grayscale() = 0;
	virtual void negative() = 0;
	virtual void monochrome() = 0;


	virtual unsigned int getWidth() const;
	virtual unsigned int getHeight() const;
	virtual std::string getFileName() const;
	virtual unsigned char** getPixels() const;
	virtual unsigned int getMaxValue() const;
	virtual void setHeader(std::string);
	virtual std::string getFormat() const;
	virtual unsigned int getPpmWidth() const;

protected:
	std::string fileName;
	unsigned char** pixels;
	unsigned int height;
	unsigned int width;
	unsigned int ppmWidth;
	std::string format = "";
	unsigned int maxValue;

	std::streampos readPosition;

	void readHeader();
};