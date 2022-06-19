#pragma once
#include "Image.h"
// not done
class PBM : public Image
{
public:
	PBM(std::string);
	void grayscale();
	virtual void monochrome() override;
	virtual void negative() override;
};