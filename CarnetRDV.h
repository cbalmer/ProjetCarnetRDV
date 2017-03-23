#ifndef CarnetRDV_h
#define CarnetRDV_h

class CarnetRDV
{
	public:
		CarnetRDV();

		bool creerRDV(std::string const& nom, std::string const& prenom, Date const& date, Horaire const& hDeb);
		bool creerRDV(std::string const &no;, std :: string const &prenom , Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		bool supprinerRDV(std::string const &nom );	
		bool ajouterPersonneRDV(std:::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne);
		bool supprimerPersonneRDV((std:::string const  &nomRDV, std::string const &NomPersonne, const std::string &PrenomPersonne);
		bool ajouterPersonne(cont std::string &prenom, const std::string &nom,std::string const &tel, std::string const  &mail);
		bool supprimerPersonne(std::string const &nom,std::string const &prenom);
		bool EstRDV(std::string const &nom,std::string const &prenom);
		std::string AfficherRDV(std::string const &nom);
		bool EstDispo(std::string const &nom, std::string const &prenom,Date const &date,Horaire const & hDeb,Horaire const  &hFin);
		std::string afficherPersonne(std::string const &nom , std::string const &prenom);
	private:
		listePersonne lp;
		ListeRDV lrdv;
		ListeLien ll;
					  
};

#endif
