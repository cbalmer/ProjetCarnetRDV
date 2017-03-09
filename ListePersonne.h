#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H
#include<string>
#include<iostream>
#include "ListeRDV.h"


struct Personne{
  std::string prenom,nom,tel,mail;
  Personne *suiv;
};

class ListePersonne
{
    public:
        ListePersonne();
        ~ListePersonne();
  //    ListePersonne(Personne &p); vraiment utile de faire ce constructeur ?
      void ajouter(std::string prenom, std::string nom,std::string tel, std::string mail);
        void supprimer(std::string prenom, std::string nom,std::string tel, std::string mail);
        void modifier(std::string prenom, std::string nom,std::string tel, std::string mail);
        bool estDouble(std::string prenom, std::string nom,std::string tel, std::string mail);
/*
        void ajouter(Personne *pe); //Permet l'ajout d'une personne*/
        void supprimer(Personne *pe); //Permet la suppression d'une personne
        void modifier(Personne *pe);// Permet la modification d'une personne
        bool estDouble(Personne *pe);// permet de voir si une personne est déjà en contact
        bool estRDV(Personne *pe,RDV *rd);// permet de savoir si une personne est dans un rendez-vous

    private:
    	Personne *p;
};

#endif // LISTEPERSONNE_H
