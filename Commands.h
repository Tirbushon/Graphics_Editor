#pragma once
#include "Image.h"
#include "Session.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"
#include <sstream>

class Commands
{
private:
	std::string fileName;
	std::vector<Session> sessions;
	Session currentSession;
	std::string header = "";

	void readFormat(std::string);

public:
	void open(const std::string&);
	void close();
	void save(std::string);
	void saveas(std::string, std::string);
	void help();
	void exit();

	void grayscale();
	void monochrome();
	void negative();
	void add(const std::string&);
	void sessionInfo();
	void switchSession(std::string);
	void undo();

	//collage
};

