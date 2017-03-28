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
