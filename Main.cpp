#include "Commands.h"

int main() {

	Commands file;
	std::string line = "";
	int first = 0;
 	while (std::getline(std::cin, line)) {
		std::string command;
		std::stringstream ss(line);
		std::getline(ss, command, ' ');
		if (command == "open") {
			std::getline(ss, command, ' ');
			file.open(command);
		}
		else if (command == "help") {
			file.help();
		}
		else if (command == "close") {
			file.close();
		}
		else if (command == "exit") {
			file.exit();
			break;
		}
		else if (command == "save") {
			std::getline(ss, command, ' ');
			file.save(command);
		}
		else if (command == "saveas") {
			std::getline(ss, command, ' ');
			std::string oldName = command;
			std::getline(ss, command, ' ');
			std::string newName = command;
			file.saveas(oldName, newName);
		}
		else if (command == "undo") {
			file.undo();
		}
		else if (command == "switch") {
			std::getline(ss, command, ' ');
			file.switchSession(command);
		}
		else if (command == "add") {
			std::getline(ss, command, ' ');
			file.add(command);
		}
		else if (command == "negative") {
			file.negative();
		}
		else if (command == "grayscale") {
			file.grayscale();
		}
		else if (command == "monochrome") {
			file.monochrome();
		}
		else if (command == "info") {
			file.sessionInfo();
		}
		else if (command == "load") {
			std::vector<std::string> files;
			std::string fileStr = "";
			while (std::getline(ss, fileStr, ' ')) {
				files.push_back(fileStr);
			}
			for (int i = 0; i < files.size(); i++) {
				file.add(files.at(i));
			}
		}
	}
	return 0;
}