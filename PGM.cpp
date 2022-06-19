#include "PGM.h"

PGM::PGM(std::string fileName): Image(fileName) {
	readHeader();
	readFile();
}

void PGM::readFile() {
	std::ifstream file(fileName, std::ios::binary);
	readPosition += 1;
	file.seekg(readPosition);
	if (format == "P2") {
		pixels = new unsigned char* [height];
		for (size_t i = 0; i < height; i++) {
			pixels[i] = new unsigned char[width];
			for (size_t j = 0; j < width; j++) {
				int number;
				file >> number;
				pixels[i][j] = number;
			}
		}
	}
	if (format == "P5") {
		pixels = new unsigned char* [height];
		for (size_t i = 0; i < height; i++) {
			pixels[i] = new unsigned char[width];
			for (size_t j = 0; j < width; j++) {
				file.read((char*)&pixels[i][j], sizeof(pixels[i][j]));
			}
		}
	}
	file.close();
}


void PGM::grayscale() {
	std::cout << "Image is already in grayscale mode\n";
}

void PGM::negative() {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			pixels[i][j] = maxValue - pixels[i][j];
		}
	}
}

void PGM::monochrome() {
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; i < width; j++) {
			if ((unsigned)pixels[i][j] < maxValue / 2) {
				pixels[i][j] = 0;
			}
			else {
				pixels[i][j] = (unsigned char)maxValue;
			}
		}
	}
}