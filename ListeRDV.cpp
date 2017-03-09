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

void ListeRDV::ajouter( const std::string & nom, const Date & d, const Horaire & hDeb, const Horaire & hFin)
{
    RDV *c = _tete;
    RDV *nvRDV = new RDV{nom, d, hDeb, hFin};
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

}
