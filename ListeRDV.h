#ifndef LISTERDV_H
#define LISTERDV_H
#include "Date.h"
#include "Horaire.h"
#include <iostream>

class CarnetRDV;

struct RDV{
    RDV():suiv{nullptr}{}
    std::string Nom;
    Date d;
    Horaire hDeb;
    Horaire hFin;
    RDV *suiv;
};

class ListeRDV
{
    public:
        ListeRDV();
        ~ListeRDV();

        ListeRDV(ListeRDV const&);

        void ajouter(const std::string & nom, const Date & d, const Horaire & hDeb, const Horaire & hFin);
        RDV* recherche(const std::string & nom);
        ListeRDV recherche(const Date &d);
        void supprimer(const std::string & nom);
        void modifierDate(const std::string & nom, const Date & d);
        void modifierHeureDebut(const std::string & nom, const Horaire & hDeb);
        void modifierHeureFin(const std::string & nom, const Horaire & hFin);
        std::string afficher() const;

    private:
        RDV *_tete;

    friend CarnetRDV;
};

#endif // LISTERDV_H
