#include "CarnetRDV.h"

MYSQL CarnetRDV::mysql;

bool CarnetRDV::import()
{

}

bool CarnetRDV::initialisation()
{
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(!mysql_real_connect(&mysql,"mysql-laverdure.alwaysdata.net","laverdure_rdv","1234567890","laverdure_carnetrdv",0,NULL,0))
        return false;

    return true;
}


bool CarnetRDV::creerRDV(std::string const& nom, Date const& date, Horaire const& hDeb)
{
    Horaire hFin = hDeb;
    hFin.decaleHeure(1);
    creerRDV(nom,date,hDeb,hFin);
}


bool CarnetRDV::creerRDV(std::string  nom, Date const& date, Horaire const& hDeb,Horaire const  &hFin)
{

    if(!lrdv.estDouble(nom))
    {
        MYSQL_BIND bind[4];
        MYSQL_STMT *stmt;
        std::string requete="INSERT INTO RDV(Nom_RDV, RDV_date, RDV_heuredeb, RDV_heureFin)values(?,?,?,?)";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        bind[0].buffer_type=MYSQL_TYPE_VARCHAR;
        std:: string lenomduRDV(nom);
        bind[0].buffer=&lenomduRDV[0];
        bind[0].is_null=0;
        unsigned long i = lenomduRDV.size();
        bind[0].length=&i;

        bind[1].buffer_type=MYSQL_TYPE_LONG;
        time_t j =  date.d_Time();
        bind[1].buffer=&j;
        bind[1].is_null=0;
        bind[1].length=0;

        bind[2].buffer_type=MYSQL_TYPE_VARCHAR;
        std::ostringstream oss;
        oss << hDeb.heure() <<":"<<hDeb.minute();
        std::string ladatedeb=oss.str();
        bind[2].buffer=&ladatedeb[0];
        bind[2].is_null=0;
        unsigned long jj = ladatedeb.size();
        bind[2].length=&jj;



        bind[3].buffer_type=MYSQL_TYPE_VARCHAR;
        std::ostringstream oss2;
        oss2 << hFin.heure() <<":"<<hFin.minute();
        std::string heurefin=oss2.str();
        bind[3].buffer=&heurefin[0];
        bind[3].is_null=0;
        unsigned long k = heurefin.size();
        bind[3].length=&k;
        mysql_stmt_bind_param(stmt,bind);
        mysql_stmt_execute(stmt);
        mysql_stmt_close(stmt);


        lrdv.ajouter(nom,date,hDeb,hFin);
    }

}

void CarnetRDV::supprimerPersonne_BDD(std::string nom,std::string prenom)
{
        MYSQL_BIND bind;
        MYSQL_STMT *stmt;
        std::string requete="delete from Personne where Id_Personne=? ";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        unsigned long int idpersonne = getIDPersonne(nom,prenom);
        bind.buffer_type= MYSQL_TYPE_LONG;
        bind.buffer=&idpersonne;
        bind.is_null= 0;
        bind.length = 0;

        mysql_stmt_bind_param(stmt,&bind);
        mysql_stmt_execute(stmt);
        std::cout << mysql_stmt_error(stmt)<<std::endl;
        mysql_stmt_close(stmt);
}
void CarnetRDV::supprimerRDV_BDD(std::string  nom)
{
        MYSQL_BIND bind;
        MYSQL_STMT *stmt;
        std::string requete="delete from RDV where idRDV=? ";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        unsigned long int idrdv = getIDRdv(nom);
        bind.buffer_type= MYSQL_TYPE_LONG;
        bind.buffer=&idrdv;
        bind.is_null= 0;
        bind.length = 0;

        mysql_stmt_bind_param(stmt,&bind);
        mysql_stmt_execute(stmt);
        std::cout << mysql_stmt_error(stmt)<<std::endl;
        mysql_stmt_close(stmt);
}

bool CarnetRDV::supprimerRDV(std::string const & nom)
{
    ///delete bdd
    ll.supprimer(lrdv.recherche(nom));
    lrdv.supprimer(nom);
    supprimerRDV_BDD(nom);

}

