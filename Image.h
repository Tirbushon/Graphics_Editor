#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/** Abstract class Image that represents an image in both ASCII and Binary format
	
	NB:reading from a file works only when there aren't any comments in the file

  * @variable fileName = name of the file
  * @variable pixels = 2d array of characters each representing a single byte from the file
  * @variable height = the height of a picture(how many pixels there are vertically)
  * @variable width = the width of a picture(how many pixels there are horizontally)
  * @variable ppmWidth = width of a picture SPECIFICALLY for images that are in ppm format
  *					since each pixel comprises of 3 bytes
  * @variable format = the format of the picture("P1", "P2", "P3", "P4", "P5", "P6")
  * @variable maxValue = the maximum value of a pixel(for ppm and pgm files only)
  * @variable readPosition = variable that helps when reading a file in binary
*/

class Image
{
public:
	Image(const std::string);
	virtual ~Image();

	//not implemented
	virtual void rotate(std::string) {};
	
	//func to turn a single image to a grayscale one
	//that means that it turns a pixel into a nuance of gray
	virtual void grayscale() = 0;

	//func to turn a single image to a negative one
	//that means that it turns every pixel into a negative one using a formula 
	virtual void negative() = 0;
	
	//func to turn a single image to a monochrome one
	//it turns a pixel to either a white one or black one
	//the function does not = 0 since it is the same for every file
	virtual void monochrome();


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

	//function that fills the format, height,width and max value parameters
	void readHeader();
};