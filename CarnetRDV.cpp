#include "CarnetRDV.h"


bool CarnetRDV::ajouterPersonne( std::string &prenom,  std::string &nom,std::string  &tel, std::string   &mail)
{
	listp.ajouter(prenom,nom,tel,mail);
	return 1;
}

bool CarnetRDV::ajouterPersonneRDV(std::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne)
{
    if(listp.estDouble(NomPersonne, PrenomPersonne))
    {
        if(lrdv.recherche(nomRDV) == nullptr)
        {
            return false;
        }
        else
        {
            RDV *rdv = lrdv.recherche(nomRDV);
            Personne *pers = listp.rechercherPersonne(NomPersonne, PrenomPersonne);
            ll.ajouter(pers, rdv);
            return true;
        }
    }
    else
    {
        return false;
    }
}

bool CarnetRDV::supprimerPersonneRDV(std::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne)
{
    if(lrdv.recherche(nomRDV) != nullptr)
    {
        RDV *rdv = lrdv.recherche(nomRDV);
        ListePersonne lPerso = ll.recherche(rdv);
        if(lPerso.rechercherPersonne(NomPersonne, PrenomPersonne) == nullptr)
        {
            return false;
        }
        else
        {
            Personne *pers = listp.rechercherPersonne(NomPersonne, PrenomPersonne);
            ll.supprimer(pers, rdv);
            return true;
        }
    }
    else
    {
        return false;
    }
}

ListePersonne CarnetRDV::getlesPersonneDuRDV(std::string const &nom)
{
    ListePersonne lPerso();
    RDV *rdv = lrdv.recherche(nom);
    if(rdv == nullptr)
    {
        return lPerso;
    }
    else
    {
        lPerso = ll.recherche(rdv);
        return lPerso;
    }
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

bool CarnetRDV::EstDispo(std::string const &nom, std::string const &prenom,Date const &date,Horaire const & hDeb,Horaire const  &hFin)
{
    return true;
}

bool CarnetRDV::EstRDV(std::string const &nom,std::string const &prenom)
{
        return true;
}

bool CarnetRDV::supprimerPersonne(std::string const &nom,std::string const &prenom)
{
    if(EstRDV(nom,prenom)==false)
        return true;
    else
        return false;
}
int main()
{
    return 0;
}
