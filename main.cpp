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
    carnet->ajouterPersonne("Camille","Balmer","0","0");
    carnet->creerRDV("YOLO",Date(30,3,2017),Horaire(12,45));
    carnet->ajouterPersonneRDV("YOLO","Balmer","Camille");
   cli(carnet);
    return 0;
}
