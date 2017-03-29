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


bool  ListeLien::supprimer(Personne* p, RDV* r)
{
	if(_tete)
	{
		if(_tete->p == p && _tete->r == r)
		{
			Lien* s = _tete;
			_tete = _tete->suiv;
			delete s;
		}
		else
		{
			Lien* c = _tete;
			while(c->suiv && (c->suiv->p != p || c->suiv->r != r))
			{
				c = c->suiv;
			}

			if(c->suiv)//si c->suiv est différent de null c'est que c'est le lien à supprimer
			{
				Lien* s = c->suiv;
				c->suiv = c->suiv->suiv;
				delete s;
			}
			else
				return false;//pas de correspondance
		}
	}
	else
		return false;

	return true;
}

bool ListeLien::supprimer(RDV* r)
{
if(_tete)
	{
		if( _tete->r == r)
		{
			Lien* s = _tete;
			_tete = _tete->suiv;
			delete s;
		}
		else
		{
			Lien* c = _tete;
			while(c->suiv && ( c->suiv->r != r))
			{
				c = c->suiv;
			}

			if(c->suiv)//si c->suiv est différent de null c'est que c'est le lien à supprimer
			{
				Lien* s = c->suiv;
				c->suiv = c->suiv->suiv;
				delete s;
			}
			else
				return false;//pas de correspondance
		}
	}
	else
		return false;

	return true;
}

bool ListeLien::ajouter(Personne *p, RDV *r)
{
    Lien *lelien= new Lien;
    lelien->p=p;
    lelien->r=r;
    lelien->suiv = nullptr;
    if(_tete==0)
    {
        _tete=lelien;
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
ListeRDV ListeLien::recherche(Personne* p)
{
	ListeRDV lRDV;

	Lien* c = _tete;
	while(c)
	{
		if(c->p == p)
			lRDV.ajouter(c->r->Nom, c->r->d, c->r->hDeb, c->r->hFin);
		c = c->suiv;
	}


	return lRDV;
}

ListePersonne ListeLien::recherche(RDV *r)
{
    ListePersonne lp;
    Lien *curs = _tete;

    while(curs != 0)
    {

        if(curs->r==r)
        {
            lp.ajouter(curs->p->prenom,curs->p->nom,curs->p->tel,curs->p->mail);

        }
		curs=curs->suiv;
    }

    return lp;
}

RDV* ListeLien::recherche(Personne* p, Date   const&d, Horaire  const&hd, Horaire  const&hf)
{
    Lien *curs = _tete;
    while
    (curs!=0 &&
        (
            curs->p!=p ||
            curs->r->d!=d ||
            (
                !(curs->r->hDeb < hd && curs->r->hFin > hf) &&
                !(curs->r->hDeb > hd && curs->r->hDeb < hf)&&
                !(curs->r->hFin > hd && curs->r->hFin < hf)
            )
        )
    )
    {

		curs=curs->suiv;
    }

    if(curs)
        return curs->r;

    return nullptr;
}
