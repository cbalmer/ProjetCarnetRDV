#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    CarnetRDV* carnet = new CarnetRDV();

    carnet->ajouterPersonne("Camille","Balmer","0987675745","caca@caca.fr");
    carnet->ajouterPersonne("Nathan","Baumann","0330492834","pipi@caca.fr");

    cli(carnet);

    return 0;
}
