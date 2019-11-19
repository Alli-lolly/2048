#include "ready_to_pop.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>

int randomNumber()    // get a random number among 2, 4, 8
{
    srand (time(NULL)*2);
    int choose = rand()%3;
    int pop;
    if (choose == 0)
        pop = 8;
    else if (choose == 1)
        pop = 4;
    else
        pop = 2;
    return pop;
}

int randomPosition(unsigned int placeHasNotChosen)
{
    srand (time(NULL));
    int placeChosen = rand() % placeHasNotChosen;
    return placeChosen;
}
