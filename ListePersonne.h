#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H
#include<string>
#include<iostream>
#include "ListeRDV.h"


struct Personne{
    Personne():suiv{nullptr}{}

  std::string prenom,nom,tel,mail;
  Personne *suiv;
};

class ListePersonne
{
    public:
        ListePersonne();
        ListePersonne(ListePersonne const& l);
        ~ListePersonne();
        //    ListePersonne(Personne &p); vraiment utile de faire ce constructeur ?
        void ajouter(std::string prenom, std::string nom,std::string tel, std::string mail);
        void supprimer(std::string  prenom, std::string nom);
        void modifier(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail);
        bool estDouble(std::string  &nom, std::string  &prenom);// permet de voir si une personne est déjà en contact
        void afficherlistpersonne();
        std::string afficherListpersonne() const;
        Personne* rechercherPersonne(std::string  nom, std::string  prenom);
    private:
    	Personne *p;
};

#endif // LISTEPERSONNE_H
