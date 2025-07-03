#include "logger.h"
#include <iostream>

void LOGGER_API log_message(const char* msg){
    std::cout << "[External lib]:: " << msg << std::endl; 
} 