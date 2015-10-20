//
// Created by lise on 2015/10/10.
//

#include <armadillo>
using namespace arma;

void fnewt(mat x, mat a, mat& f, mat& D)
{
    f[0] = a[1]*(x[1]-x[0]);
    f[1] = a[0]*x[0] - x[1] - x[0]*x[2];
    f[2] = x[0]*x[1] - a[2]*x[2];

    D[0,0] = -a[1];
    D[0,1] = a[0]-x[2];
    D[0,2] = x[1];
    D[1,0] = a[1];
    D[1,1] = -1;
    D[1,2] = x[0];
    D[2,0] = 0;
    D[2,1] = -x[0];
    D[2,2] = -a[2];
}
