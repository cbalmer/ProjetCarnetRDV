#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    setlocale(LC_ALL,"");
    CarnetRDV* carnet = new CarnetRDV();
    CarnetRDV::initialisation();

    cli(carnet);

    return 0;
}
