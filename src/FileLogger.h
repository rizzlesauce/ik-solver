#ifndef FileLogger_h
#define FileLogger_h

//#include <semaphore.h>
#include <string>

class FileLogger {
	public:
	FileLogger(std::string);
	FileLogger();
	void setFileName(std::string);
	~FileLogger();
	int log(std::string);

	protected:
	std::string _filename;
	//sem_t _fileAccess;
};

#endif