bool CarnetRDV::EstDispo(std::string  nom, std::string  prenom,Date const  &date,Horaire const& hDeb,Horaire  const& hFin)
{
	Personne *p=listp.rechercherPersonne(nom,prenom);

	if(!ll.recherche(p,date,hDeb,hFin))
        return true;
    else
    {
        return false;
    }
}


bool CarnetRDV::ajouterPersonne( std::string prenom,  std::string nom,std::string  tel, std::string   mail)
{
    if(!listp.estDouble(nom, prenom))
    {
        MYSQL_BIND bind[4];
        MYSQL_STMT *stmt;
        std::string requete="INSERT INTO Personne(Nom_Personne, Prenom_Personne, Tel_Personne, Mail_Personne)values(?,?,?,?)";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        bind[0].buffer_type=MYSQL_TYPE_VARCHAR;
        std:: string lenom(nom);
        bind[0].buffer=&lenom[0];
        bind[0].is_null=0;
        unsigned long i = lenom.size();
        bind[0].length=&i;

       bind[1].buffer_type=MYSQL_TYPE_VARCHAR;
       std::string leprenom(prenom);
        bind[1].buffer=&leprenom[0];
        bind[1].is_null=0;
        unsigned long j = leprenom.size();
        bind[1].length=&j;

        bind[2].buffer_type=MYSQL_TYPE_VARCHAR;
       std::string letel(tel);
        bind[2].buffer=&letel[0];
        bind[2].is_null=0;
        unsigned long k = letel.size();
        bind[2].length=&k;

        bind[3].buffer_type=MYSQL_TYPE_VARCHAR;
         std::string lemail(mail);
        bind[3].buffer=&lemail[0];
        bind[3].is_null=0;
          unsigned long l = lemail.size();
        bind[3].length=&l;

       mysql_stmt_bind_param(stmt,bind);
        mysql_stmt_execute(stmt);
        mysql_stmt_close(stmt);
    }
	listp.ajouter(prenom,nom,tel,mail);
	return 1;
}

int CarnetRDV::getIDPersonne(std::string nom,std::string prenom)
{
        MYSQL_BIND bind[2];
        MYSQL_STMT *stmt;
        std::string requete="Select Id_Personne from Personne where Nom_Personne=? and Prenom_Personne=?";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        bind[0].buffer_type=MYSQL_TYPE_VARCHAR;
        std:: string lenom(nom);
        bind[0].buffer=&lenom[0];
        bind[0].is_null=0;
        unsigned long i = lenom.size();
        bind[0].length=&i;

        bind[1].buffer_type=MYSQL_TYPE_VARCHAR;
        std::string leprenom(prenom);
        bind[1].buffer=&leprenom[0];
        bind[1].is_null=0;
        unsigned long j = leprenom.size();
        bind[1].length=&j;

        mysql_stmt_bind_param(stmt, bind);

        mysql_stmt_execute(stmt);

        memset(bind, 0, sizeof(bind));

        int id;
        bind[0].buffer_type= MYSQL_TYPE_INT24;
        unsigned long int z = sizeof(id);
        bind[0].buffer= (char *)&id;
        bind[0].is_null= 0;
        bind[0].length = &z;
        mysql_stmt_bind_result(stmt, bind);
        mysql_stmt_store_result(stmt);
        mysql_stmt_fetch(stmt);
        mysql_stmt_close(stmt);
        return id;
}


int CarnetRDV::getIDRdv(std::string nom)
{
        MYSQL_BIND bind[1];
        MYSQL_STMT *stmt;
        std::string requete="Select idRDV from RDV where Nom_RDV=?";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        bind[0].buffer_type=MYSQL_TYPE_VARCHAR;
        std:: string lenom(nom);
        bind[0].buffer=&lenom[0];
        bind[0].is_null=0;
        unsigned long i = lenom.size();
        bind[0].length=&i;
        mysql_stmt_bind_param(stmt, bind);
        mysql_stmt_execute(stmt);
        memset(bind, 0, sizeof(bind));

        int id;
        bind[0].buffer_type= MYSQL_TYPE_INT24;
        unsigned long int z = sizeof(id);
        bind[0].buffer= (char *)&id;
        bind[0].is_null= 0;
        bind[0].length = &z;
        mysql_stmt_bind_result(stmt, bind);
        mysql_stmt_store_result(stmt);
        mysql_stmt_fetch(stmt);
        mysql_stmt_close(stmt);

        return id;
}


