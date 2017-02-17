#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H

struct Personne{
  char prenom;
  char nom;
  int tel;
  char mail;
};

class ListePersonne
{
    public:
        ListePersonne();

        ListePersonne(char prenom,char nom, int tel,char mail);
        void ajouter();
        void supprimer();
        void modifier();
    
    protected:

    private:
};

#endif // LISTEPERSONNE_H
