#ifndef CarnetRDV_h
#define CarnetRDV_h
#include <string>
#include "ListePersonne.h"
#include "ListeRDV.h"
#include "Date.h"
#include "Horaire.h"

class CarnetRDV
{
	public:
		CarnetRDV();

		bool creerRDV(std::string const& nom, std::string const& prenom, Date const& date, Horaire const& hDeb);
		bool creerRDV(std::string const &nom, std :: string const &prenom , Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		bool supprinerRDV(std::string const &nom );
		bool ajouterPersonneRDV(std::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne);
		bool supprimerPersonneRDV(std::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne);
		bool ajouterPersonne(std::string &prenom, std::string &nom,std::string  &tel, std::string &mail);
		bool supprimerPersonne(std::string const &nom,std::string const &prenom);
		bool EstRDV(std::string const &nom,std::string const &prenom);
		std::string AfficherRDV(std::string const &nom);
		bool EstDispo(std::string const &nom, std::string const &prenom,Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		std::string afficherPersonne(std::string const &nom , std::string const &prenom);
		ListePersonne getlesPersonneDuRDV(std::string const &nom);
	private:
		ListePersonne listp;
		ListeRDV lrdv;
		//ListeLien ll;

};

#endif
