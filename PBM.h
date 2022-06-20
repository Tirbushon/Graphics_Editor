#pragma once
#include "Image.h"
// NOT IMPLEMENTED
class PBM : public Image
{
public:
	PBM(std::string);
	void grayscale();
	virtual void monochrome() override;
	virtual void negative() override;
};