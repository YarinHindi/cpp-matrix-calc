#include <vector>
#include <iostream>
using namespace std;
namespace zich{
    class Matrix {
    private:
        int row;
        int col;
        vector<double> mat;
    public:
        Matrix(vector<double> mat, int rows, int cols);

        bool operator==(Matrix const & mat);

        bool operator!=(Matrix const & mat);

        bool operator<(Matrix const & mat);

        void checkMatSize(Matrix const & mat);

        double getMatAt(int pos);

        void setMatAt(int pos,double value);

        int getRows();

        int getCols();

        bool operator>(Matrix  const & mat);

        bool operator<=(Matrix const & mat);

        bool operator>=(Matrix const & mat);

        Matrix operator+(const Matrix &);

        void operator++();

        void operator--();

        Matrix operator=(const Matrix &);

        Matrix operator*=(double num);

        Matrix operator*=(const Matrix &);

        Matrix operator+=(const Matrix &);

        Matrix operator-(const Matrix &);

        Matrix operator-();

        Matrix operator+();

        Matrix operator-=(const Matrix &);

        friend istream& operator>>(istream &in, Matrix &mat);

        friend ostream& operator<<(ostream &out,  Matrix const &mat);

        friend Matrix operator*(int num, Matrix mat);

        friend Matrix operator*(double num, Matrix mat);
    };
};