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

void ListePersonne::ajouter(Personne *pe)
{
    Personne *n=new Personne();
    n->pe=pe;
    n->suiv=0;
    if (p==0)
    {
        p=n;
    }
    else if (pe < p -> pe)
    {
        n->suiv=p;
        p=n;
    }
    else
    {
        Personne *p1 = p ,*p2 = p ->suiv;
        while(p2!=0  pe>p2->pe)
        {
            p1=p2;
            p2=p2->suiv;
        }
        p1->suiv=n;
        n->suiv=p2;
    }
}

void ListePersonne::supprimer(Personne *pe)
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
int main()
{
	return 0;
}