void CarnetRDV::InsererLien(int idpers,int idrdv)
{
        MYSQL_BIND bind[2];
        memset(bind, 0, sizeof(bind));
        MYSQL_STMT *stmt;
        std::string requete="INSERT INTO Lien values(?,?);";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());
        bind[0].buffer_type= MYSQL_TYPE_LONG;
        bind[0].buffer=&idpers;
        bind[0].is_null= 0;
        bind[0].length = 0;
        bind[1].buffer_type= MYSQL_TYPE_LONG;
        bind[1].buffer=&idrdv;
        bind[1].is_null= 0;
        bind[1].length = 0;
        mysql_stmt_bind_param(stmt,bind);
        mysql_stmt_execute(stmt);
        std::cout<<mysql_stmt_error(stmt);
        mysql_stmt_close(stmt);
}

int CarnetRDV::ajouterPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne)
{
    ///insert bdd
    if(listp.estDouble(NomPersonne, PrenomPersonne))
    {
        if(lrdv.recherche(nomRDV) == nullptr)
        {
            return 1;
        }
        else
        {
            RDV *rdv = lrdv.recherche(nomRDV);
            Personne *pers = listp.rechercherPersonne(NomPersonne, PrenomPersonne);
            if(pers==nullptr)
                return 2;
            if(EstDispo(pers->nom,pers->prenom,rdv->d,rdv->hDeb,rdv->hFin))
            {
                int idpersonne=getIDPersonne(pers->nom,pers->prenom);
                int idRDV=getIDRdv(rdv->Nom);
                InsererLien(idpersonne,idRDV);
                ll.ajouter(pers, rdv);
                return 0;
            }
             else
             {
                 return 3;
             }


        }
    }
    else
    {
        return 2;
    }
}

void CarnetRDV::ModifierPersonne_BDD(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail)
{
        MYSQL_BIND bind[5];
        MYSQL_STMT *stmt;
        std::string requete="update Personne set Nom_Personne=?, Prenom_Personne=?, Tel_Personne=?, Mail_Personne=? where Id_Personne=?";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());
        bind[0].buffer_type=MYSQL_TYPE_VARCHAR;
        std:: string lenom(nouveaunom);
        bind[0].buffer=&lenom[0];
        bind[0].is_null=0;
        unsigned long i = lenom.size();
        bind[0].length=&i;
       bind[1].buffer_type=MYSQL_TYPE_VARCHAR;
       std::string leprenom(nouveauprenom);
        bind[1].buffer=&leprenom[0];
        bind[1].is_null=0;
        unsigned long j = leprenom.size();
        bind[1].length=&j;
        bind[2].buffer_type=MYSQL_TYPE_VARCHAR;
       std::string letel(tel);
        bind[2].buffer=&letel[0];
        bind[2].is_null=0;
        unsigned long k = letel.size();
        bind[2].length=&k;
        bind[3].buffer_type=MYSQL_TYPE_VARCHAR;
         std::string lemail(mail);
        bind[3].buffer=&lemail[0];
        bind[3].is_null=0;
          unsigned long l = lemail.size();
        bind[3].length=&l;
        unsigned long int idpersonne = getIDPersonne(nom,prenom);
        bind[4].buffer_type= MYSQL_TYPE_LONG;
        bind[4].buffer=&idpersonne;
        bind[4].is_null= 0;
        bind[4].length = 0;
        mysql_stmt_bind_param(stmt,bind);
        mysql_stmt_execute(stmt);
        std::cout << mysql_stmt_error(stmt)<<std::endl;
        mysql_stmt_close(stmt);
}

