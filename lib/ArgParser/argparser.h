#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <iostream>
#include <cstring>

int toInt(char* chrArr);

void parseArg(int argc, char* argv[], char*& inputFile, char*& outputFile, int& maxIter, int& freq);

#endif
