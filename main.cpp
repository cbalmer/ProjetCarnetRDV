#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    CarnetRDV* carnet = new CarnetRDV();

    carnet->ajouterPersonne("Camille","Balmer","0987675745","caca@caca.fr");
    carnet->ajouterPersonne("Nathan","Baumann","0330492834","pipi@caca.fr");
//    std::cout<<carnet->supprimerPersonne("Camille","Balmer");
   // carnet->creerRDV("RDV random",Date(29,3,2017),Horaire(18,00),Horaire(19,00));
//    std::cout << carnet->AfficherRDV("RDV random");
//     carnet->ajouterPersonneRDV("RDV random","Balmer","Camille");
//     ListePersonne l(carnet->getlesPersonneDuRDV("RDV random"));
//
//    std::cout << l.afficherListpersonne();
//    std::cout<<carnet->EstDispo("Balmer","Camille",Date(29,3,2017),Horaire(16,00),Horaire(18,00));
//    carnet->supprimerPersonneRDV("RDV random","Balmer","Camille");
//     ListePersonne l2(carnet->getlesPersonneDuRDV("RDV random"));
 carnet->creerRDV("RDV rando",Date(30,3,2017),Horaire(18,00),Horaire(19,00));
  carnet->creerRDV("RDV rand",Date(30,3,2017),Horaire(17,00),Horaire(19,00));
   carnet->creerRDV("RDV rando",Date(31,3,2017),Horaire(18,00),Horaire(19,00));
//    std::cout << carnet->AfficherRDV("RDV random");
   //std::cout << carnet->AfficherRDVs_dune_Date(Date(30,3,2017));
    cli(carnet);

    return 0;
}
