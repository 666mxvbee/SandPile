#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    private:
        int **matrix;
        int rows;
        int cols;

        void Expand(int userRow, int userCol);
        void ExpandBottom();
        void ExpandTop();
        void ExpandRight();
        void ExpandLeft();

    public:
        Matrix();
        ~Matrix();

        void centredElem(int row, int col, int elem);
        void tryExplore();
        bool AllElemsLower();
        int& operator()(int row, int col);
        int RowsElem();
        int ColsElem();
        int** MatrixElems();
        void print();

};

#endif