//
// Created by lise on 2015/10/9.
//

#ifndef PENDULUM_MATRIX_H
#define PENDULUM_MATRIX_H


class Matrix
{
public:

    // Create a 1x1 matrix, and set value to zeros.
    Matrix();
    
    // Create a nR by nC matrix, and set value to zeros.
    Matrix(int nR, int nC=1);

    // Create a matrix by coping.
    Matrix(const Matrix& mat);

    // Called when a Matrix object goes out of scope.
    ~Matrix();

    // Return the number of rows of columns.
    int nRow() const{ return _nRow; }
    int nCol() const{ return _nCol; }

    // Override this matrix by a given matrix.
    Matrix& operator=(const Matrix& mat);

    // Allow access to values of Matrix via (i,j) pair.
    double& operator()(int i, int j=1);

    // Parenthesis operator function (const version)
    const double& operator()(int i, int j=1) const;

    // Set all element of this matrix to a given value.
    void set(double value);

private:

    int _nRow, _nCol; // Number of rows, columns.
    double* _data;    // Pointer used to allocate memory for data.

    // Copy values from a given matrix to this.
    void copy(const Matrix& mat);
};


#endif //PENDULUM_MATRIX_H
