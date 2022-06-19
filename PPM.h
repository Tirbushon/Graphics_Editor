#pragma once
#include "Image.h"

class PPM : public Image
{
private:
	virtual void readFile();
public:
	PPM(std::string);
	virtual void grayscale() override;
	virtual void negative() override;
	virtual void monochrome() override;
};

