//
// Created by lise on 2015/10/9.
//

#include <iostream>
#include <cmath>
#include "Pendulum.h"

Pendulum::Pendulum(double theta, double omega)
{
    this->theta0 = theta*M_PI/180;
    this->omega0 = omega;
    this->theta = this->theta0;
    this->omega = this->omega0;
    this->time = 0;
}

void Pendulum::reset()
{
    theta = theta0;
    omega = omega0;
    time = 0;
}

void Pendulum::run(double tau, double maxTime, string type)
{
    if(type=="theory")
    {
        //
    }
    else if(type=="euler")
    {
        run_euler(tau, maxTime);
    }
    else if(type=="verlet")
    {
        //
    }
    else
    {
        cerr << "Unknown type: " << type << endl;
    }
}

void Pendulum::run_euler(double tau, double maxTime)
{
    for(int i=0; time<maxTime; i++)
    {
        time += tau;

        accel = -1.0*sin(theta);
        theta = theta + tau*omega;
        omega = omega + tau*accel;
        printf("%f %f\n", time, theta*180/M_PI);
    }
}
