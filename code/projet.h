#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct 
{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct

{
   	int numAd;
	char prenom[15];
    char nom [15];
	Date dateInscri;
   	int nbJeux;
   	int etatEmp;  //0 si pas en retard 1 si en retard

} Adherent;

typedef struct

{
    int numJeu;
    char nomJeu[15];
    char type[20];
    int etat;    //0 si le jeu est dans la ludo 1 si emprunter
} Jeu;

typedef struct maillonJ
{
    Jeu J;
    struct maillonJ *suivJ;
}MaillonJ,*ListeJ;

typedef enum {faux,vrai} Booleen;


typedef struct 
{
    int codeEmp;
    int adEmp;
    int jeuEmp;
    Date dateEmp;
}Emprunt;

typedef struct maillon
{
    Emprunt Emp;
    struct maillon *suivE;
}MaillonE,* ListeE;


typedef struct 
{
    int numAt;
    char jeuAt[20];
    Date dateAt;
    int nbPersAp;

}Aprem;

typedef struct maillonAt
{
    Aprem at;
    struct maillonAt *suivAt;
}MaillonAt,* ListeAt;

typedef struct 
{
    int numIns;
    int numP;
    int numAt;
}Partic;

typedef struct maillonP
{
    Partic p;
    struct maillonP *suivP;
}maillonP, *ListeP;



void global (void);

Adherent **chargeAd (int *nbAd);
Adherent * lireAd(FILE * flot);
void afficherAd (Adherent *a);
void afficher (Adherent **tAd, int max);
int rechercheDicoA (Adherent **tAd,int nb,Adherent *a,int *r);
Adherent ** ajouterAd (Adherent **tAd,int *nb,int *r);
void triEchange(Adherent **tAd, int nb);
void echanger(Adherent **tAd, int i, int j);
int PlusGrand(Adherent **tAd, int nb);
void DecalerGauche(Adherent** tAd, int nbAd, int n);
void SupprAd(Adherent** tAd, int *nbAd);
void sauvegardeAd (Adherent **a, int *nb);



ListeJ listeVide(void);
ListeJ insertionEnTeteJ (ListeJ j, Jeu x);
ListeJ insertionJ (ListeJ j, Jeu x);
Booleen videJ (ListeJ j);
ListeJ ajouterJ(ListeJ j);
void sauvegarde(ListeJ l);
void afficherJeu(ListeJ l);
ListeJ chargement(void);
Jeu lireJeu(FILE * flot);
ListeJ supp(ListeJ l, char *nomJ);
int AppartientJ(ListeJ l, char nomJ[]);
ListeJ suppT(ListeJ l);
int AppartientJnum(ListeJ l, int numJ);
char * AppartientGlobal(ListeJ l);



ListeE listeVideE(void);
ListeE insertionEnTeteEmp (ListeE k,Emprunt x);
ListeE ajouterEmp(ListeE k,ListeJ j,Adherent **tAd,int nbAd);
int compareAdEmp (Emprunt e,Adherent **tAd,int nbAd);
int compareJeuEmp (ListeJ l, Emprunt e);
ListeE insertionE (ListeE k, Emprunt x);
Booleen videE (ListeE k);
ListeE chargementEmp(void);
Emprunt lireEmp(FILE * flot);
void afficherEmp(ListeE k);
void sauvegardeEmp(ListeE k);
ListeE suppTEmp(ListeE k);
int AppartientGlobalEmp(ListeE k);
int AppartientEmp(ListeE k, int numE);
ListeE suppEmp(ListeE k, int numS);


void afficherMenu (void);
void afficherMenuAd (void);
void afficherMenuJeu (void);
void afficherMenuEmp (void);
void afficherMenuApMThe (void);
void afficherMenuI (void);
int choixMenu (void);
int choixMenuAd (void);
int choixMenuJeu (void);
int choixMenuEmp (void);
int choixMenuApMThe (void);
int choixMenuI(void);


ListeAt insertionAt (ListeAt apremT,Aprem at);
Booleen videAt (ListeAt at);
ListeAt ajouterAt(ListeAt apremT, ListeJ j);
ListeAt insertionEnTeteAt (ListeAt apremT,Aprem ApremThematique);
ListeAt listeVideAt(void);
Aprem lireAprem(FILE * flot);
void afficherAt(ListeAt lat);
ListeAt chargementAt(void);
int AppartientAT(ListeAt l, int numAth);
int AppartientGlobalAT(ListeAt l);
ListeAt suppAt(ListeAt l, int numAth);
ListeAt suppTAt(ListeAt l);
void sauvegardeAt(ListeAt l);

int calcul3semaines (ListeE k);
void retard (ListeE k, Adherent ** a, int nbAd);
void affichRetard (Adherent **a,int nbAd);


ListeP insertionP (ListeP P, Partic Par);
ListeP ajouterP(ListeP P,Adherent **tAd,int nb,ListeAt l);
ListeP insertionEnTeteP (ListeP p,Partic Pa);
ListeP chargementPart(ListeP P);
int compareNumAd (Partic e,Adherent **tAd,int nbAd);
void afficherP(ListeP pa);
ListeP listeVideP(void);
void sauvegardeP(ListeP pa);
ListeP suppEnTeteP(ListeP l);
ListeP suppP(ListeP l, int numPart);
int AppartientGlobalP(ListeP l);
int AppartientP(ListeP l, int numInscri);
Booleen videP (ListeP l);
