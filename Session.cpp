#include "Session.h"

Session::Session() {
	id += 1;
}

unsigned int Session::getID() const {
	return id;
}

bool Session::getSaved() const {
	return this->isSaved;
}

void Session::setSaved(bool _isSaved) {
	this->isSaved = _isSaved;
}

std::vector<Image*>& Session::getImages() {
	return this->images;
}

std::vector<std::string>& Session::getTransformations() {
	return transformations;
}

void Session::printSession() const {
	std::cout << "Name of images in the session: ";
	for (int i = 0; i < images.size(); i++) {
		Image* temp = images[i];
		std::cout << temp->getFileName() << " ";
	}
	std::cout << "\nPendingTransformations: ";
	for (int i = 0; i < transformations.size(); i++) {
		if (i == transformations.size() - 1)
			std::cout << transformations[i] << "\n";
		else
			std::cout << transformations[i] << ", ";
	}
}