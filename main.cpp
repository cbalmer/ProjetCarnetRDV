#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    CarnetRDV* carnet = new CarnetRDV();

    carnet->ajouterPersonne("Camille","Balmer","0987675745","caca@caca.fr");
    carnet->ajouterPersonne("Nathan","Baumann","0330492834","pipi@caca.fr");
    carnet->creerRDV("RDV random",Date(29,3,2017),Horaire(18,00),Horaire(19,00));
    std::cout << carnet->AfficherRDV("RDV random");
     carnet->ajouterPersonneRDV("RDV random","Balmer","Camille");
     ListePersonne l = carnet->getlesPersonneDuRDV("RDV random");

    // std::cout << l.afficherListpersonne();
    //std::cout<<carnet->EstDispo("Balmer","Camille",Date(29,3,2017),Horaire(20,00),Horaire(21,00));
    //cli(carnet);

    return 0;
}
