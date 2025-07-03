#include "logger.h"
#include <iostream>

void LOGGER_API log_message(const char* msg) {
    std::cout << "[External Lib]: " << msg << std::endl;
}