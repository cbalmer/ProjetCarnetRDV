#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    setlocale(LC_ALL,"");
    CarnetRDV* carnet = new CarnetRDV();

    if(!CarnetRDV::initialisation())
    {
        std::cerr << "Connexion à la base de données impossible.\n";
        return 1;
    }

    cli(carnet);

    return 0;
}
