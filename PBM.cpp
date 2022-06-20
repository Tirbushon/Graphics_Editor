#include "PBM.h"

PBM::PBM(std::string _fileName) : Image(_fileName) {

}

void PBM::grayscale() {
	std::cout << "File format is PBM and is already in grayscale format.\n";
}

void PBM::monochrome() {
	std::cout << "File format is PBM and the image is already monochrome!\n";
}

void PBM::negative() {
}