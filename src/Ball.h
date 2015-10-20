//
// Created by lise on 2015/10/9.
//

#ifndef BALLE_BALL_H
#define BALLE_BALL_H


#include <armadillo>
#include <cstdio>
#include <string>
using namespace std;
using namespace arma;
const double pi = 3.141592654;
const vec2 grav({0, -9.81});



class Ball
{
public:
    Ball(double height, double speed, double angle);
    void reset();
    void run(double tau, string type);

private:
    vec2 r , v , a ;
    vec2 r0, v0, a0;
    void run_theory(double tau);
    void run_euler(double tau);
    void run_euler_cromer(double tau);
    void run_midpoint(double tau);
};



#endif //BALLE_BALL_H
