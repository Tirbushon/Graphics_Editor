#include "PPM.h"

PPM::PPM(std::string _fileName) : Image(_fileName) {
	readHeader();
	readFile();
}

void PPM::readFile() {
	std::ifstream file(fileName, std::ios::binary);
	readPosition += 1;
	ppmWidth = width * 3;
	file.seekg(readPosition);
	if (format == "P3") {
		pixels = new unsigned char* [height];
		for (size_t i = 0; i < height; i++) {
			pixels[i] = new unsigned char[ppmWidth];
			for (size_t j = 0; j < ppmWidth; j++) {
				int number;
				file >> number;
				pixels[i][j] = number;
			}
		}
	}
	if (format == "P6") {
		pixels = new unsigned char* [height];
		for (size_t i = 0; i < height; i++) {
			pixels[i] = new unsigned char[ppmWidth];
			for (size_t j = 0; j < ppmWidth; j++) {
				file.read((char*)&pixels[i][j], sizeof(pixels[i][j]));
			}
		}
	}
	file.close();
}

void PPM::grayscale() {
	for (size_t i = 0; i < height; i++) {
		int counter = 0;
		unsigned char red, green, blue;
		size_t redIndex, greenIndex, blueIndex;
		for (size_t j = 0; j < ppmWidth; j++) {
			counter++;
			if (counter == 1) {
				red = pixels[i][j];
				redIndex = j;
			}
			if (counter == 2) {
				green = pixels[i][j];
				greenIndex = j;
			}
			if (counter == 3) {
				blue = pixels[i][j];
				blueIndex = j;

				unsigned char gray = red * 0.3 + green * 0.59 + blue * 0.11;
				pixels[i][redIndex] = gray;
				pixels[i][greenIndex] = gray;
				pixels[i][blueIndex] = gray;

				counter = 0;
			}
		}
	}
}

void PPM::negative() {
	for (size_t i = 0; i < height; i++) {
		int counter = 0;
		unsigned char red, green, blue;
		size_t redIndex, greenIndex, blueIndex;
		for (size_t j = 0; j < ppmWidth; j++) {
			counter++;
			if (counter == 1) {
				red = pixels[i][j];
				redIndex = j;
			}
			if (counter == 2) {
				green = pixels[i][j];
				greenIndex = j;
			}
			if (counter == 3) {
				blue = pixels[i][j];
				blueIndex = j;

				unsigned char negativeRed = red - maxValue;
				unsigned char negativeGreen = green - maxValue;
				unsigned char negativeBlue = blue - maxValue;

				pixels[i][redIndex] = negativeRed;
				pixels[i][greenIndex] = negativeGreen;
				pixels[i][blueIndex] = negativeBlue;

				counter = 0;
			}
		}
	}
}

void PPM::monochrome() {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; i < ppmWidth; j++) {
			if (pixels[i][j] > maxValue / 2) {
				pixels[i][j] = 0;
			}
			else {
				pixels[i][j] = (unsigned char)maxValue;
			}
		}
	}
}