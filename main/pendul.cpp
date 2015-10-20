#include <iostream>
#include "Pendulum.h"
using namespace std;

int main()
{
    double theta = 10;
    double omega = 0;
    double tau = 0.1;

    Pendulum pendulum = Pendulum(theta, omega);
    pendulum.run(0.1, 30, "euler");





    cout << "Hello, World!" << endl;
    return 0;
}