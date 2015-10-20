//
// Created by lise on 2015/10/10.
//

#include <armadillo>

using namespace arma;

void fnewt(mat x, mat a, mat& f, mat& D);
void ge(mat a, mat b, mat& x);

int main()
{
    /*Matrix initPos(3+1);
    initPos(1,1) = 50;
    initPos(2,1) = 50;
    initPos(3,1) = 50;

    Matrix a(3+1);
    a(1,1) = 28;
    a(2,1) = 10;
    a(3,1) = (double)8/3;*/

    mat x = mat({50, 50, 50});
    mat a = mat({28, 10, (double)8/3});
    mat f = mat(3, 1, fill::zeros);
    mat D = mat(3, 3, fill::zeros);
    mat dx = mat(3, 1, fill::zeros);

    for(int i=0; i<10; i++)
    {
        fnewt(x, a, f, D);
        D.t();
        ge(D,f,dx);
        x = x - dx;
    }

    cout << x << endl;

    return 0;
}