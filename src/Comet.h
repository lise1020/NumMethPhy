//
// Created by lise on 2015/10/17.
//

#ifndef NUMMETHPHY_COMET_H
#define NUMMETHPHY_COMET_H


#include <armadillo>
using namespace arma;

class Comet
{
public:
    Comet(double r0, double v0);
    void reset();
    void run(double tau, int nstep, std::string method);

private:
    vec2 r0, v0;
    vec2 r , v ;
};


#endif //NUMMETHPHY_COMET_H
