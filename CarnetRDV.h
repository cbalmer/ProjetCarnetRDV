#ifndef CarnetRDV_h
#define CarnetRDV_h

#include <string>
#include <map>
#ifdef _WIN32
    #include <mysql.h>
    #include <winsock.h>
#else
    #include <MYSQL/mysql.h>
    #include <string.h>
#endif

#include "ListePersonne.h"
#include "ListeRDV.h"
#include "ListeLien.h"
#include "Date.h"
#include "Horaire.h"

class CarnetRDV
{
	private:
		int getIDRdv(std::string nom);
		void InsererLien(int idpers,int idrdv);
		void supprimerRDV_BDD(std::string nom);
		void supprimerPersonneDuRDV_BDD(std::string nomrdv,std::string nom,std::string prenom);
		void ModifierPersonne_BDD(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail);
        void supprimerPersonne_BDD(std::string nom,std::string prenom);
	public:
		bool creerRDV(std::string const& nom, Date const& date, Horaire const& hDeb);
		bool creerRDV(std::string nom, Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		bool supprimerRDV(std::string const &nom );
		int ajouterPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne);
		int getIDPersonne(std::string nom,std::string prenom);
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


    public:static bool initialisation();
    public:bool import();
    public:static MYSQL mysql;
};

#endif
