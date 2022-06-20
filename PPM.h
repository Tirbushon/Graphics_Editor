#pragma once
#include "Image.h"

/* Class PPM that inherits class Image and constructs it for its format
*/

class PPM : public Image
{
private:
	//reads the contents of a file after the Header(format, width, height, maxValue)
	//depending on the format P3 or P6, the function initializes the variable pixels from Image class
	virtual void readFile();
public:
	PPM(std::string);
	//converts a ppm picture into a grayscale
	//the algorithm that is used to convert each pixel of RGB is from this article:
	//https://tannerhelland.com/2011/10/01/grayscale-image-algorithm-vb6.html
	// Gray = (Red * 0.3 + Green * 0.59 + Blue * 0.11)
	virtual void grayscale() override;
	//converts a pgm picture into a negative
	//each pixel from the RGB triplet is converted to its negative part
	//the formula is the same like the one from the pgm format
	//the only difference is that it needs to be done on each pixel in the
	//triplet - red, green, blue
	virtual void negative() override;
};

