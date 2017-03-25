#include "ListePersonne.h"

ListePersonne::ListePersonne():p{0}
{}

ListePersonne::~ListePersonne()
{
    while(p!=0)
    {
        Personne *ps=p->suiv;
        delete p;
        p=ps;
    }
}



//pk !curs dont work
bool ListePersonne::estDouble(std::string  &nom, std::string  &prenom)
{
    nom[0]=std::toupper(nom[0]);
    bool estdouble=false;
    Personne *curs=p;
    while(curs!=0 && !estdouble)
    {
        if(curs->nom==nom && curs->prenom==prenom)
            estdouble=true;
        curs=curs->suiv;
    }
    return estdouble;
}


void ListePersonne::ajouter(std::string &prenom, std::string &nom,std::string &tel, std::string &mail)
{
    Personne *pe=new Personne;
    nom[0]=std::toupper(nom[0]);
    pe->nom=nom;
    pe->prenom=prenom;
    pe->tel=tel;
    pe->mail=mail;
    pe->suiv=0;
    if(!estDouble(pe->nom,pe->prenom))
    {
        if(p==0)
        {
            p=pe;
        }
        else
        {
            Personne *curs=p,*preC=0;
            if(nom<curs->nom)
            {
                pe->suiv=p;
                p=pe;
            }
            else
            {
                while(curs!=0 && curs->nom<=nom)
                {
                    preC=curs;
                    curs=curs->suiv;
                }
                if(curs==0)
                {
                    preC->suiv=pe;
                }
                else
                {
                    pe->suiv=curs;
                    preC->suiv=pe;
                }
            }
        }
//        Personne  *curse=p;
//        while(curse!=0)
//        {
//            std::cout<<curse->nom<<std::endl;
//            curse=curse->suiv;
//        }
//        std::cout << "---------------------------"<<std::endl;
    }
}
//aide prof
//Personne *c1=l.t, *precC=0;
//if{c1==0}
//{
//	//liste vide
//	return 0;
//}
//if(c1->n<nom)
//{
//	//insert tete
//	return 0;
//}
//
//while(c1!=0 && c1->n>n)
//{
//	precC=c1;
//	c1=c1->suiv;
//}





void ListePersonne::supprimer(std::string &prenom, std::string &nom)
{
    nom[0]=std::toupper(nom[0]);
    if(p!=0)
    {
        if(p->nom ==nom && p->prenom==prenom)
        {
            Personne *supprP=p;
            p=p->suiv;
            delete supprP;
        }
        else
        {
            Personne *curs=p;
            Personne *Preccurs=0;
            while(curs!=0 )
            {
                if(curs->nom==nom && curs->prenom==prenom)
                {
                   break;
                }
                Preccurs=curs;
                curs=curs->suiv;
            }
            if(curs!=0)
            {
                Preccurs->suiv=curs->suiv;
                delete curs;
            }
        }
    }
}
void ListePersonne::afficherlistpersonne()
{
    Personne *curs=p;
    while(curs!=0)
    {
        std::cout<<curs->nom<<std::endl;
         std::cout<<curs->prenom<<std::endl;
          std::cout<<curs->mail<<std::endl;
           std::cout<<curs->tel<<std::endl;
           std::cout<<std::endl;
        curs=curs->suiv;
    }
    std::cout<<"----------------------------------------------------"<<std::endl;
}
void ListePersonne:: modifier(std::string &prenom, std::string &nom,std::string &nouveaunom,std::string &nouveauprenom,std::string &tel, std::string &mail)
{
    nom[0]=std::toupper(nom[0]);
    nouveaunom[0]=std::toupper(nouveaunom[0]);
    bool trouver=false;
    Personne *curs=p;
    while(curs!=0 && !trouver)
    {
        if(curs->nom==nom && curs->prenom==prenom)
        {
            trouver=true;
            supprimer(prenom,nom);
            ajouter(nouveauprenom,nouveaunom,tel,mail);
        }
        curs=curs->suiv;
    }
}

Personne* ListePersonne::rechercherPersonne(std::string  &nom, std::string  &prenom)
 {
    Personne *curs=p;
    while(curs!=0 )
    {
        if(curs->nom==nom && curs->prenom==prenom)
        {
           break;
        }
        curs=curs->suiv;
    }
    return curs;
 }

int main()
{
    ListePersonne lp;
    std:: string nom="toto",prenom="Alice",tel="",mail="";
    lp.ajouter(nom,prenom,tel,mail);
    lp.ajouter("toto","Alice","062606060626","fdziosf");
    lp.ajouter("toto","albert","062606060626","fdziosf");
    lp.ajouter("toto","Banner","062606060626","fdziosf");
    lp.ajouter("toto","connor","062606060626","fdziosf");
    lp.afficherlistpersonne();
    lp.supprimer("toto","Alice");
    lp.afficherlistpersonne();
    lp.modifier("toto","albert","couillons","toto","0612346500","hypoter@hotmail.fr");
    lp.afficherlistpersonne();
    Personne *perso=lp.rechercherPersonne("Banner","tito");
    if(perso!=0)
    {
        std::cout<<perso->nom<<std::endl;
        std::cout<<perso->prenom<<std::endl;
        std::cout<<perso->mail<<std::endl;
        std::cout<<perso->tel<<std::endl;
        std::cout<<std::endl;
    }

	return 0;
}
