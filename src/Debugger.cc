#include <cstdio>
#include <string>
#include <iostream>
#include "Debugger.h"
#include "FileLogger.h"

using namespace std;

Debugger::Debugger() {
    enabled_ = true;

    logger.setFileName("messages.log");
}

Debugger&
Debugger::getInstance() {
    static Debugger instance;

    return instance;
}

void
Debugger::setEnabled(bool enabled) {
    enabled_ = enabled;
}

bool
Debugger::isEnabled() {
    return enabled_;
}

void
Debugger::print(string message) {
    if (enabled_) {
        cout << message << endl;
        fflush(stdout);

        //logger.log(message);
    }
}

void
Debugger::throwMessage(string message) {
    this->print(message);
    throw message;
}
