#ifndef BMPCREATOR_H
#define BMPCREATOR_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>  


const unsigned char colors[5][3] = {
    {255, 255, 255}, // 0 - белый
    {0, 255, 0},     // 1 - зеленый
    {128, 0, 128},   // 2 - фиолетовый
    {0,255,255},     // 3 - желтый
    {0, 0, 0}        // 4 - черный
};

class BMPImage {
    private:
        int width;
        int height;
        int** matrix;

    public:
        void createDirectory(const char* dirName);
        BMPImage(int w, int h);

        ~BMPImage();

        void createBMP(const char* outputdir,const char* filename);

        void setMatrix(int** newMatrix, int newHeight, int newWidth);
};


#endif