#ifndef LISTERDV_H
#define LISTERDV_H


class ListeRDV
{
    public:
        ListeRDV();
        
        ListeRDV(int jour,int mois, int annee,int heureDebut,int heureFin);
        void ajouter();
        void supprimer();
        void modifier();
    
    protected:

    private:
};

#endif // LISTERDV_H
