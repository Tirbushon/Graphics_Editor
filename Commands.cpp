#include "Commands.h"

void Commands::open(const std::string& _fileName) {
	std::fstream file(_fileName, std::ios::in | std::ios::binary);
	if (file.is_open()) {
		fileName = _fileName;
		std::cout << "Successfully opened " << fileName << '\n';
	}
	else {
		file.open(fileName, std::ios::out);
		file << "";
		std::cout << "File created successfully!\n";
	}
	std::cout << "Session with ID: " << currentSession.getID() << " started\n";
	readFormat(_fileName);
	Image* image = nullptr;
	if (header == "P1" || header == "P4") {
		image = new PBM(fileName);
	}
	else if (header == "P2" || header == "P5") {
		image = new PGM(fileName);
	}
	else if (header == "P3" || header == "P6") {
		image = new PPM(fileName);
	}
	currentSession.getImages().push_back(image);
	file.close();
}

void Commands::close() {
	for (Session s : sessions) {
		for (auto iptr : s.getImages()) {
			delete iptr;
		}
	}
	sessions.clear();
	std::cout << "Successfully closed " << fileName << '\n';
}

void Commands::help() {
	std::cout << "The following commands are supported:\n";
	std::cout << "open <file>												  opens <file>\n";
	std::cout << "close										  closes currently opened file\n";
	std::cout << "save										 saves the currently open file\n";
	std::cout << "saveas <file>					   saves the currently open file in <file>\n";
	std::cout << "help											   prints this information\n";
	std::cout << "exit													exists the program\n";
	std::cout << "monocrome									 converts a file to monochrome\n";
	std::cout << "grayscale									  converts a file to grayscale\n";
	std::cout << "negative									   converts a file to negative\n";
	std::cout << "rotate <direction>			rotates a picture in direction <direction>\n";
	std::cout << "undo							   undoes a previously made transformation\n";
	std::cout << "session info						  gives info about the current session\n";
	std::cout << "add <image>							 adds another image to the session\n";
	std::cout << "switch <id>							switches to a session with id <id>\n";
	std::cout << "collage <direction> <image1> <image2> <outimage>         	 saves the currently open file\n";

}

void Commands::exit() {
	for (Session s : sessions) {
		if (!s.getSaved()) {
			std::cout << "You have to save the pictures in session with id: " << s.getID() << "!\n";
			return;
		}
	}
	std::cout << "Exiting program...\n";
}

void Commands::switchSession(std::string _id) {
	if (std::stoi(_id) > sessions.size()) {
		std::cout << "Session with id " << _id << "doesn't exist!\n";
	}
	else {
		currentSession = sessions.at(std::stoi(_id) - 1);
		std::cout << "You switched to session with ID: " << _id << "!\n";
		sessionInfo();
	}
}

void Commands::sessionInfo() {
	currentSession.printSession();
}

void Commands::undo() {
	if (currentSession.getTransformations().size() == 0) {
		std::cout << "There aren't any transformations to be undone!\n";
	}
	else {
		currentSession.getTransformations().pop_back();
	}
}

void Commands::add(const std::string& _fileName) {
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		for (int j = 0; j < currentSession.getTransformations().size(); j++) {
			if (currentSession.getTransformations().at(j) == "grayscale") {
				currentSession.getImages().at(i)->grayscale();
			}
			else if (currentSession.getTransformations().at(j) == "monochrome") {
				currentSession.getImages().at(i)->monochrome();
			}
			else if (currentSession.getTransformations().at(j) == "negative") {
				currentSession.getImages().at(i)->negative();
			}
		}
	}

	currentSession.getTransformations().clear();
	open(_fileName);
}

