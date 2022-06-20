#pragma once
#include "Image.h"

/* Sessions class that represents a session in the programme
*  
* @variable id = the sessions id 
* @variable transformations = vector of transformations in the session
* @variable images = vector of Image pointers storing the images
* @variable isSaved = used to check if the session is saved
*
*/

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