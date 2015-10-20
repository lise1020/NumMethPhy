#include <iostream>
#include "Comet.h"
using namespace std;


int main()
{
    Comet comet = Comet(1, 2*M_PI);
    comet.run(0.02, 200, "euler");

    comet.reset();
    comet.run(0.02, 200, "euler-cromer");

    return 0;
}


