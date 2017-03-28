#include "ListeLien.h"

ListeLien::ListeLien()

 bool ListeLien::ajouter(Personne *p, RDV *r)
{
    Lien *lelien= new Lien;
    lelien->p=p;
    lelien->r=r;
    if(_tete==0)
    {
        _lien=lelien;
    }
    else
    {
        Lien *curs=_tete;
        while(curs->suiv!=0)
        {
            curs=curs->suiv;
        }
        curs->suiv=lelien;
    }
}
