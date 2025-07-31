#include "tsvparser.h"


readTSV::readTSV(int maxRows) : maxRows(maxRows), maxCols(3), cntRow(0) {
    datamatrix = new int*[maxRows];
    for (int i = 0; i < maxRows; ++i) {
        datamatrix[i] = new int[maxCols];
    }
}

readTSV::~readTSV() {
    for (int i = 0; i < maxRows; ++i) {
        delete[] datamatrix[i];
    }
    delete[] datamatrix;
}

bool readTSV::IsReadable(const char* filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    while (cntRow < maxRows && inputFile >> datamatrix[cntRow][0] >> datamatrix[cntRow][1] >> datamatrix[cntRow][2]) {
        cntRow++;
    }

    inputFile.close();
    return true;
}

int readTSV::getCntRow() const {
    return cntRow;
}

int** readTSV::getDataMatrix() const {
    return datamatrix;
}

void readTSV::PrintElems() const {
    for (int i = 0; i < cntRow; ++i) {
        std::cout << datamatrix[i][0] << "\t" << datamatrix[i][1] << "\t" << datamatrix[i][2] << std::endl;
    }
}

