#include "PBM.h"

//void PBM::initialize() {
//	pixels = new char * [height];
//	for (int i = 0; i < height; i++) {
//		pixels[i] = new char[width];
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			pixels[i][j].setPixelValue(0);
//		}
//	}
//}

PBM::PBM(std::string _fileName) : Image(_fileName) {

}

//PBM::PBM(const PBM& other) {
//	width = other.width;
//	height = other.height;
//	pixels = new Pixel * [height];
//	for (int i = 0; i < height; i++) {
//		pixels[i] = new Pixel[width];
//	}
//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			pixels[i][j] = other.pixels[i][j];
//		}
//	}
//}

//PBM& PBM::operator=(const PBM& other){
//	if (this != &other) {
//		width = other.width;
//		height = other.height;
//		//allocate variable to populate from other
//		Pixel** tempPixels = new Pixel * [height];
//		for (int i = 0; i < width; i++) {
//			tempPixels[i] = new Pixel[width];
//		}
//		//populate tempPixels with other parameter
//		for (int i = 0; i < height; i++) {
//			for (int j = 0; j < width; j++) {
//				tempPixels[i][j] = other.pixels[i][j];
//			}
//		}
//		//delete this(current object)
//		for (int i = 0; i < height; i++) {
//			delete[] pixels[i];
//		}
//		delete[] pixels;
//
//		pixels = tempPixels;
//	}
//	return *this;
//}


void PBM::grayscale() {
	std::cout << "File format is PBM and is already in grayscale format.\n";
}

void PBM::monochrome() {
	std::cout << "File format is PBM and the image is already monochrome!\n";
}



void PBM::negative() {
	//for (int i = 0; i < height; i++) {
	//	for (int j = 0; j < width; j++) {
	//		if (pixels[i][j].getPixelValue() == 1)
	//			pixels[i][j].setPixelValue(0);
	//		else
	//			pixels[i][j].setPixelValue(1);
	//	}
	//}
}