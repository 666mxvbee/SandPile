#include "argparser.h"

int toInt(char* chrArr){
    int intres = 0;

    while (*chrArr){
        intres = intres*10 + (*chrArr - '0');
        chrArr++;
    }
    return intres;
}

void parseArg(int argc, char* argv[], char*& inputFile, char*& outputFile, int& maxIter, int& freq){
    inputFile = nullptr;
    outputFile = nullptr;
    maxIter = 0;
    freq = 0;

    for (int i = 1; i<argc;++i){
        if (((strcmp(argv[i], "-i")==0) || (strcmp(argv[i],"--input")==0)) && (i+1)<argc){
            inputFile = new char[strlen(argv[i+1])+1];

            strcpy(inputFile, argv[i+1]);
        }

        if(((strcmp(argv[i],"-o")==0) || (strcmp(argv[i],"--output")==0)) && (i+1)<argc){
            outputFile = new char[strlen(argv[i+1])+1];

            strcpy(outputFile, argv[i+1]);
        }

        if((strcmp(argv[i],"-m")==0 || (strcmp(argv[i],"--max-iter")==0)) && (i+1)<argc){
            maxIter = toInt(argv[i+1]);
        }

        if((strcmp(argv[i],"-f")==0 || (strcmp(argv[i],"--freq")==0)) && (i+1)<argc){
            freq = toInt(argv[i+1]);
        }

    }
}
