#ifndef ListeLien_h
#define ListeLien_h

#include "ListePersonne.h"
#include "ListeRDV.h"

struct Lien
{
    Lien():suiv{nullptr}{}
	Personne* p;
	RDV* r;
	Lien* suiv;
};

class ListeLien
{

	public:
		ListeLien();
		~ListeLien();

		bool ajouter(Personne* p, RDV* r);
		bool supprimer(Personne* p, RDV* r);
		bool supprimer(RDV* r);

		ListePersonne recherche(RDV* r);
		ListeRDV recherche(Personne* p);
		RDV* recherche(Personne* p, Date const &d, Horaire   const &hd, Horaire  const &hf);

	private:
		Lien* _tete;
};

#endif
