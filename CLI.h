#ifdef WIN32
    #define CLEAR() system("cls")
#else
    #define CLEAR() system("clear")
#endif // WIN32

#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>
#include <sstream>

#include "CarnetRDV.h"

void cli(CarnetRDV* carnet);

#endif
