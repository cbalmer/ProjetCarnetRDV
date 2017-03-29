#include "CarnetRDV.h"

bool CarnetRDV::creerRDV(std::string const& nom, Date const& date, Horaire const& hDeb)
{
    Horaire hFin = hDeb;
    hFin.decaleHeure(1);
    lrdv.ajouter(nom,date,hDeb,hFin);
}

bool CarnetRDV::creerRDV(std::string const& nom, Date const& date, Horaire const& hDeb,Horaire const  &hFin)
{
    lrdv.ajouter(nom,date,hDeb,hFin);
}

bool CarnetRDV::supprimerRDV(std::string const & nom)
{
    lrdv.supprimer(nom);
}

bool CarnetRDV::EstDispo(std::string  nom, std::string  prenom,Date const  &date,Horaire const& hDeb,Horaire  const& hFin)
{
	Personne *p=listp.rechercherPersonne(nom,prenom);

	if(!ll.recherche(p,date,hDeb,hFin))
        return true;
    else
    {
        return false;
    }
}


bool CarnetRDV::ajouterPersonne( std::string prenom,  std::string nom,std::string  tel, std::string   mail)
{
	listp.ajouter(prenom,nom,tel,mail);
	return 1;
}

bool CarnetRDV::ajouterPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne)
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

bool CarnetRDV::supprimerPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne)
{
    if(lrdv.recherche(nomRDV) != nullptr)
    {
        RDV *rdv = lrdv.recherche(nomRDV);
        ListePersonne lPerso(ll.recherche(rdv));
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
    RDV *rdv = lrdv.recherche(nom);
    if(rdv == nullptr)
    {
        return ListePersonne();
    }
    else
    {
        ListePersonne lPerso(ll.recherche(rdv));
        return lPerso ;
    }
}

std::string CarnetRDV::AfficherRDV(std::string const &nom)
{
    ListePersonne pRDV(getlesPersonneDuRDV(nom));
    std::string chaine="";
    RDV *lerdv=lrdv.recherche(nom);
    if(!lerdv)
        return "";
    chaine=chaine+lerdv->Nom+"\n";
    chaine+=lerdv->d.str()+"\n";
    chaine+=lerdv->hDeb.str()+"\n";
    chaine+=lerdv->hFin.str()+"\n";
    chaine+= pRDV.afficherListpersonne();

    return chaine;
}

std::string CarnetRDV::afficherPersonne(std::string  nom , std::string  prenom)
{
    Personne* perso = listp.rechercherPersonne(nom,prenom);
    if(!perso)
        return "";

    std::string str;
    str = "\nNom: " + perso->nom;
    str += "\nPrénom: " + perso->prenom;
    str += "\nTel: " + perso->tel;
    str += "\nmail: " + perso->mail;

    return str;
}


bool CarnetRDV::EstRDV(std::string &nom,std::string &prenom)
{
    Personne* pers=listp.rechercherPersonne(nom,prenom);
    if(pers==nullptr)
        return false;
    else
    {

        ListeRDV lr(ll.recherche(pers));
        if(lr._tete==nullptr)
            return false;
        else
            return true;
    }
}

bool CarnetRDV::supprimerPersonne(std::string nom,std::string prenom)
{
    if(EstRDV(nom,prenom)==false)
        return true;
    else
        return false;
}

std::string CarnetRDV::afficherPersonnes() const
{
    return listp.afficherListpersonne();
}

void CarnetRDV::modifierPersonne(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail)
{
    listp.modifier(prenom,nom,nouveaunom,nouveauprenom,tel,mail);
}

