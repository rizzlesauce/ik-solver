#include "Utils.h"
#include "Debugger.h"
//#include <wait.h>
#include <string>
//#include <sys/sendfile.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <cerrno>

using namespace std;

Utils::Utils() {
}

Utils&
Utils::getInstance() {
	static Utils instance;

	return instance;
}

string
Utils::itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

string
Utils::ftos(float f) {
	stringstream ss;
	ss << f;
	return ss.str();
}

int
Utils::stoi(string s) {
	int i;
	stringstream ss;
	ss << s;
	if ((ss >> i).fail()) {
		Debugger::getInstance().throwMessage("invalid int: " + s);
	}
	return i;
}

float
Utils::stof(string s) {
	float f;
	stringstream ss;
	ss << s;
	if ((ss >> f).fail()) {
		Debugger::getInstance().throwMessage("invalid float: " + s);
	}
	return f;
}

string
Utils::date(time_t t) {
	struct tm *gmt;
	char buf[200];

	memset(buf, 0, 200);
	gmt = gmtime(&t);
	if (gmt == NULL) {
		return "";
	}
	
	if (strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", gmt) == 0) {
		return "";
	}

	return string(buf);
}
