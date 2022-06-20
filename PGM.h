#pragma once
#include "Image.h"

/* Class PGM that inherits class Image and constructs it for its format
*/

class PGM : public Image
{
private:
	//reads the contents of a file after the Header(format, width, height, maxValue)
	//depending on the format P2 or P5, the function initializes the variable pixels from Image class
	virtual void readFile();
public:
	PGM(std::string);
	//turns a PGM image into grayscale
	//since the image is already in grayscale it does nothing
	virtual void grayscale() override;
	//turns a PGM image into negative
	//the formula for turning a picture into negative is:
	// newPixelVal = maxValue - oldPixelVal
	// read from:
	// https://www.cs.nmsu.edu/~hfugal/cs167/labs/negative.html
	virtual void negative() override;
};

