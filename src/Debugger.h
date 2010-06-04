#ifndef Debugger_h
#define Debugger_h

#include <string>
#include "FileLogger.h"

/**
 * Debugger
 *
 * This class handles debugging messages and options for the program. It is a singleton
 */
class Debugger {
    public:
    /**
     * Get the only instance of this class
     */
    static Debugger& getInstance();
    bool isEnabled();
    void setEnabled(bool = true);
    void print(std::string);
	void throwMessage(std::string);

    private:
    Debugger();

    FileLogger logger;

    protected:
    bool enabled_;
};

#endif
