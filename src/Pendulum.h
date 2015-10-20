//
// Created by lise on 2015/10/9.
//

#ifndef PENDULUM_PENDULUM_H
#define PENDULUM_PENDULUM_H

#include <string>
using namespace std;


class Pendulum
{
public:
    Pendulum(double theta, double omega);
    void run(double tau, double maxTime, string type);
    void reset();

private:
    double theta0, omega0;
    double theta , omega , accel;
    double time;
    void run_euler(double tau, double maxTime);
    void run_verlet(double tau, double maxTime);
};



#endif //PENDULUM_PENDULUM_H