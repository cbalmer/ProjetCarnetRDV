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
bool ListePersonne::estDouble(Personne *pe)
{
    Personne *n=new Personne;
    std::cin >> pe->nom;
    std::cin>> pe->prenom;
    if(pe->nom == n->nom && pe->prenom ==n->prenom)
    {
        return true;
    }
    else
        return false;
}
bool ListePersonne::estRDV(Personne *pe,RDV *rd)
{
    std::cin >> pe->nom >> pe->prenom;
    if (pe->nom && pe->prenom == rd->jour &&rd->mois&&rd->heureDebut&&rd->heureFin)
    {
        return true;
    }
    else
        return false;
}
void ListePersonne::ajouter(Personne *pe)
{
    Personne *n=new Personne();
    if(estDouble(pe)==false)
    {
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
    else
        std::cout<<"Erreur: Cette personne existe deja et ne peut pas etre ajoutee."<<endl;

}

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


int main()
{
	return 0;
}