void CarnetRDV::supprimerPersonneDuRDV_BDD(std::string nomrdv,std::string nom,std::string prenom)
{
        MYSQL_BIND bind[2];
        MYSQL_STMT *stmt;
        std::string requete="delete from Lien where id_RDV=? and id_Personne=?";
        stmt= mysql_stmt_init(&CarnetRDV::mysql);
        mysql_stmt_prepare(stmt,requete.c_str(),requete.size());

        unsigned long int idrdv = getIDRdv(nomrdv);
        bind[0].buffer_type= MYSQL_TYPE_LONG;
        bind[0].buffer=&idrdv;
        bind[0].is_null= 0;
        bind[0].length = 0;

        unsigned long int idpersonne = getIDPersonne(nom,prenom);
        bind[1].buffer_type= MYSQL_TYPE_LONG;
        bind[1].buffer=&idpersonne;
        bind[1].is_null= 0;
        bind[1].length = 0;

        mysql_stmt_bind_param(stmt,bind);
        mysql_stmt_execute(stmt);
        std::cout << mysql_stmt_error(stmt)<<std::endl;
        mysql_stmt_close(stmt);
}
bool CarnetRDV::supprimerPersonneRDV(std::string nomRDV, std::string NomPersonne, std::string PrenomPersonne)
{
    ///insert bdd
    if(lrdv.recherche(nomRDV) != nullptr)
    {
        RDV *rdv = lrdv.recherche(nomRDV);
        ListePersonne lPerso(ll.recherche(rdv));
        if(lPerso.rechercherPersonne(NomPersonne, PrenomPersonne) == nullptr)
        {
            return false;
        }
        else
        {
            Personne *pers = listp.rechercherPersonne(NomPersonne, PrenomPersonne);
            ll.supprimer(pers, rdv);
            supprimerPersonneDuRDV_BDD(rdv->Nom,pers->nom,pers->prenom);
            return true;
        }
    }
    else
    {
        return false;
    }
}

ListePersonne CarnetRDV::getlesPersonneDuRDV(std::string const &nom)
{
    RDV *rdv = lrdv.recherche(nom);
    if(rdv == nullptr)
    {
        return ListePersonne();
    }
    else
    {
        ListePersonne lPerso(ll.recherche(rdv));
        return lPerso ;
    }
}

std::string CarnetRDV::AfficherRDV(std::string const &nom)
{
    ListePersonne pRDV(getlesPersonneDuRDV(nom));
    std::string chaine="";
    RDV *lerdv=lrdv.recherche(nom);
    if(!lerdv)
        return "";
    chaine=chaine+lerdv->Nom+"\n";
    chaine+=lerdv->d.str()+"\n";
    chaine+=lerdv->hDeb.str()+"\n";
    chaine+=lerdv->hFin.str()+"\n";
    chaine+= pRDV.afficherListpersonne();

    return chaine;
}

std::string CarnetRDV::afficherPersonne(std::string  nom , std::string  prenom)
{
    Personne* perso = listp.rechercherPersonne(nom,prenom);
    if(!perso)
        return "";

    std::string str;
    str = "\nNom: " + perso->nom;
    str += "\nPrénom: " + perso->prenom;
    str += "\nTel: " + perso->tel;
    str += "\nmail: " + perso->mail;

    return str;
}


bool CarnetRDV::EstRDV(std::string &nom,std::string &prenom)
{
    Personne* pers=listp.rechercherPersonne(nom,prenom);
    if(pers==nullptr)
        return false;
    else
    {

        ListeRDV lr(ll.recherche(pers));
        if(lr._tete==nullptr)
            return false;
        else
            return true;
    }
}

bool CarnetRDV::supprimerPersonne(std::string prenom,std::string nom)
{
    ///insert bdd
    if(EstRDV(nom,prenom)==false)
    {
        listp.supprimer(prenom,nom);
        supprimerPersonne_BDD(nom,prenom);
        return true;
    }
    else
        return false;
}

std::string CarnetRDV::afficherPersonnes() const
{
    return listp.afficherListpersonne();
}

void CarnetRDV::modifierPersonne(std::string prenom, std::string nom,std::string nouveaunom,std::string nouveauprenom,std::string tel, std::string mail)
{
    ///insert bdd
    listp.modifier(prenom,nom,nouveaunom,nouveauprenom,tel,mail);
    ModifierPersonne_BDD(prenom,nom,nouveaunom,nouveauprenom,tel,mail);

}
std::string CarnetRDV::AfficherRDVs_dune_Date(Date const &d)
{
    return lrdv.recherche(d).afficher();
}
