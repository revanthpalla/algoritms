#include "logger/logger.h"
#include <iostream>

void log_message(std::string& message){
    std::cout << "[EXTERNAL LIB]: " << message << std::endl;
} 