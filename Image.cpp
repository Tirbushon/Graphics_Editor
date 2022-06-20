#include "Image.h"

Image::Image(const std::string _fileName) {
	fileName = _fileName;
	pixels = nullptr;
	height = 0;
	width = 0;
	maxValue = 0;
}

Image::~Image() {
	for (int i = 0; i < height; i++) {
		delete[] pixels[i];
	}
	delete[] pixels;
}

unsigned char** Image::getPixels() const {
	return this->pixels;
}

unsigned int Image::getMaxValue() const {
	return this->maxValue;
}

unsigned int Image::getHeight() const {
	return height;
}

unsigned int Image::getWidth() const {
	return width;
}

std::string Image::getFileName() const {
	return fileName;
}

void Image::readHeader() {
	std::ifstream file(fileName);
	if (file.is_open()) {
		int counter = 0;
		char c;
		while (counter < 4) {
			if (counter == 0) {
				readPosition = file.tellg();
				file.get(c);
				if (c != '#') {
					file.seekg(readPosition);
					file >> format;
				}
			}
			else if (counter == 1) {
				readPosition = file.tellg();
				file.seekg(readPosition);
				file.get(c);
				if (c != '#') {
					file >> width;
				}
			}
			else if (counter == 2) {
				readPosition = file.tellg();
				file.get(c);
				if (c != '#') {
					file.seekg(readPosition);
					file >> height;
				}
			}
			else if (counter == 3) {
				readPosition = file.tellg();
				file.get(c);
				if (c != '#') {
					file.seekg(readPosition);
					file >> maxValue;
				}
			}
			counter += 1;
		}
		readPosition = file.tellg();
	}
	file.close();
}

void Image::setHeader(std::string _format) {
	this->format = _format;
}

std::string Image::getFormat() const {
	return this->format;
}

unsigned int Image::getPpmWidth() const {
	return ppmWidth;
}

void Image::monochrome() {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; i < width; j++) {
			if (pixels[i][j] > maxValue / 2) {
				pixels[i][j] = 0;
			}
			else {
				pixels[i][j] = (unsigned char)maxValue;
			}
		}
	}
}