void Commands::save(std::string _fileName) {
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		if (_fileName != currentSession.getImages().at(i)->getFileName()) {
			continue;
		}
		std::ofstream file(currentSession.getImages().at(i)->getFileName(), std::ofstream::out | std::ofstream::trunc);
		file << currentSession.getImages().at(i)->getFormat() << '\n'
			<< currentSession.getImages().at(i)->getWidth() << " " << currentSession.getImages().at(i)->getHeight() << '\n'
			<< currentSession.getImages().at(i)->getMaxValue() << '\n';
		if (currentSession.getImages().at(i)->getFormat() == "P1" ||
			currentSession.getImages().at(i)->getFormat() == "P2" ||
			currentSession.getImages().at(i)->getFormat() == "P3") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getWidth(); k++) {
					file << (unsigned)currentSession.getImages().at(i)->getPixels()[j][k] << ' ';
				}
			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P3") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getPpmWidth(); k++) {
					file << (unsigned)currentSession.getImages().at(i)->getPixels()[j][k] << ' ';
				}
			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P4" ||
			currentSession.getImages().at(i)->getFormat() == "P5" ||
			currentSession.getImages().at(i)->getFormat() == "P6") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getWidth(); k++) {
					file.write((char*)currentSession.getImages().at(i)->getPixels()[j][k],
						sizeof(currentSession.getImages().at(i)->getPixels()[j][k]));
				}
			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P6") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getPpmWidth(); k++) {
					file.write((char*)currentSession.getImages().at(i)->getPixels()[j][k],
						sizeof(currentSession.getImages().at(i)->getPixels()[j][k]));
					currentSession.setSaved(true);
				}
			}
		}
		currentSession.setSaved(true);
		for (int i = 0; i < currentSession.getImages().size(); i++) {
			std::cout << "Successfully saved file " << currentSession.getImages().at(i)->getFileName() << '\n';
		}
		file.close();
	}
}

void Commands::saveas(std::string oldFile, std::string newFile) {
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		if (oldFile != currentSession.getImages().at(i)->getFileName()) {
			continue;
		}
		std::ofstream file(newFile , std::ofstream::out | std::ofstream::trunc);
		file << currentSession.getImages().at(i)->getFormat() << '\n'
			<< currentSession.getImages().at(i)->getWidth() << " " << currentSession.getImages().at(i)->getHeight() << '\n'
			<< currentSession.getImages().at(i)->getMaxValue() << '\n';
		if (currentSession.getImages().at(i)->getFormat() == "P1" ||
			currentSession.getImages().at(i)->getFormat() == "P2") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getWidth(); k++) {
					file << (unsigned)currentSession.getImages().at(i)->getPixels()[j][k] << ' ';
				}

			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P3") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getPpmWidth(); k++) {
					file << (unsigned)currentSession.getImages().at(i)->getPixels()[j][k] << ' ';
				}

			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P4" ||
			currentSession.getImages().at(i)->getFormat() == "P5") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getWidth(); k++) {
					file.write((char*)&currentSession.getImages().at(i)->getPixels()[j][k], sizeof(currentSession.getImages().at(i)->getPixels()[j][k]));
				}
			}
		}
		if (currentSession.getImages().at(i)->getFormat() == "P6") {
			for (size_t j = 0; j < currentSession.getImages().at(i)->getHeight(); j++) {
				for (size_t k = 0; k < currentSession.getImages().at(i)->getPpmWidth(); k++) {
					file.write((char*)&currentSession.getImages().at(i)->getPixels()[j][k], sizeof(currentSession.getImages().at(i)->getPixels()[j][k]));
				}
			}
		}
		file.close();
	}
	currentSession.setSaved(true);
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		std::cout << "Successfully saved file " << currentSession.getImages().at(i)->getFileName() << " as " << newFile << '\n';
	}
}


void Commands::grayscale() {
	//delete for when at the final
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		currentSession.getImages().at(i)->grayscale();
	}
	currentSession.getTransformations().push_back("grayscale");
}

void Commands::monochrome() {
	//delete for when at the final
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		currentSession.getImages().at(i)->monochrome();
	}
	currentSession.getTransformations().push_back("monochrome");
}

void Commands::negative() {
	//delete for when at the final
	for (int i = 0; i < currentSession.getImages().size(); i++) {
		currentSession.getImages().at(i)->negative();
	}
	currentSession.getTransformations().push_back("negative");
}

void Commands::readFormat(std::string _fileName) {
	std::ifstream file(_fileName);
	if (file.is_open()) {
		char c;
		std::streampos pos = file.tellg();
		file.get(c);
		while (true) {
			if (c != '#') {
				file.seekg(pos);
				file >> header;
				break;
			}
		}
	}
}

