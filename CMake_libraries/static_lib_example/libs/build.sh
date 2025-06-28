# 1. compile src code
g++ -c -I./include source/logger.cpp -o logger.o
# 2. Archive the object file into a static librar
ar rcs liblogger.a logger.o