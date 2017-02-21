#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H
#include<string>
#include<iostream>

using namespace std;
struct Personne{
  string prenom,nom,tel,mail;
  Personne *suiv;
};

class ListePersonne
{
    public:
        ListePersonne();
        ~ListePersonne();
  //    ListePersonne(Personne &p); vraiment utile de faire ce constructeur ?
/*      void ajouter(string prenom, string nom,string tel, string mail);
        void supprimer(string prenom, string nom,string tel, string mail);
        void modifier(string prenom, string nom,string tel, string mail);
        bool estDouble(string prenom, string nom,string tel, string mail);
*/
        void ajouter(Personne *pe);
        void supprimer(Personne *pe);
        void modifier(Personne *pe);
        bool estDouble(Personne *pe);
    private:
    	Personne *p;
};

#endif // LISTEPERSONNE_H
