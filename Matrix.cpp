//
// Created by yarin on 3/30/2022.
//
#include "Matrix.hpp"
using namespace std;
using namespace zich;
Matrix::Matrix(vector<double> mat,int row,int col){
        this->mat = mat;
        this->row = row;
        this->col = col;
}

int Matrix::getRows() {
    return this->row;
}
int Matrix::getCols() {
    return this->col;
}
double Matrix::getMatAt(int pos) {
    if(pos<0||pos> this->col*this->row){
        throw std::invalid_argument("index out of range");
    }
    unsigned int position = (unsigned int)(pos);
    return this->mat.at(position);
}
void Matrix::checkMatSize(Matrix const & mat){
    if(mat.col!=this->col||mat.row!=this->row){
        throw std::invalid_argument("matrix should be in same size");
    }
}
bool Matrix::operator>=(const Matrix &mat) {
    Matrix::checkMatSize(mat);
    double sum1 =0;
    double sum2 =0;
    for (int i = 0; i <  mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        sum1+= this->mat.at(pos);
        sum2+= mat.mat.at(pos);
    }
    bool less = sum1>sum2;
    return (Matrix::operator==(mat)||less);
}
bool Matrix::operator>(const Matrix &mat) {
    Matrix::checkMatSize(mat);
    return (!(Matrix::operator==(mat))&&Matrix::operator>=(mat));
}
bool Matrix::operator<(const Matrix &mat) {
    Matrix::checkMatSize(mat);
    return (!(Matrix::operator==(mat))&&Matrix::operator<=(mat));
}

bool Matrix::operator<=(const Matrix &mat) {
    Matrix::checkMatSize(mat);
    double sum1 =0;
    double sum2 =0;
    for (int i = 0; i <  mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        sum1+= this->mat.at(pos);
        sum2+= mat.mat.at(pos);
    }
    bool less = sum1<sum2;
    return (Matrix::operator==(mat)||less);
}
bool Matrix::operator==(const Matrix &mat) {
        Matrix::checkMatSize(mat);
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(mat.mat.at(pos)!=this->mat.at(pos)){
            return false;
        }
    }
    return true;
}
bool Matrix::operator!=(const Matrix &mat) {
    Matrix::checkMatSize(mat);
    return !(Matrix::operator==(mat));
}
Matrix Matrix::operator*=(double num){
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(this->mat.at(pos)!=0) {
            this->mat.at(pos) *= num;
        }
    }
    return (*this);
}
void Matrix::operator++(){
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
            this->mat.at(pos)++;
    }

}
void Matrix::operator--(){
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        this->mat.at(pos)--;
    }

}
Matrix zich::operator*(int num,Matrix matrix){
    for(int i=0;i<matrix.col*matrix.row;i++){
        unsigned int pos = (unsigned int)(i);
        matrix.mat.at(pos)*=num;
    }
    return matrix;
}
Matrix zich::operator*(double num,Matrix matrix){
    for(int i=0;i<matrix.col*matrix.row;i++){
        unsigned int pos = (unsigned int)(i);
        matrix.mat.at(pos)*=num;
    }
    return matrix;
}

Matrix Matrix::operator-(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    Matrix result(this->mat,this->row,this->col);
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        result.mat.at(pos)-=mat.mat.at(pos);
    }
    return result;
}
Matrix Matrix::operator-=(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        this->mat.at(pos)-=mat.mat.at(pos);
    }
    return (*this);
}
Matrix Matrix::operator+=(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        this->mat.at(pos)+=mat.mat.at(pos);
    }
    return (*this);
}
Matrix Matrix::operator-() {
    Matrix result(this->mat,this->row, this->col);
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(result.mat.at(pos)!=0) {
            result.mat.at(pos) *= -1;
        }
    }
    return result;
}
Matrix Matrix::operator+() {
    return (*this);
}
Matrix Matrix::operator=(const Matrix & mat) {
    this->row = mat.row;
    this->col = mat.col;
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        this->mat.at(pos)=mat.mat.at(pos);
    }
    return (*this);
}
Matrix Matrix::operator+(Matrix const & mat) {
    if(mat.col!=this->col||mat.row!=this->row){
        throw std::invalid_argument("matrix should be in same size");
    }
    Matrix result(mat.mat,mat.row,mat.col);
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        result.mat.at(pos)+=this->mat.at(pos);
    }
    return result;
}

istream& zich::operator >>(istream& in,Matrix &mat){
    return in;
}
ostream& zich::operator <<(ostream& out,  Matrix const &mat){
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        if(i%mat.col==0){
            out<<"["<<mat.mat.at(pos)<<" ";
        }else{
        if((i+1)%mat.col==0) {
            out << mat.mat.at(pos) << "]" << endl;
        }else{
            out <<mat.mat.at(pos)<<" ";
        }
        }

    }
    return out;
}
