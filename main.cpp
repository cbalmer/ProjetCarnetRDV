#include <iostream>

#include "CLI.h"
#include "CarnetRDV.h"

int main()
{
    CarnetRDV* carnet = new CarnetRDV();

    carnet->ajouterPersonne("Camille","Balmer","0987675745","caca@caca.fr");
    carnet->ajouterPersonne("Nathan","Baumann","0330492834","pipi@caca.fr");
//    std::cout<<carnet->supprimerPersonne("Camille","Balmer");
    carnet->creerRDV("RDV",Date(30,3,2017),Horaire(18,00),Horaire(19,00));
//    std::cout << carnet->AfficherRDV("RDV random");
   carnet->ajouterPersonneRDV("RDV","Balmer","Camille");
//     ListePersonne l(carnet->getlesPersonneDuRDV("RDV random"));
//
//    std::cout << l.afficherListpersonne();
//    std::cout<<carnet->EstDispo("Balmer","Camille",Date(29,3,2017),Horaire(16,00),Horaire(18,00));
//    carnet->supprimerPersonneRDV("RDV random","Balmer","Camille");
//     ListePersonne l2(carnet->getlesPersonneDuRDV("RDV random"));
 carnet->creerRDV("RDV2",Date(30,3,2017),Horaire(18,10),Horaire(18,50));
  carnet->creerRDV("RDV3",Date(30,3,2017),Horaire(17,00),Horaire(18,50));
  carnet->creerRDV("RDV4",Date(30,3,2017),Horaire(19,10),Horaire(19,50));

 //  std::cout << carnet->AfficherRDV("RDV random");
   //std::cout << carnet->AfficherRDVs_dune_Date(Date(30,3,2017));
    cli(carnet);

    return 0;
}
