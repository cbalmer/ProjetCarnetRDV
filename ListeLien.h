#ifndef ListeLien_h
#define ListeLien_h

#include "ListePersonne.h"
#include "ListeRDV.h"

struct Lien
{
	Personne* p;
	RDV* r;
	Lien* suiv;
};

class ListeLien
{
	ListeLien();
	~ListeLien();

	void ajouter(Personne* p, RDV* r);
	void supprimer(Personne* p, RDV* r);
	void supprimer(RDV* r);

	std::vector<Personne*> recherche(RDV* r);
	std::vector<RDV*> recherche(Personne* r);
};

#endif