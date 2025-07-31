#include "..\lib\SandMatrix\matrix.h"  
#include "..\lib\ArgParser\argparser.h"
#include "..\lib\TsvParser\tsvparser.h"
#include "..\lib\bmpCreator\bmpcreator.h"


char* inttoStr(int num){
    static char buffer[20];
    int indx = 19;
    if (num==0){
        buffer[indx--] = '0';
    }

    while (num>0){
        buffer[indx--] = (num%10) + '0';
        num/=10;
    }
    return &buffer[indx+1];
}


int main(int argc, char* argv[]){
    int cnt = 0;
    
    //argparser
    char* inputFile = nullptr;
    char* outputFile = nullptr;
    int maxIter = 0;
    int freq = 0;

    parseArg(argc,argv,inputFile,outputFile,maxIter,freq);

    const int maxRows = 100;
    readTSV reading(maxRows);
    if (reading.IsReadable(inputFile)){
        int rowCnt = reading.getCntRow();
            //start work with sand matrix
            Matrix matrix;
            for (int i =0;i<rowCnt;++i){
            matrix.centredElem(reading.getDataMatrix()[i][0],
                               reading.getDataMatrix()[i][1],
                               reading.getDataMatrix()[i][2]);
            }

            for (int i = 0; i<matrix.RowsElem();++i){
                for (int j = 0;j<matrix.ColsElem(); ++j){
                    if (matrix(i,j)>3){

                        matrix.tryExplore();
                        for (int i = 1; i<matrix.RowsElem()-1;++i){
                            for (int j = 1; j<matrix.ColsElem()-1;++j){
                                if (matrix(i,j)>3){
                                    matrix(i+1,j)+=1;
                                    matrix(i-1,j)+=1;
                                    matrix(i,j+1)+=1;
                                    matrix(i,j-1)+=1;
                                    matrix(i,j)-=4;
                                }
                            }
                        }
                    
                    if ((freq!=0) && (cnt%freq==0)){
                        BMPImage BMPcreate(matrix.ColsElem(),matrix.RowsElem());
                        int** MatrixDataElems = matrix.MatrixElems();
                        BMPcreate.createDirectory(outputFile);
                        BMPcreate.setMatrix(MatrixDataElems,matrix.RowsElem(),matrix.ColsElem());
                        char* strcntfreq = nullptr;
                        strcntfreq = inttoStr(cnt);
                        BMPcreate.createBMP(outputFile,strcntfreq);
                    }


                    cnt++;
                    if (cnt==maxIter){
                        goto spawn_point;
                    }
                    i = 0;
                    j = 0;

                    }
                }
            }
            spawn_point:
            matrix.print();

            std::cout<<"COUNT OF ITERATIONS IS "<<cnt;
    BMPImage BMPcreate(matrix.ColsElem(),matrix.RowsElem());
    int** MaxtrixDataElems = matrix.MatrixElems();
    BMPcreate.createDirectory(outputFile);
    BMPcreate.setMatrix(MaxtrixDataElems,matrix.RowsElem(),matrix.ColsElem());
    char* strcnt = inttoStr(cnt);
    BMPcreate.createBMP(outputFile,"final");
                
    }
        
}
