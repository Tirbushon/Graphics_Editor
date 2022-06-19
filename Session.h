#pragma once
#include "Image.h"

class Session
{
private:
	unsigned int id = 0;
	std::vector<std::string> transformations;
	std::vector<Image*> images;
	bool isSaved = false;
public:
	Session();
	bool getSaved() const;
	void setSaved(bool);
	unsigned int getID() const;
	std::vector<Image*>& getImages();
	std::vector<std::string>& getTransformations();
	void printSession() const;
};