
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
                std::cin.ignore();
                carnet->modifierPersonne(prenom,nom,newnom,newprenom,tel,mail);
            }
                break;

            case '2':
                {
                    std::string str;
                    do
                    {
                        std::cout<<"Voulez vous vraiment supprimer cette personne ? o/n"<<std::endl;
                        std::cout <<str;
                        std::cin >> str;
                        std::cin.ignore();
                    }
                    while(str != "o" && str !="O" && str != "N" && str !="n");
                    if(str=="o" || str=="0")
                    {
                         if(carnet->supprimerPersonne(prenom,nom))
                         {
                            std::cout << "Erreur la personne doit tout d'abord ne plus avoir de RDV"<<std::endl;
                         }
                    }
                    boucle=false;
                    CLEAR();
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
                std::cin.ignore();
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


void menuRDV(std::string nomRDV, CarnetRDV *carnet)
{
    bool boucle;
    CLEAR();
	do
	{
        std::cout << "==== Gestion du RDV ====\n";
        std::cout << "1. Affichage des personnes du RDV\n";
        std::cout << "2. Ajouter une personne du RDV\n";
        std::cout << "3. Supprimer une personne du RDV\n";
        std::cout << "4. Supprimer le RDV du RDV\n";
        std::cout << "R. Retour\n";

		 boucle = true;
		char choix = entrerChar();

		switch(choix)
		{
            case '1':
                std::cout <<carnet->AfficherRDV(nomRDV)<<std::endl;
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

                    int r = carnet->ajouterPersonneRDV(nomRDV,s1,s2);

                    if(r == 2)
                    {
                        r = carnet->ajouterPersonneRDV(nomRDV,s2,s1);
                        if(r == 2)
                            std::cout << "La personne n'existe pas.\n";
                    }

                    if(r == 3)
                    {
                        std::cout << "La personne est indisponible.\n";
                    }


                }
                pause();
                CLEAR();
                break;
            case'3':
                {
                    std::string s1, s2, str;
                    std::istringstream iss;
                    std::cout << "Entrez le nom d'une personne: ";
                    std::getline(std::cin,str);
                    iss.str(str);
                    iss >> s1 >> s2;
                   if( !carnet->supprimerPersonneRDV(nomRDV,s1,s2))
                   {
                        if( !carnet->supprimerPersonneRDV(nomRDV,s2,s1))
                        {
                            std::cout << "La personne n'est pas dans le rdv"<<std::endl;
                        }
                   }
                    pause();
                    CLEAR();
                }
            break;
            case '4':
            {
                                    std::string str;
                    do
                    {
                        std::cout<<"Voulez vous vraiment supprimer ce RDV ? o/n"<<std::endl;
                        std::cout <<str;
                        std::cin >> str;
                        std::cin.ignore();
                    }
                    while(str != "o" && str !="O" && str != "N" && str !="n");
                    if(str=="o" || str=="0")
                    {
                         bool erreur;
                         erreur=carnet->supprimerRDV(nomRDV);
                         if(erreur)
                         {
                           // std::cout << "Erreur la personne doit tout d'abord ne plus avoir de RDV"<<std::endl;
                         }
                    }
                    boucle=false;
                    pause();
                    CLEAR();

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
     bool boucle;
    CLEAR();
	do
	{
        std::cout << "==== Gestion RDV ====\n";
        std::cout << "1. Affichage de tout les RDV d'une date\n";
        std::cout << "2. Recherche RDV\n";
        std::cout << "3. Ajouter RDV\n";
        std::cout << "R. Retour\n";

		boucle = true;
		char choix = entrerChar();

		switch(choix)
		{
		    case'1':
		    {
                std::cout << "Saisir une Date jj/mm/aaaa" << std::endl;
                int j,m,a;
                char c;
                std::cin >>j>>c>>m>>c>>a;
                std::cin.ignore();
                std::cout<< carnet->AfficherRDVs_dune_Date(Date(j,m,a));
                pause();
                CLEAR();
		    }
            break;

            case'2':
            {
                 std::cout << "Saisir le nom du RDV" << std::endl;
                 std::string nomrdv;

                std::getline(std::cin,nomrdv);
                  if(carnet->AfficherRDV(nomrdv)!="")
                  {
                      menuRDV(nomrdv,carnet);
                  }
                  else
                  {
                      std::cout << "Erreur le rdv '"<<nomrdv<<"' n\'existe pas "<<std::endl;
                  }

               pause();
                CLEAR();


            }
            break;
            case'3':
                {
                    std::string nomRDV;
                    std::cout << "Saisir le Nom du RDV" << std::endl;
                    std::cin >>nomRDV;
                    std::cout << "Saisir une Date jj/mm/aaaa" << std::endl;
                    int j,m,a,hdebut,hfin,mdebut,mfin;
                    char c;
                    std::cin >>j>>c>>m>>c>>a;
                    std::cout << "Saisir Heure debut hh:mm" << std::endl;
                    std::cin >> hdebut>>c>>mdebut;
                    std::cin.ignore();
    //               std::cout << "Saisir Heure fin hh:mm" << std::endl;
    //               std::cin >> hfin>>c>>mfin;
                    carnet->creerRDV(nomRDV,Date(j,m,a),Horaire(hdebut,mdebut),Horaire(hdebut+1,mdebut+1));
                    pause();
                    CLEAR();
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
