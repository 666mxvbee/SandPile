#include "matrix.h"

void Matrix::Expand(int userRow, int userCol){
    int newRows = std::max(userRow+1,rows);
    int newCols = std::max(userCol+1,cols);

    //new matrix
    int** newMatrix = new int*[newRows];
    for (int i = 0; i<newRows; ++i){
        newMatrix[i] = new int[newCols]{0};
    }

    //copy from the prev matrix
    for (int i = 0; i<rows;++i){
        for (int j = 0; j<cols;++j){
            newMatrix[i][j] = matrix[i][j];
        }
    }

    //delete the prev matrix
    for (int i =0; i<rows;++i){
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newMatrix;
    rows = newRows;
    cols = newCols;
}


void Matrix::ExpandBottom(){
    int** newMatrix = new int*[rows+1];
    for (int indx = 0; indx<rows+1;++indx){
        newMatrix[indx] = new int[cols]{0};
    }

    for (int r = 0; r<rows;++r){
        for (int c=0;c<cols;++c){
            newMatrix[r][c] = matrix[r][c];
        }
    }
    for (int r = 0; r<rows;++r){
        delete[] matrix[r];
    }
    delete[] matrix;

    matrix = newMatrix;
    rows = rows+1;
}


void Matrix::ExpandTop(){
    int **newMatrix = new int*[rows+1];
    for (int indx = 0; indx<rows+1;++indx){
        newMatrix[indx] = new int[cols]{0};
    }

    for (int r = 0;r<rows;++r){
        for (int c=0; c<cols;++c){
            newMatrix[r+1][c] = matrix[r][c];
        }
    }
    for (int r =0 ;r<rows;++r){
        delete[] matrix[r];
    }
    delete[] matrix;

    matrix = newMatrix;
    rows = rows+1;
}


void Matrix::ExpandRight(){
    int** newMatrix = new int*[rows];
    for (int indx = 0; indx<rows;++indx){
        newMatrix[indx] = new int[cols+1]{0};
    }

    for (int r= 0; r<rows;++r){
        for (int c=0 ;c<cols;++c){
            newMatrix[r][c] = matrix[r][c];
        }
    }
    for (int r =0;r<rows;++r){
        delete[] matrix[r];
    }
    delete[] matrix;

    matrix = newMatrix;
    cols = cols+1;
}


void Matrix::ExpandLeft(){
    int** newMatrix = new int*[rows];
    for (int indx = 0; indx<rows;++indx){
        newMatrix[indx] = new int[cols+1]{0};
    }

    for (int r = 0;r<rows;++r){
        for (int c = 0;c<cols;++c){
            newMatrix[r][c+1] = matrix[r][c];
        }
    }
    for (int r =0; r<rows;++r){
        delete[] matrix[r];
    }
    delete[] matrix;

    matrix = newMatrix;
    cols = cols+1;
}


Matrix::Matrix() : rows(1),cols(1) {
    matrix = new int*[rows];
    for (int i = 0; i<rows;++i){
        matrix[i] = new int[cols]{0};
    }
}


Matrix::~Matrix() {
    for (int i =0 ;i<rows;++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}


void Matrix::centredElem(int row, int col, int elem){
    if (row>=rows || col>=cols){
        Expand(row,col);
    }
    matrix[row][col] = elem;
}


void Matrix::tryExplore(){
    for (int i = 0; i<cols;++i){
        if (matrix[rows-1][i]>3){
            ExpandBottom();
            break;
        }
    }
    for (int i = 0;i<cols;++i){
        if (matrix[0][i]>3){
            ExpandTop();
            break;
        }
    }

    for (int i = 0;i<rows;++i){
        if (matrix[i][cols-1]>3){
            ExpandRight();
            break;
        }
    }
    for (int i = 0;i<rows;++i){
        if (matrix[i][0]>3){
            ExpandLeft();
            break;
        }
    }
}


bool Matrix::AllElemsLower(){
    for (int i = 0; i<rows;++i){
        for (int j = 0; j<cols;++j){
            if (matrix[i][j]>3){
                return false;
            }
        }
    }
    return true;
}


int& Matrix::operator()(int row, int col){
    return matrix[row][col];
}


int Matrix::RowsElem() {
    return rows;
}


int Matrix::ColsElem() {
    return cols;
}

int** Matrix::MatrixElems() {
    return matrix;
}

void Matrix::print() {
    for (int i = 0; i<rows;++i){
        for (int j = 0; j<cols;++j){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

