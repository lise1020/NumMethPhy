//
// Created by lise on 2015/10/9.
//

#include <assert.h>
#include "Matrix.h"

Matrix::Matrix()
{
    _nRow = 1;
    _nCol = 1;
    _data = new double[1];
    set(0.0);
}

Matrix::Matrix(int nR, int nC)
{
    assert(nR>0 && nC>0);
    _nRow = nR;
    _nCol = nC;
    _data = new double[nR*nC];
    assert(_data != nullptr);
    set(0.0);
}

Matrix::Matrix(const Matrix &mat)
{
    this->copy(mat);
}

Matrix::~Matrix()
{
    delete []_data;
}

Matrix &Matrix::operator=(const Matrix &mat)
{
    if(this == &mat) return *this;
    delete[] _data;
    this->copy(mat);
    return *this;
}

double &Matrix::operator()(int i, int j)
{
    assert(i>0 && i<=_nRow);
    assert(j>0 && j<=_nRow);
    return _data[ _nCol*(i-1)+ (j-1) ];
}

const double &Matrix::operator()(int i, int j) const
{
    assert(i>0 && i<=_nRow);
    assert(j>0 && j<=_nRow);
    return _data[ _nCol*(i-1)+ (j-1) ];
}

void Matrix::set(double value)
{
    for(int i=0; i<_nRow*_nCol; i++)
    {
        _data[i] = value;
    }
}

void Matrix::copy(const Matrix &mat)
{
    _nRow = mat._nRow;
    _nCol = mat._nCol;
    _data = new double[_nRow*_nCol];

    for(int i=0; i<_nRow*_nCol; i++)
    {
        _data[i] = mat._data[i];
    }
}
