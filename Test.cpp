#include "doctest.h"
#include "Matrix.hpp"
#include <ctime>
#include <ostream>
using namespace zich;
using namespace std;

TEST_CASE("Test Matrix constructor and methods on valid matrix for small matrix"){
    vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix matrix1(vec1,3,4);
    Matrix matrix2(vec1,4,3);
    CHECK_THROWS(matrix1*matrix1);
    Matrix matrix3 = -matrix2;
    CHECK_THROWS(matrix1+matrix2);
    CHECK_THROWS(bool ans = (matrix1==matrix2));
    CHECK_NOTHROW(3.7*matrix1);
    CHECK_NOTHROW(matrix1+matrix1+matrix1);
    Matrix matrix4 = matrix3+matrix2;
    for (int i = 0; i < 12; ++i) {
        CHECK(matrix4.getMatAt(i)==0);
        CHECK(3.5*matrix1.getMatAt(i)==3.5);
        CHECK(-3.5*matrix4.getMatAt(i)==0);
    }
    CHECK_NOTHROW(++matrix1);


}
TEST_CASE("generate bigger matrix and test out put"){
    srand(time(0));
    vector<double> vec2;
    vector<int> dvided;
    int counter = 0;
    int size;
    bool end = false;
    for (int i=0; i<1000;i++){
         size = 1+rand()%1000;
        counter = 0;
        for (int j = 0; j < size; ++j) {
            vec2.push_back(rand() % 10000 - rand() % 10000);
            if (j > 0) {
                if (size % j == 0) {
                    int div = size / j;
                    dvided.push_back(div);
                    counter++;
                }
            }
        }
        if(counter>0){
            int pos = rand()%counter;
            unsigned int rpos = (unsigned int)(pos);
            int rows = dvided.at(rpos);
            int cols = size / rows;
            Matrix bigmat(vec2, rows, cols);;
            Matrix bigmat2 = bigmat+bigmat;
            bool equ = (bigmat2==2*bigmat);
            CHECK_NOTHROW(-bigmat);
            CHECK_NOTHROW(bigmat+bigmat);
            CHECK(equ== true);
            vec2.clear();
            dvided.clear();
        }

    }
}

TEST_CASE("multiply  matrix and more operators check"){
    vector<double> unitMulBy2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix unitMatrixMulBy2(unitMulBy2,3,3);
    int byTwo =2;
    for (int i = 0; i <15; ++i) {
        CHECK_NOTHROW(cout<<unitMatrixMulBy2<<endl);
        bool bol =unitMatrixMulBy2*unitMatrixMulBy2==byTwo*unitMatrixMulBy2;
        CHECK(bol==true);
        CHECK_NOTHROW(unitMatrixMulBy2*=2);
        byTwo*=2;
    }
    Matrix rowVector(unitMulBy2,9,1);
    Matrix colVector(unitMulBy2,1,9);
        CHECK_NOTHROW(rowVector*colVector);
        CHECK_NOTHROW(colVector*rowVector);
        CHECK_NOTHROW(++rowVector);
        CHECK_THROWS(bool bol1 =rowVector<colVector);
        CHECK_THROWS(bool bol2 =rowVector<colVector);
        CHECK_THROWS(bool bol3 =rowVector<=colVector);
        CHECK_THROWS(bool bol4 =rowVector>=colVector);
        CHECK_THROWS(bool bol5 =rowVector==colVector);



}
