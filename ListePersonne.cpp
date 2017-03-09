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
//bool ListePersonne::estDouble(Personne *pe)
//{
//    Personne *n=new Personne;
//    std::cin >> pe->nom;
//    std::cin>> pe->prenom;
//    if(pe->nom == n->nom && pe->prenom ==n->prenom)
//    {
//        return true;
//    }
//    else
//        return false;
//}

bool ListePersonne::estRDV(Personne *pe,RDV *rd)
{}
void ListePersonne::ajouter(std::string prenom, std::string nom,std::string tel, std::string mail)
{
    Personne *pe=new Personne;
    pe->nom=nom;
    pe->prenom=prenom;
    pe->tel=tel;
    pe->mail=mail;
    pe->suiv=0;

        if(p==0)
        {
            p=pe;
        }
        else
        {
            Personne *curs=new Personne;
            curs=p;
            while(curs->suiv!=0)
            {
                curs=curs->suiv;
            }
            if(curs->suiv==0)
            {
                curs->suiv=pe;
            }
            else
            {
                pe->suiv=curs->suiv;
                curs->suiv=pe;
            }



        }
        Personne  *curs=p;
         while(curs->suiv!=0)
            {
                std::cout<<curs->nom<<std::endl;
                curs=curs->suiv;
            }
}
/*
void ListePersonne::supprimer(Personne *pe)
{
    if(estRDV(pe,rd)==false)
    {
        if(p==0)
        {
        }
        else if(p->pe==pe)
        {
            Personne *tmp=p;
            p=p->suiv;
            delete tmp;
        }
        else
        {
            Personne *p1=p,*p2=p->suiv;
            while(p2!=0  p2->pe!=pe)
            {
                p1=p2;
                p2=p2->suiv;
            }
            if(p2!=0)
            {
                p1->suiv=p2->suiv;
                delete p2;
            }
        }
    }
    else
        std::cout<<"Erreur: Cette personne est encore inscris dans un rendez-vous et ne peut pas etre supprimee."<<endl;
}

*/
int main()
{
    ListePersonne lp;

    lp.ajouter("toto","alyssa","062606060626","fdziosf");
    lp.ajouter("toto","tata","062606060626","fdziosf");
    lp.ajouter("toto","Banner","062606060626","fdziosf");
   lp.ajouter("toto","connor","062606060626","fdziosf");
	return 0;
}
