#ifndef LISTEPERSONNE_H
#define LISTEPERSONNE_H


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
