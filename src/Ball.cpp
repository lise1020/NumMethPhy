//
// Created by lise on 2015/10/9.
//

#include "Ball.h"


Ball::Ball(double height, double speed, double angle)
{
    r0[0] = 0;
    r0[1] = height;
    v0[0] = speed*cos( angle*pi/180 );
    v0[1] = speed*sin( angle*pi/180 );

    r = r0;
    v = v0;
}



void Ball::reset()
{
    r = r0;
    v = v0;
    a = a0;
}



void Ball::run(double tau, string type)
{
    if(type=="theory")
    {
        run_theory(tau);
    }
    else if(type=="euler")
    {
        run_euler(tau);
    }
    else if(type=="euler_cromer")
    {
        run_euler_cromer(tau);
    }
    else if(type=="midpoint")
    {
        run_midpoint(tau);
    }
    else
    {
        cerr << "Error run type: " << type << endl;
    }
}



void Ball::run_theory(double tau)
{
    double t;
    for(int i=0; i<1000; i++)
    {
        t = tau*i;
        r = r0 + v0*t + 0.5*grav*t*t;

        printf("%f %f\n", r[0], r[1]);
        if(r[1] < 0) break;
    }
}



void Ball::run_euler(double tau)
{
    for(int i=0; i<1000; i++)
    {
        a = grav;
        r = r + tau*v;
        v = v + tau*a;

        printf("%f %f\n", r[0], r[1]);
        if(r[1] < 0) break;
    }
}



void Ball::run_euler_cromer(double tau)
{
    for(int i=0; i<1000; i++)
    {
        a = grav;
        v = v + tau*a;
        r = r + tau*v;

        printf("%f %f\n", r[0], r[1]);
        if(r[1] < 0) break;
    }
}



void Ball::run_midpoint(double tau)
{
    for(int i=0; i<1000; i++)
    {
        vec2 v0 = v;
        a = grav;
        v = v + tau*a;
        r = r + tau*(v+v0)/2;

        printf("%f %f\n", r[0], r[1]);
        if(r[1] < 0) break;
    }
}