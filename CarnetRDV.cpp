#include "CarnetRDV.h"





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
    chaine+= pRDV.afficherlistpersonne();
}
std::string CarnetRDV::afficherPersonne(std::string const &nom , std::string const &prenom)
{
    std::string chaine="";
    Personne *lapers=listp.rechercherPersonne(nom,prenom);
    chaine=chaine+lapers->nom+"\n";
    chaine+=lapers->prenom+"\n";
    chaine+=lapers->mail+"\n";
    chaine+=lapers->tel+"\n";
    chaine+= listp.afficherlistpersonne();
}

int main()
{
    /*CarnetRDV c;
    std::string nom;
    std::string prenom;

   if(c.supprimerPersonne(nom,prenom)==false)
        std::cout<<"Suppression impossible"<<std::endl;
   else
        c.supprimerPersonne(nom,prenom);
*/
return 0;
}
