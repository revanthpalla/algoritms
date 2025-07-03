#ifndef LOGGER_H
#define LOGGER_H

#ifdef WIN32
#ifdef BUILD_LOGGER
#define LOGGER_API __declspec(dllexport)
#else
#define LOGGER_API __declspec(dllimport)
#endif
#else
#define LOGGER_API 
#endif

// api to display
void LOGGER_API log_message(const char* msg);


#endif //LOGGER_H