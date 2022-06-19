#pragma once
#include "Image.h"

class PGM : public Image
{
private:
	virtual void readFile();
public:
	PGM(std::string);
	virtual void grayscale() override;
	virtual void negative() override;
	virtual void monochrome() override;
};

