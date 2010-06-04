#include "FileLogger.h"
#include "Utils.h"
//#include <sys/time.h>
#include <string>
//#include <semaphore.h>
#include <iostream>
#include <fstream>

using namespace std;

FileLogger::FileLogger(string filename) {
	setFileName(filename);
}

FileLogger::FileLogger() {
}

void FileLogger::setFileName(string fileName) {
	_filename = fileName;
	//sem_init(&_fileAccess, 0, 1);
}

FileLogger::~FileLogger() {
	//sem_destroy(&_fileAccess);
}

int
FileLogger::log(string message) {
	int result = 0;

	//sem_wait(&_fileAccess);

	// Wait our turn before getting the current time to avoid
	// misordering of times
	//struct timeval time;
	//if (gettimeofday(&time, NULL) == -1) {
		//result = -1;
	//} else {
		ofstream logFile;
		logFile.open(_filename.c_str(), ios::out | ios::app);
		//logFile << time.tv_sec << ":" << time.tv_usec;
		//logFile << " ";
		logFile << message << endl;
		logFile.close();
	//}

	//sem_post(&_fileAccess);
	return result;
}
