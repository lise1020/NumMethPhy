//
// Created by lise on 2015/10/10.
//

#include <armadillo>
#include <assert.h>

using namespace arma;

/**
 * ge   -   Function to perform Gaussion elemination to solve A*x = b
 *          using scaled column pivoting
 *
 * Inputs
 *  A   -   Matrix A (NxN)
 *  b   -   Vector b (Nx1)
 *
 * Outputs
 *  x   -   Vector x (Nx1)
 *  det -   Determinate of matrix A
 */
void ge(mat A, mat b, mat& x)
{
    int N = A.n_rows;
    assert( N==A.n_cols && N==b.n_rows && N==x.n_rows);

    // Set scale factor, scale[i] = max( |A[i,j]| ), for each row
    for(int i=0; i<N; i++)
    {

    }
}