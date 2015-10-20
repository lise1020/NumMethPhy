//
// Created by lise on 2015/10/17.
//
#include <iostream>
#include "Comet.h"
using namespace std;


int main()
{
    Comet comet = Comet(1, 2*M_PI);
    comet.run(0.02, 200, "euler");




    cout << "LISE" << endl;
    return 0;
}