#include "ListeLien.h"

ListeLien::ListeLien(): _tete{nullptr}
{}

ListeLien::~ListeLien()
{
	if(_tete)
	{
		Lien* c = _tete;
		while(c)
		{
			Lien* s = c;
			c = c->suiv;
			delete s;
		}
	}
}


bool supprimer(Personne* p, RDV* r)
{
	if(_tete)
	{
		if(_tete->)

		Lien* c = _tete;
		while(c->suiv && (c->suiv->p != p || c->suiv->r != r))
		{
			c = c->suiv;
		}

		if(c)
	}
}


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
