#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H
#include<string>
#include<iostream>

struct Personne{
  string prenom,nom,tel,mail;
  Personne *suiv;
};

class ListePersonne
{
    public:
        ListePersonne();
        ~ListePersonne();


        void ajouter(Personne *pe); //Permet l'ajout d'une personne
        void supprimer(Personne *pe); //Permet la suppression d'une personne
        void modifier(Personne *pe);// Permet la modification d'une personne
        bool estDouble(Personne *pe);// permet de voir si une personne est déjà en contact
        bool estRDV(Personne *pe,RDV *rd);// permet de savoir si une personne est dans un rendez-vous
  
    private:
    	Personne *p;
};

#endif // LISTEPERSONNE_H
