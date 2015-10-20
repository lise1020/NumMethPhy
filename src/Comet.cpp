#include "Comet.h"
using namespace std;

Comet::Comet(double r0, double v0)
{
    this->r0 = vec2({r0,0});
    this->v0 = vec2({0,v0});
    this->r = this->r0;
    this->v = this->v0;
}

void Comet::run(double tau, int nstep, std::string method)
{
    double GM = 4*M_PI*M_PI;
    vec2 a;

    if(method=="euler")
    {
        for(int i=0; i< nstep; i++)
        {
            a = -GM*r/pow(norm(r),3);
            r = r + tau*v;
            v = v + tau*a;
            printf("%f %f\n", r[0], r[1]);
        }
    }
    else if(method=="euler-cromer")
    {
        for(int i=0; i< nstep; i++)
        {
            a = -GM*r/pow(norm(r),3);
            v = v + tau*a;
            r = r + tau*v;
        }
    }
    else if(method=="rk4")
    {
        //
    }
    else if(method=="rka")
    {
        //
    }
    else
    {
        std::cerr << "Error method: " << method << endl;
    }

}

void Comet::reset()
{
    this->r = this->r0;
    this->v = this->v0;
}
