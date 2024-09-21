/**
 * Authors: Ammar AbdElaal AbdElHameed - Mohammed Elsayed - Mohammed Shalaby.
 * IDs: 202301708 - 202300734 - 202300967
 * Task: Elevator simulation.
 * Description: Design a program that interprets the action of an elevator.
 * Date: 18/5/2024
*/

#include <iostream>
#include <string>
#include "Elevator.h"

Elevator E;
int Elevator::minFloor = 0;

int main()
{    
    E.setMaxFloor();
    E.setMaxCapacity();
    while(1 == 1)
    {
    
    E.move();

    }
    return 0;
}

