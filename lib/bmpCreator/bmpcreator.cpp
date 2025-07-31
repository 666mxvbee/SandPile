#include "bmpcreator.h"

void BMPImage::createDirectory(const char* dirName){
    if (GetFileAttributesA(dirName)!=INVALID_FILE_ATTRIBUTES){
        RemoveDirectoryA(dirName);
    }
    CreateDirectoryA(dirName, NULL);
}

BMPImage::BMPImage(int w, int h) : width(w), height(h) {
    matrix = new int*[height];
    for (int i = 0; i < height; ++i) {
        matrix[i] = new int[width];
    }
}


BMPImage::~BMPImage() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void BMPImage::createBMP(const char* foldername,const char* filename) {
    char fullPath[256];
    std::strcpy(fullPath, foldername);
    std::strcat(fullPath, "/");
    
    if (std::strlen(filename) < 4 || std::strcmp(filename + std::strlen(filename) - 4, ".bmp") != 0) {
        std::strcat(fullPath, filename);
        std::strcat(fullPath, ".bmp");
    } else {
        std::strcat(fullPath, filename);
    }


    const int padding = (4 - (width * 3) % 4) % 4;
    const int fileSize = 54 + (3 * width + padding) * height;

    unsigned char bmpFileHeader[14] = {
        'B', 'M', // Signature
        fileSize & 0xFF, (fileSize >> 8) & 0xFF, (fileSize >> 16) & 0xFF, (fileSize >> 24) & 0xFF, // File size
        0, 0, 0, 0, // Reserved
        54, 0, 0, 0 // Offset to pixel data
    };

    unsigned char bmpInfoHeader[40] = {
        40, 0, 0, 0, // Header size
        width & 0xFF, (width >> 8) & 0xFF, (width >> 16) & 0xFF, (width >> 24) & 0xFF, // Width
        height & 0xFF, (height >> 8) & 0xFF, (height >> 16) & 0xFF, (height >> 24) & 0xFF, // Height
        1, 0, // Planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression
        (3 * width * height + padding * height) & 0xFF, // Image size
        0, 0, 0, 0, // X pixels per meter
        0, 0, 0, 0, // Y pixels per meter
        0, 0, 0, 0, // Total colors
        0, 0, 0, 0  // Important colors
    };

    std::ofstream file(fullPath, std::ios::binary);
    if (!file) {
        std::cerr<<"Error in opening for writing"<<fullPath<<std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(bmpFileHeader), sizeof(bmpFileHeader));
    file.write(reinterpret_cast<const char*>(bmpInfoHeader), sizeof(bmpInfoHeader));

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            if (matrix[y][x]>3){
                int colorIndex = 4;
                file.write(reinterpret_cast<const char*>(colors[colorIndex]),3);
            }
            else{
                int colorIndex = matrix[y][x];
                file.write(reinterpret_cast<const char*>(colors[colorIndex]), 3);
            }
        }

        for (int p = 0; p < padding; ++p) {
            file.put(0);
        }
    }

    file.close();
}


void BMPImage::setMatrix(int** newMatrix, int newHeight, int newWidth){
    for (int i = 0;i<height;++i){
        delete[] matrix[i];
    }
    delete[] matrix;

    height = newHeight;
    width = newWidth;
    matrix = new int*[height];
    for (int i = 0; i<height;++i){
        matrix[i] = new int[width];
    }

    for (int i = 0; i<height;++i){
        for (int j = 0;j<width;++j){
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

