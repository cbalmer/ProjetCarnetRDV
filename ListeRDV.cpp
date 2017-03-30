#include "ListeRDV.h"

ListeRDV::ListeRDV():_tete{nullptr}
{}

ListeRDV::~ListeRDV()
{
    while(_tete!=0)
    {
        RDV *c=_tete->suiv;
        delete _tete;
        _tete=c;
    }
}
ListeRDV::ListeRDV(const ListeRDV &rdv)
{
    RDV *curs = rdv._tete;
    while(curs!=0)
    {
        ajouter(curs->Nom,curs->d,curs->hDeb,curs->hFin);
        curs=curs->suiv;
    }
}
void ListeRDV::ajouter( const std::string & nom, const Date & d, const Horaire & hDeb, const Horaire & hFin)
{
    RDV *c = _tete;
    RDV *nvRDV = new RDV;
    nvRDV->Nom = nom;
    nvRDV->d = d;
    nvRDV->hDeb = hDeb;
    nvRDV->hFin = hFin;

    if(_tete != nullptr)
    {
        while(c->suiv != nullptr)
        {
            c = c->suiv;
        }
        c->suiv = nvRDV;
    }
    else
    {
        _tete = nvRDV;
    }
    nvRDV->suiv = nullptr;
}

RDV* ListeRDV::recherche(const std::string & nom)
{
    RDV* c = _tete;
    if(_tete == nullptr)
    {
        return nullptr;
    }
    else
    {
        if(_tete->Nom == nom)
        {
            return _tete;
        }
        else
        {
            while(c->suiv != nullptr && c->suiv->Nom != nom)
            {
                c = c->suiv;
            }
            if(c->suiv == nullptr)
            {
                return nullptr;
            }
            else
            {
                return c->suiv;
            }
        }
    }
}

void ListeRDV::supprimer(const std::string & nom)
{
    RDV *c = recherche(nom);
    RDV *c2;
    if(_tete != nullptr)
    {
       if(c == _tete)
        {
            c2 = _tete->suiv;
            _tete = c2;
            delete c;
        }
        else
        {
            c2 = _tete;
            while(c2->suiv != nullptr && c2->suiv != c)
            {
                c2 = c2->suiv;
            }
            if(c2->suiv != nullptr)
            {
                c2->suiv = c->suiv;
                delete c;
            }
        }
    }
}

std::string ListeRDV::afficher() const
{
    std::ostringstream oss;

    RDV *c = _tete;
    while(c != nullptr)
    {
        oss << c->Nom << ": " << c->d.str() << " de " << c->hDeb.str() << " à " << c->hFin.str() <<"\n";
        c = c->suiv;
    }

    return oss.str();
}

void ListeRDV::modifierDate(const std::string & nom, const Date & da)
{
    RDV *rdv = recherche(nom);
    if(rdv != nullptr)
    {
        rdv->d = da;
    }
}

void ListeRDV::modifierHeureDebut(const std::string & nom, const Horaire & hDeb)
{
    RDV *rdv = recherche(nom);
    if(rdv != nullptr)
    {
        rdv->hDeb = hDeb;
    }
}

void ListeRDV::modifierHeureFin(const std::string & nom, const Horaire & hFin)
{
    RDV *rdv = recherche(nom);
    if(rdv != nullptr)
    {
        rdv->hFin = hFin;
    }
}
  ListeRDV ListeRDV::recherche(const Date &d)
  {
	ListeRDV lRDV;

	RDV* c = _tete;
	while(c)
	{


		if(c->d == d)
        {
			lRDV.ajouter(c->Nom, c->d, c->hDeb, c->hFin);
        }
		c = c->suiv;
	}
	return lRDV;
  }

//int main()
//{
//    ListeRDV test;
//    Date d(21, 04, 2017);
//    Horaire hD(10, 10);
//    Horaire hF(11, 05);
//    test.ajouter("essai", d, hD, hF);
//    d = {22, 05, 2017};
//    hD = {20, 12};
//    hF = {21, 00};
//    test.ajouter("essai 2", d, hD, hF);
//    test.afficher();
//    test.supprimer("essai");
//    test.afficher();
//}
