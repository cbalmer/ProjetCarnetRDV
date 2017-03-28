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

	public:
		ListeLien();
		~ListeLien();

		void ajouter(Personne* p, RDV* r);
		void supprimer(Personne* p, RDV* r);
		void supprimer(RDV* r);

		ListePersonne recherche(RDV* r);
		ListeRDV recherche(Personne* r);

	private:
		Lien* _tete;
};	

#endif