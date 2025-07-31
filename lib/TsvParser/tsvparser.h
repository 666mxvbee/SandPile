#ifndef TSVPARSER_H
#define TSVPARSER_Hts

#include <iostream>
#include <fstream>  

class readTSV {
private:
    int** datamatrix; 
    int cntRow;       
    int maxRows;      
    const int maxCols;

public:

    readTSV(int maxRows);


    ~readTSV();


    bool IsReadable(const char* filename);


    int getCntRow() const;

    int** getDataMatrix() const;


    void PrintElems() const;
};

#endif 
