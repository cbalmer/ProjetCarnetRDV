#ifndef LISTERDV_H
#define LISTERDV_H
#include "Date.h"
#include "Horaire.h"

struct RDV{
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
        void ajouter(const std::string & nom, const Date & d, const Horaire & hDeb, const Horaire & hFin);
        RDV* recherche(const std::string & nom);
        void supprimer(const std::string & nom);
        void modifierDate(const std::string & nom, const Date & d);
        void modifierHeureDebut(const std::string & nom, const Horaire & hDeb);
        void modifierHeureFin(const std::string & nom, const Horaire & hFin);

    private:
        RDV *_tete;
};

#endif // LISTERDV_H
