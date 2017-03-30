#ifndef CarnetRDV_h
#define CarnetRDV_h
#include <string>
#include "ListePersonne.h"
#include "ListeRDV.h"
#include "ListeLien.h"
#include "Date.h"
#include "Horaire.h"

class CarnetRDV
{
	public:
		bool creerRDV(std::string const& nom, Date const& date, Horaire const& hDeb);
		bool creerRDV(std::string const &nom, Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		bool supprimerRDV(std::string const &nom );
		bool ajouterPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne);
		bool supprimerPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne);
		bool ajouterPersonne(std::string prenom, std::string nom,std::string  tel, std::string mail);
		bool supprimerPersonne(std::string nom,std::string prenom);
		bool EstRDV(std::string  &nom,std::string &prenom);
		std::string AfficherRDV(std::string const &nom);
		bool EstDispo(std::string  nom, std::string  prenom,Date  const&date,Horaire const& hDeb,Horaire  const&hFin);
		std::string afficherPersonne(std::string  nom , std::string  prenom);
		ListePersonne getlesPersonneDuRDV(std::string const &nom);
		std::string afficherPersonnes() const;
		void modifierPersonne(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail);
		std::string AfficherRDVs_dune_Date(Date const &Date);
	private:
		ListePersonne listp;
		ListeRDV lrdv;
		ListeLien ll;

};

#endif
