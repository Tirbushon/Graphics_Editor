#pragma once
#include "Image.h"
#include "Session.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"
#include <sstream>

/* Commands class that enables a user to interact with the command prompt
*
  *	@param fileName = name of a file
  * @param sessions = a vector of sessions
  * @param currentSession = the session that the changes on images will be applied to
  * @param header = a variable to determine the format of a picture and construct the right one
*/
class Commands
{
private:
	std::string fileName;
	std::vector<Session> sessions;
	Session currentSession;
	std::string header = "";

	//function that sets the format of a header
	void readFormat(std::string);

public:
	//opens a file from cmd
	void open(const std::string&);
	
	//closes all the files and clears all sessions
	void close();

	//saves a particular file in the current session
	void save(std::string);

	//saves a particular file in the current session into a newly created one
	void saveas(std::string, std::string);

	//displays the commands that the programme supports
	void help();

	//exits the programme
	void exit();

	//converts all the images in the current session into grayscale
	void grayscale();

	//converts all the images in the current session into monochrome
	void monochrome();

	//converts all the images in the current session into negative
	void negative();

	//adds another file to the current session
	void add(const std::string&);

	//prints the current session's info
	void sessionInfo();

	//switches to another session
	void switchSession(std::string);

	//undoes the last change that was made on the files
	void undo();
};

