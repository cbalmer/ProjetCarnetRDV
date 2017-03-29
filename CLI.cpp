
#include "CLI.h"

void pause()
{
    std::cout << "Appuyez sur ENTRÉE pour continuer...";
    std::string s;
    std::getline(std::cin,s);
}

char entrerChar()
{
    char c;
	std::cout << "> ";
	std::istringstream iss;

	std::string str;
	std::getline(std::cin, str);

	iss.str(str);
	iss >> c;

	return std::tolower(c);
}

std::string entrerChaine()
{
	std::cout << "> ";
	std::string str;
	std::getline(std::cin, str);

	return str;
}

void menuPersonne(std::string nom, std::string prenom, CarnetRDV* carnet)
{
    bool boucle;
    CLEAR();
	do
	{
        std::cout << carnet->afficherPersonne(nom,prenom);
        std::cout << "\n==== Gestion Personnes ====\n";
        std::cout << "1. Modifier  la personne\n";
        std::cout << "2. Supprimer la personne\n";
        std::cout << "R. Retour\n";
		boucle = true;
		char choix = entrerChar();

		switch(choix)
		{
            case '1':
            {
                std::string newnom, newprenom,tel,mail;
                std::cout << "Entrez le nom de la personne: ";
                std::cin >> newnom;
                std::cout << "Entrez le prenom de la personne: ";
                std::cin >> newprenom;
                std::cout << "Entrez le tel de la personne: ";
                std::cin >> tel;
                std::cout << "Entrez le mail de la personne: ";
                std::cin >> mail;
                carnet->modifierPersonne(prenom,nom,newnom,newprenom,tel,mail);
            }
                break;

            case '2':
                    std::cout<<"Voulez vous vraiment supprimer cette personne ? o/n"<<std::endl;
                    std::string str:
                    std::cin >> str;


                break;

            case 'r':
                boucle = false;
            break;

            default:
                CLEAR();
				std::cout << "Entrée invalide.\n\n";
			break;
		}

	}while(boucle);
}

void gestionPersonnes(CarnetRDV* carnet)
{

    bool boucle;
    CLEAR();
	do
	{
        std::cout << "==== Gestion Personnes ====\n";
        std::cout << "1. Affichage liste\n";
        std::cout << "2. Recherche Personne\n";
        std::cout << "3. Ajouter Personne\n";
        std::cout << "R. Retour\n";

		boucle = true;
		char choix = entrerChar();

		switch(choix)
		{
            case '1':
                std::cout << "** Liste des personnes **\n";
                std::cout << carnet->afficherPersonnes();
                pause();
                CLEAR();
            break;




            case '2':
            {
                std::string s1, s2, str;
                std::istringstream iss;

                std::cout << "Entrez le nom d'une personne: ";
                std::getline(std::cin,str);
                iss.str(str);
                iss >> s1 >> s2;

                if((str = carnet->afficherPersonne(s1, s2)) == "")
                {
                    if((str = carnet->afficherPersonne(s2, s1)) == "")
                    {
                        std::cout << "Cette personne n'existe pas.\n";
                    }
                    else
                        menuPersonne(s2,s1,carnet);
                }
                else
                    menuPersonne(s1,s2,carnet);

            }
            CLEAR();
            break;





            case '3':
            {
                std::string nom, prenom,tel,mail;


                std::cout << "Entrez le nom de la personne: ";
                std::cin >> nom;
                std::cout << "Entrez le prenom de la personne: ";
                std::cin >> prenom;
                std::cout << "Entrez le tel de la personne: ";
                std::cin >> tel;
                std::cout << "Entrez le mail de la personne: ";
                std::cin >> mail;
                bool erreur;
                erreur=carnet->ajouterPersonne(prenom,nom,tel,mail);
                if(!erreur)
                {
                    std::cout << "Erreur la personne existe déjà dans le carnet"<<std::endl;
                }
                else
                {
                    std::cout << "Insertion réussie !" <<  std::endl;
                }
            }
            break;

            case 'r':
                boucle = false;
            break;

            default:
                CLEAR();
				std::cout << "Entrée invalide.\n\n";
			break;
		}

	}while(boucle);
}

void gestionRDV(CarnetRDV* carnet)
{
}


void menuPrincipal(CarnetRDV* carnet)
{
    CLEAR();
    bool boucle;
	do
	{
        std::cout << "==== Menu principal ====\n";
        std::cout << "1. Gestion de personnes\n";
        std::cout << "2. Gestion des RDV\n";
        std::cout << "Q. Quitter\n";
		boucle = true;
		char choix = entrerChar();

		switch(choix)
		{
            case '1':
                gestionPersonnes(carnet);
                CLEAR();
            break;

            case '2':
                gestionRDV(carnet);
                CLEAR();
            break;

            case 'q':
                boucle = false;
            break;

			default:
                CLEAR();
				std::cout << "Entrée invalide.\n";
			break;
		}

	}while(boucle);
}


void cli(CarnetRDV* carnet)
{
	if(!carnet)
	{
		std::cerr << "[ERREUR] Le carnet est null." << std::endl;
		return;
	}

    menuPrincipal(carnet);
}
