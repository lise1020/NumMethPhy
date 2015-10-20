//
// Created by lise on 2015/10/17.
//

#include "Comet.h"

Comet::Comet(double r0, double v0)
{
    this->r0 = vec2({r0,0});
    this->v0 = vec2({0,v0});

    r = this->r0;
    //v = v0;
}

void Comet::run(double tau, int nstep, std::string method)
{
    double GM = 4*M_PI*M_PI;
    vec2 a;

    //a = -GM*r/pow(norm(r),3);
    //r = r + tau*v;
    //v = v + tau*a;
}
