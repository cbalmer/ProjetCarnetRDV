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
void ListePersonne:: modifier(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail)
{
    bool trouver=false;
    Personne *curs=p;
    while(curs!=0 && !trouver)
    {
        if(curs->nom==nom && curs->prenom==prenom)
        {
            trouver=true;
            curs->nom=nouveaunom;
            curs->prenom==prenom;
            curs->tel=tel;
            curs->mail=mail;
        }
        curs=curs->suiv;
    }
}
//pk !curs dont work
bool ListePersonne::estDouble(Personne *pe)
{
    bool estdouble=false;
    Personne *curs=p;
    while(curs!=0 && !estdouble)
    {
        if(curs->nom==pe->nom && curs->prenom==pe->prenom)
            estdouble=true;
        curs=curs->suiv;
    }
    return estdouble;
}


void ListePersonne::ajouter(std::string prenom, std::string nom,std::string tel, std::string mail)
{
    Personne *pe=new Personne;
    nom[0]=std::toupper(nom[0]);
    pe->nom=nom;
    pe->prenom=prenom;
    pe->tel=tel;
    pe->mail=mail;
    pe->suiv=0;
    if(!estDouble(pe))
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





void ListePersonne::supprimer(std::string prenom, std::string nom)
{
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
            while(curs!=0 && curs->nom==mom && curs->prenom==prenom)
            {

            }
        }

    }
}


int main()
{
    ListePersonne lp;

    lp.ajouter("toto","Alice","062606060626","fdziosf");
     lp.ajouter("toto","Alice","062606060626","fdziosf");
    lp.ajouter("toto","albert","062606060626","fdziosf");
    lp.ajouter("toto","Banner","062606060626","fdziosf");
   lp.ajouter("toto","connor","062606060626","fdziosf");
	return 0;
}
