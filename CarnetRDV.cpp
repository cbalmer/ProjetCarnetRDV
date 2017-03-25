#include "CarnetRDV.h"


	bool CarnetRDV::ajouterPersonne( std::string &prenom,  std::string &nom,std::string  &tel, std::string   &mail)
	{
        listp.ajouter(prenom,nom,tel,mail);
        return 1;
	}
		ListePersonne CarnetRDV::getlesPersonneDuRDV(std::string const &nom)
		{

		}
	std::string CarnetRDV::AfficherRDV(std::string const &nom)
	{
	    ListePersonne pRDV=getlesPersonneDuRDV(nom);
	    std::string chaine="";
	    RDV *lerdv=lrdv.recherche(nom);
	    chaine=chaine+lerdv->Nom+"\n";
	    chaine+=lerdv->d.str()+"\n";
	    chaine+=lerdv->hDeb.str()+"\n";
	    chaine+=lerdv->hFin.str()+"\n";
	    chaine+= pRDV.afficherListpersonne();
	}
int main()
{
    return 0;
}
