#include"projet.h"


void global (void)
{
	Adherent **a;
	int nbAd=0,r;
	int choix,choixAd,choixJeu,choixEmp,choixApMThe,choixI,EmpSupp,ApSupp,PSupp;
	char *jeuS;
	ListeJ j;
	ListeE e;
	ListeAt at;
	ListeP P;
	system("date +%d-%m-%Y> date.txt");
	//j=listeVide();
	
	j=chargement();
	a=chargeAd(&nbAd);
	printf("%d\n",nbAd );
	triEchange(a,nbAd);
	e=listeVideE();
	e=chargementEmp();
	at=chargementAt();
	choix=choixMenu();
	P=listeVideP();
	P=chargementPart(P);
	retard(e,a,nbAd);
	while(choix!=7)
	{
		switch(choix)
	
		{
			case 1 : choixAd=choixMenuAd();
				while(choixAd!=5)
				{
					switch(choixAd)
					{
						case 1 : afficher(a,nbAd);
							break;
						case 2 : a=ajouterAd(a,&nbAd,&r);
						         triEchange(a,nbAd);
							break;
						case 3 : SupprAd(a,&nbAd);
							break;
						case 4 : sauvegardeAd(a,&nbAd);
							break;
					
					}
					choixAd=choixMenuAd();
				}
				break;
			case 2 : choixJeu=choixMenuJeu();
				while(choixJeu!=5)
				{
					switch(choixJeu)
					{
						case 1 : afficherJeu(j);
							break;
						case 2 : j=ajouterJ(j);
							break;
						case 3 : 
						afficherJeu(j);
       					jeuS=AppartientGlobal(j);
						j=supp(j,jeuS);
							break;
						case 4 : sauvegarde(j);
							break;
					}
					choixJeu=choixMenuJeu();
				}
				break;
			case 3 : choixEmp=choixMenuEmp();
				while(choixEmp!=5)
				{
					switch(choixEmp)
					{
						case 1 : afficherEmp(e);
							break;
						case 2 : e=ajouterEmp(e,j,a,nbAd);
							break;
						case 3 : afficherEmp(e);
								 EmpSupp=AppartientGlobalEmp(e);
								 e=suppEmp(e,EmpSupp);
							break;
						case 4 : sauvegardeEmp(e);
							break;
					}
					choixEmp=choixMenuEmp();
				}
				break;
			case 4 : choixApMThe=choixMenuApMThe();
				while(choixApMThe!=5)
				{
					switch(choixApMThe)
					{
						case 1 : afficherAt(at);
							break;
						case 2 : at=ajouterAt(at,j);
							break;
						case 3 : afficherAt(at);
								 ApSupp=AppartientGlobalAT(at);
								 at=suppAt(at,ApSupp);
							break;
						case 4 : sauvegardeAt(at);
							break;
					}
					choixApMThe=choixMenuApMThe();
				}
				break;
			case 5 : retard(e,a,nbAd);
					affichRetard(a,nbAd);
				break;
			case 6 : choixI=choixMenuI();
					while(choixI!=5)
				{
					switch(choixI)
					{
						case 1 : afficherP(P);
							break;
						case 2 : P=ajouterP(P,a,nbAd,at);
							break;
						case 3 : afficherP(P);
								 PSupp=AppartientGlobalP(P);
								 P=suppP(P,PSupp);;
							break;
						case 4 : sauvegardeP(P);
							break;
					}
					choixI=choixMenuI();
				}
				break;					
		}
		choix=choixMenu();
	}
}

void afficherMenu (void)
{
	printf("\n-----Bienvenue à la ludothèque-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Adhérents\n");
	printf("2-Jeux\n");
	printf("3-Emprunts\n");
	printf("4-Après-midi thématiques\n");
	printf("5-Emprunteur ayant un retard\n");
	printf("6-Inscription a une après-midi thématique\n");
	printf("7-Quitter\n");
}

void afficherMenuAd (void)
{
	printf("\n-----Menu Adhérents-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Afficher les adhérents\n");
	printf("2-Ajouter un adhérent\n");
	printf("3-Supprimer un adhérent\n");
	printf("4-Sauvegarder\n");
	printf("5-Quitter\n");
}

void afficherMenuJeu (void)
{
	printf("\n-----Menu des Jeux-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Afficher les jeux\n");
	printf("2-Ajouter un jeu\n");
	printf("3-Supprimer un jeu\n");
	printf("4-Sauvegarder\n");
	printf("5-Quitter\n");
}
void afficherMenuEmp (void)
{
	printf("\n-----Menu des Emprunts-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Afficher les emprunts\n");
	printf("2-Ajouter un emprunt\n");
	printf("3-Supprimer un emprunt\n");
	printf("4-Sauvegarder\n");
	printf("5-Quitter\n");
}
void afficherMenuApMThe (void)
{
	printf("\n-----Menu des Après-midi thématiques-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Afficher les après-midi thématiques\n");
	printf("2-Ajouter une après-midi\n");
	printf("3-Supprimer une après-midi\n");
	printf("4-Sauvegarder\n");
	printf("5-Quitter\n");
}

void afficherMenuI (void)
{
	printf("\n-----Menu des Inscription aux après-midi thématiques-----\n");
	printf("Que souhaitez-vous faire ?\n\n");
	printf("1-Afficher les inscrits\n");
	printf("2-Ajouter une inscription\n");
	printf("3-Supprimer une inscription\n");
	printf("4-Sauvegarder\n");
	printf("5-Quitter\n");
}

int choixMenu (void)
{
	int code;
	afficherMenu();
	printf("\nVotre choix ?:\n");
	scanf("%d",&code);
	while(code<1 || code>7)
	{
		printf("Votre choix doit être comprit entre 1 et 7 \n");
		scanf("%d",&code);
	}
	return code;
}

int choixMenuAd (void)
{
	int codeAd;
	afficherMenuAd();
	printf("\nVotre choix ?:\n");
	scanf("%d",&codeAd);
	while(codeAd<1 || codeAd>5)
	{
		printf("Votre choix doit être comprit entre 1 et 5 \n");
		scanf("%d",&codeAd);
	}
	return codeAd;
}

int choixMenuJeu (void)
{
	int codeJ;
	afficherMenuJeu();
	printf("\nVotre choix ?:\n");
	scanf("%d",&codeJ);
	while(codeJ<1 || codeJ>5)
	{
		printf("Votre choix doit être comprit entre 1 et 5 \n");
		scanf("%d",&codeJ);
	}
	return codeJ;
}

int choixMenuEmp (void)
{
	int codeE;
	afficherMenuEmp();
	printf("\nVotre choix ?:\n");
	scanf("%d",&codeE);
	while(codeE<1 || codeE>5)
	{
		printf("Votre choix doit être comprit entre 1 et 5 \n");
		scanf("%d",&codeE);
	}
	return codeE;
}

int choixMenuApMThe (void)
{
	int codeApT;
	afficherMenuApMThe();
	printf("\nVotre choix ?:\n");
	scanf("%d",&codeApT);
	while(codeApT<1 || codeApT>5)
	{
		printf("Votre choix doit être comprit entre 1 et 5 \n");
		scanf("%d",&codeApT);
	}
	return codeApT;
}

int choixMenuI(void)
{
	int codeI;
	afficherMenuI();
	printf("\nVotre choix ?:\n");
	scanf("%d",&codeI);
	while(codeI<1 || codeI>5)
	{
		printf("Votre choix doit être comprit entre 1 et 5 \n");
		scanf("%d",&codeI);
	}
	return codeI;
}


ListeJ listeVide(void)
{
	return NULL;
}

ListeP listeVideP(void)
{
	return NULL;
}

ListeJ insertionEnTeteJ (ListeJ j,Jeu x)
{
	MaillonJ *m;
	m=(MaillonJ*)malloc(sizeof(MaillonJ));
	if(m==NULL)
	{
		printf("Problème malloc");
		exit(1);
	}
	m->J=x;
	m->suivJ=j;
	return m;
}

ListeJ ajouterJ(ListeJ j)
{
	Jeu jeux;
	printf("Saisir le numero de jeu : \n");
	scanf("%d%*c",&jeux.numJeu);
	printf("Saisir le nom du jeu\n");
	scanf("%s%*c",jeux.nomJeu);
	printf("Saisir le type du jeu\n");
	scanf("%s%*c",jeux.type);
	printf("Saisir l'etat(0/1)\n");
	scanf("%d%*c",&jeux.etat);
	if (jeux.etat!=0 && jeux.etat!=1)
	{
		printf("Veuillez mettre un etat comprit entre 1 et 0:\n");
		scanf("%d%*c",&jeux.etat);
	}
	j=insertionJ(j,jeux);
	sauvegarde(j);
	return j;
}


ListeJ insertionJ (ListeJ j, Jeu x)
{
	if(videJ(j))
		return insertionEnTeteJ(j,x);
	if(strcmp(j->J.nomJeu,x.nomJeu)>0)
		return insertionEnTeteJ(j,x);
	if(strcmp(j->J.nomJeu,x.nomJeu)==0 && j->J.numJeu!=x.numJeu)
		return insertionEnTeteJ(j,x);
	if(j->J.numJeu==x.numJeu)
		{
			printf("Le Jeu %s correspondant au numéro %d déjà présent dans la ludothèque\n",j->J.nomJeu,j->J.numJeu);
			exit(1);
		}
	j->suivJ=insertionJ(j->suivJ,x);
	return j;
}

Booleen videJ (ListeJ j)
{
	if(j==NULL)
		return vrai;
	return faux;
}

Jeu lireJeu(FILE * flot)
{
    Jeu j;
    fscanf(flot,"%d%*c",&j.numJeu);
    fgets(j.nomJeu,20,flot);
    j.nomJeu[strlen(j.nomJeu)-1]='\0';
    fgets(j.type,20,flot);
    j.type[strlen(j.type)-1]='\0';
    fscanf(flot,"%d%*c",&j.etat);
    return j;

}


ListeJ chargement(void)
{
	ListeJ l;
	l=listeVide();
	Jeu J;
	FILE *flot;
	flot=fopen("jeux.txt","r");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	J=lireJeu(flot);
	while(!feof(flot))
	{
		l=insertionJ(l,J);
		J=lireJeu(flot);
	}
	fclose(flot);
	return l;
	
}

void afficherJeu(ListeJ l)
{
	printf("Nom de Jeu\tType de Jeu\tNuméro de Jeu\tEtat\n");
	while (l!=NULL)
	{
		printf("%s     \t%s      \t%d      \t\t%d",l->J.nomJeu,l->J.type,l->J.numJeu,l->J.etat);
		l=l->suivJ;
		printf("\n");
	}
	printf("\n");
}

void sauvegarde(ListeJ l)
{
	FILE *flot;
	flot=fopen("jeux.txt","w");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	
			while(l!=NULL)
			{
				fprintf(flot, "%d\n%s\n%s\n%d\n\n",l->J.numJeu,l->J.nomJeu,l->J.type,l->J.etat);
				l=l->suivJ;
			}
	fclose(flot);

}			

ListeJ suppT(ListeJ l)
{
	MaillonJ *m;
	if (l==NULL)
	{
		printf("opération interdite\n");
		exit(1);
	}
	m=l;
	l=l->suivJ;
	free(m);
	return l;
}



ListeJ supp(ListeJ l, char * nomJ)
{
	
	if(videJ(l))
		return l;
	if(strcmp(l->J.nomJeu,nomJ)==0)
		return suppT(l);
	l->suivJ=supp(l->suivJ, nomJ);
	return l;
}

char * AppartientGlobal(ListeJ l)
{	
	int n;
	char choix;
	char *nomJ=NULL;
	nomJ=(char*)malloc(20*sizeof(char));
	printf("Quel jeu voulez-vous supprimer ?\n");
	scanf("%s%*c",nomJ);
	n=AppartientJ(l,nomJ);
	printf("%d\n",n );
	while(n==-1)
	{
		printf("Le jeu n'est pas présent dans la ludothèque\n");
		printf("Voulez-vous ressaisir le nom du Jeu ? (O/N)\n");
		scanf("%c%*c",&choix);
		if(choix=='O')
		{
			printf("Saisir le nom du Jeu :\n");
			scanf("%s%*c",nomJ);
			n=AppartientJ(l,nomJ);
		}
		if(choix=='N')
			exit(1);
	
	}
	return nomJ;
}

int AppartientJ(ListeJ l, char nomJ[])
{
		if(l==NULL)
			return -1;
		if(strcmp(l->J.nomJeu,nomJ)==0)
			return 1;
		if(strcmp(l->J.nomJeu,nomJ)<0)
			return AppartientJ(l->suivJ,nomJ);
		return -1;
	
}

int AppartientJnum(ListeJ l, int numJ)
{
	while(l!=NULL)
	{
		if(l->J.numJeu==numJ)
			return 1;
		if(l->J.numJeu<numJ)
			return -1;
		l=l->suivJ;
	}
	return -1;
}

Adherent * lireAd(FILE * flot)
{
    Adherent* a;
    a=(Adherent*)malloc(sizeof(Adherent));
    fscanf(flot,"%d%*c",&a->numAd);
    fgets(a->prenom,15,flot);
    a->prenom[strlen(a->prenom)-1]='\0';
    fgets(a->nom,15,flot);
    a->nom[strlen(a->nom)-1]='\0';
    fscanf(flot,"%d%*c",&a->dateInscri.jour);
    fscanf(flot,"%d%*c",&a->dateInscri.mois);
    fscanf(flot,"%d%*c",&a->dateInscri.annee);
    fscanf(flot,"%d%*c",&a->nbJeux);
    fscanf(flot,"%d%*c",&a->etatEmp);
    return a;

}

Adherent **chargeAd (int *nbAd)
{
    FILE *flot;
    Adherent **tAd;
    Adherent *a;
    int i=0;
    tAd=(Adherent * *)malloc(*nbAd*sizeof(Adherent*));
     if (tAd==NULL)
        {
            printf("Problème allocation\n");
            exit(1);
        }
    flot=fopen("adherents.txt","r");
    if(flot==NULL)
    {
        printf("Problème de lecture du fichier\n");
        exit(1);
    }
    a=lireAd(flot);
    while(!feof(flot))
    {
    	
        tAd[i]=a;
        a=lireAd(flot);
        i=i+1;
    }
    fclose(flot);
    *nbAd=i;

return tAd;
    
}


void DecalerGauche(Adherent** tAd, int nbAd, int n)
{
	while(n < (nbAd-1))
	{
		tAd[n] = tAd[n+1]; 
		n++;
	}
}

void SupprAd(Adherent** tAd, int *nbAd)
{
	int i, r;
	Adherent *a;
	a=(Adherent*)malloc(sizeof(Adherent));
	printf("Entrer le code de l'adhérent à supprimer\n");
	scanf("%d%*c",&a->numAd);
	i = rechercheDicoA(tAd,*nbAd,a, &r);
	if (r == 1)
	{
		printf("Adherent introuvable\n");
		return;
	}
	DecalerGauche(tAd,*nbAd, i);
	*nbAd = *nbAd - 1;
}

void afficherAd (Adherent *a)
{
		
	printf("%d\t", a->numAd);
	printf("%s    \t",a->prenom);
	printf("%s    \t",a->nom);
	printf("%2d/",a->dateInscri.jour);
	printf("%2d/",a->dateInscri.mois);
	printf("%4d\t\t",a->dateInscri.annee);
	printf("%d\t",a->nbJeux);
	printf("%d\n",a->etatEmp );
}
void afficher (Adherent **tAd, int nb)
{
	int i;
	printf("Num\tNom\t\tPrenom\t\tDate d'inscription\tNombre de jeux\tRetard\n");
	for(i=0;i<nb;i++)
		afficherAd(tAd[i]);
}

int rechercheDicoA (Adherent **tAd,int nb,Adherent *a,int *r)
{
	int inf=0,sup=nb-1,m;
	while (inf<=sup)
	{
		m=(inf+sup)/2;
		if(a->numAd==tAd[m]->numAd)
		{
			*r=-1;
			return m;
		}
		if(a->numAd<tAd[m]->numAd)
			sup=m-1;
		else
			inf=m+1;
	}
	*r=1;
	return inf;
}

Adherent ** ajouterAd (Adherent **tAd,int *nb,int *r)
{
	int n;
	Adherent * a;
	Adherent ** aux;
	FILE *flot;
	a=(Adherent*)malloc(sizeof(Adherent));
	printf("Numero du nouvel adherent :\n");
	scanf("%d%*c",&a->numAd);
	n=rechercheDicoA(tAd,*nb,a,r);
	while(*r==-1)
	{
		printf("Adherent deja present\n");
		printf("Tapez un nouveau numéro :\n");
		scanf("%d%*c",&a->numAd);
		n=rechercheDicoA(tAd,*nb,a,r);
	}
	printf("Prenom :\n");
	scanf("%s%*c",a->prenom);
	printf("Nom :\n");
	scanf("%s%*c",a->nom);
	flot=fopen("date.txt","r");
	if (flot==NULL)
	{
		printf("problème d'ouverture de fichier\n");
		exit(1);
	}
	fscanf(flot,"%d%*c",&a->dateInscri.jour);
	fscanf(flot,"%d%*c",&a->dateInscri.mois);
	fscanf(flot,"%d%*c",&a->dateInscri.annee);
	a->nbJeux=0;
	a->etatEmp=0;	
	*nb=*nb+1;
	aux=(Adherent**)realloc(tAd,*nb*sizeof(Adherent*));
	if(aux==NULL)
	{
		printf("Problème realloc\n");
		exit(1);
	}
	aux[*nb-1]=a;
	//free(a);
	fclose(flot);
	return aux;
	
}

void sauvegardeAd (Adherent **a, int *nb)
{
	FILE *flot;
	int i;
	flot=fopen("adherents.txt","w");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	for(i=0;i<*nb;i++)
		fprintf(flot,"%d\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n\n",a[i]->numAd,a[i]->prenom,a[i]->nom,a[i]->dateInscri.jour,a[i]->dateInscri.mois,a[i]->dateInscri.annee,a[i]->nbJeux,a[i]->etatEmp);
	fclose(flot);
}


ListeE listeVideE(void)
{
	return NULL;
}

ListeE insertionEnTeteEmp (ListeE k,Emprunt x)
{
	MaillonE *e;
	e=(MaillonE*)malloc(sizeof(MaillonE));
	if(e==NULL)
	{
		printf("Problème malloc\n");
		exit(1);
	}
	e->Emp=x;
	e->suivE=k;
	return e;
}

int compareAdEmp (Emprunt e,Adherent **tAd,int nbAd)
{
	int i=0;
	while(i<nbAd)
	{
	if(tAd[i]->numAd==e.adEmp)
		return 1;
	i=i+1;
	}
	return -1;
}

int compareJeuEmp (ListeJ l, Emprunt e)
{
	while(l!=NULL)
	{
		if(l->J.numJeu==e.jeuEmp)
			return 1;
		if(l->J.numJeu<e.jeuEmp)
			return -1;
		l=l->suivJ;
	}
	return -1;
}



ListeE ajouterEmp(ListeE k,ListeJ j,Adherent **tAd,int nbAd)
{
	Emprunt e;
	int i=0;
	FILE *flot;
	printf("Saisir le numero de l'emprunt : \n");
	scanf("%d%*c",&e.codeEmp);
	afficher(tAd,nbAd);
	printf("Saisir le numéro de l'adherent\n");
	scanf("%d%*c",&e.adEmp);
	i=compareAdEmp(e,tAd,nbAd);
	while(i!=1)
	{
		printf("Veuillez saisir un numéro d'adherent déjà présent\n");
		scanf("%d%*c",&e.adEmp);
		i=compareAdEmp(e,tAd,nbAd);
	}
	tAd[e.adEmp]->nbJeux=tAd[e.adEmp]->nbJeux + 1;
	afficherJeu(j);
	printf("Saisir le numéro du jeu emprunter:\n");
	scanf("%d%*c",&e.jeuEmp);
	while(compareJeuEmp(j,e)!=1)
	{
		printf("Veuillez saisir un numéro de jeu déjà présent :\n");
		scanf("%d%*c",&e.jeuEmp);
	}
	while(j!=NULL)
	{
		if (j->J.numJeu==e.jeuEmp)
			j->J.etat=1;
		j=j->suivJ;
	}
	flot=fopen("date.txt","r");
	if (flot==NULL)
	{
		printf("problème d'ouverture de fichier\n");
		exit(1);
	}
	fscanf(flot,"%d%*c",&e.dateEmp.jour);
	fscanf(flot,"%d%*c",&e.dateEmp.mois);
	fscanf(flot,"%d%*c",&e.dateEmp.annee);
	k=insertionE(k,e);
	fclose(flot);
	return k;
}


ListeE insertionE (ListeE k, Emprunt x)
{
	if(videE(k))
		return insertionEnTeteEmp(k,x);
	if(k->Emp.codeEmp>x.codeEmp)
		return insertionEnTeteEmp(k,x);
	if(k->Emp.codeEmp==x.codeEmp)
		{
			printf("L'emprunt %d correspondant à l'adhérent avec le numéro %d déjà présent dans la ludothèque\n",k->Emp.codeEmp,k->Emp.adEmp);
			exit(1);
		}
	k->suivE=insertionE(k->suivE,x);
	return k;
}

Booleen videE (ListeE k)
{
	if(k==NULL)
		return vrai;
	return faux;
}

Emprunt lireEmp(FILE * flot)
{
   	Emprunt k;
    fscanf(flot,"%d%*c",&k.codeEmp);
    fscanf(flot,"%d%*c",&k.adEmp);
    fscanf(flot,"%d%*c",&k.jeuEmp);
    fscanf(flot,"%d%*c",&k.dateEmp.jour);
    fscanf(flot,"%d%*c",&k.dateEmp.mois);
    fscanf(flot,"%d%*c",&k.dateEmp.annee);
    return k;

}


ListeE chargementEmp(void)
{
	ListeE k;
	k=listeVideE();
	Emprunt e;
	FILE *flot;
	flot=fopen("emprunts.txt","r");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	e=lireEmp(flot);
	while(!feof(flot))
	{
		k=insertionE(k,e);
		e=lireEmp(flot);
	}
	fclose(flot);
	return k;
	
}

void afficherEmp(ListeE k)
{
	printf("Numéro Emprunt\tNumero Adherent\tNumero Jeu\tDate d'emprunt\n");
	while (k!=NULL)
	{
		printf("%d\t\t%d\t\t%d\t\t",k->Emp.codeEmp,k->Emp.adEmp,k->Emp.jeuEmp);
		printf("%d/%d/%d",k->Emp.dateEmp.jour,k->Emp.dateEmp.mois,k->Emp.dateEmp.annee );
		k=k->suivE;
		printf("\n");
	}
	printf("\n");
}


void sauvegardeEmp(ListeE k)
{
	FILE *flot;
	flot=fopen("emprunts.txt","w");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
		while(k!=NULL)
		{	
	    fprintf(flot,"%d\n%d\n%d\n%d\n%d\n%d\n\n",k->Emp.codeEmp,k->Emp.adEmp,k->Emp.jeuEmp,k->Emp.dateEmp.jour,k->Emp.dateEmp.mois,k->Emp.dateEmp.annee);
		k=k->suivE;
		}
	fclose(flot);
}

ListeE suppTEmp(ListeE k)
{
	MaillonE *e;
	if (k==NULL)
	{
		printf("opération interdite\n");
		exit(1);
	}
	e=k;
	k=k->suivE;
	free(e);
	return k;
}

ListeE suppEmp(ListeE k, int numS)
{
	if(videE(k))
		return k;
	if(k->Emp.codeEmp==numS)
		return suppTEmp(k);
	k->suivE=suppEmp(k->suivE,numS);
	return k;
}


int AppartientEmp(ListeE k, int numE)
{
	while(k!=NULL)
	{
		if(numE==k->Emp.codeEmp)
			return 1;
		if(numE<k->Emp.codeEmp)
			return -1;
		k=k->suivE;
	}
	return -1;
}

int AppartientGlobalEmp(ListeE k)
{	
	int m;
	char choixE;
	int empSupp;
	printf("Quel emprunt voulez-vous supprimer ?\n");
	scanf("%d%*c",&empSupp);
	m=AppartientEmp(k,empSupp);
	while(m==-1)
	{
		printf("L'emprunt n'est pas présent dans la ludothèque\n");
		printf("Voulez-vous ressaisir le numéro de l'emprunt ? (O/N)\n");
		scanf("%c%*c",&choixE);
		if(choixE=='O')
		{
			printf("Saisir le numéro de l'emprunt:\n");
			scanf("%d%*c",&empSupp);
			m=AppartientEmp(k,empSupp);
		}
		if(choixE=='N')
			exit(1);
	
	}
	return empSupp;
}

void affichRetard (Adherent **a,int nbAd)
{
	int i=0;
	printf("Num\tNom\t\tPrenom\t\tDate d'inscription\tNombre de jeux\tRetard\n");
	while(i<nbAd)
	{
		if (a[i]->etatEmp==1)
			afficherAd(a[i]);
		i=i+1;
	}
}

void retard (ListeE k, Adherent ** a, int nbAd)
{
	int pb3;
	int i=0;
	while(k!=NULL)
	{
		pb3=calcul3semaines(k);
		if (pb3==-1)
		{
			while(i<nbAd)
			{
				if(a[i]->numAd==k->Emp.adEmp)
					a[i]->etatEmp=1;
				i=i+1;
			}
		}
		if (pb3==1)
		{
			while(i<nbAd)
			{
				if(a[i]->numAd==k->Emp.adEmp)
					a[i]->etatEmp=1;
				i=i+1;
			}
		}
		if(pb3==0)
			printf("Problème de calcul du retard\n");
		k=k->suivE;
	}
}

int calcul3semaines (ListeE k)
{
	FILE *flot;
	float jour,mois,annee;
	float sem,emp,auj;
	flot=fopen("date.txt","r");
	if (flot==NULL)
	{
		printf("pb ouv\n");
		exit(1);
	}
	fscanf(flot,"%f%*c",&jour);
	fscanf(flot,"%f%*c",&mois);
	fscanf(flot,"%f%*c",&annee);
	sem=21.0/365.0;
	emp=k->Emp.dateEmp.annee/1.0+k->Emp.dateEmp.mois/12.0+k->Emp.dateEmp.jour/365.0;
	auj=annee/1.0+mois/12.0+jour/365.0;
	if (auj-emp>sem)
		return -1;
	else 
		return 1;
	return 0;
}


ListeAt listeVideAt(void)
{
	return NULL;
}

ListeAt insertionEnTeteAt (ListeAt apremT,Aprem ApremThematique)
{
	MaillonAt *m;
	m=(MaillonAt*)malloc(sizeof(MaillonAt));
	if(m==NULL)
	{
		printf("Problème malloc");
		exit(1);
	}
	m->at=ApremThematique;
	m->suivAt=apremT;
	return m;
}

ListeAt ajouterAt(ListeAt apremT, ListeJ j)
{
	Aprem Ap;
	int n;
	char choix;
	printf("Saisir le numero de l'après-midi thématique : \n");
	scanf("%d%*c",&Ap.numAt);
	afficherJeu(j);
	printf("Saisir le nom du jeu de l'après-midi thématique\n");
	fgets(Ap.jeuAt,20,stdin);
	Ap.jeuAt[strlen(Ap.jeuAt)-1]='\0';
	n=AppartientJ(j,Ap.jeuAt);
	while(n==-1)
	{
		printf("Le jeu n'est pas présent dans la ludothèque\n");
		printf("Voulez-vous ressaisir le nom du Jeu ? (O/N)\n");
		scanf("%c%*c",&choix);
		if(choix=='O')
		{
			printf("Saisir le nom du Jeu :\n");
			scanf("%s%*c",Ap.jeuAt);
			n=AppartientJ(j,Ap.jeuAt);
		}
		if(choix=='N')
		exit(1);
	}
	
	printf("Saisir la date de l'après-midi thématique\n");
	printf("Jour:\n");
	scanf("%d%*c",&Ap.dateAt.jour);
	while(Ap.dateAt.jour<1 || Ap.dateAt.jour>31)
	{
			printf("Veuillez entrer un jour correct\n");
			printf("Jour:\n");
			scanf("%d%*c",&Ap.dateAt.jour);
	}
	printf("Mois;\n");
	scanf("%d%*c",&Ap.dateAt.mois);
	while(Ap.dateAt.mois<1 || Ap.dateAt.mois>12)
	{
			printf("Veuillez entrer un mois correct\n");
			printf("Mois:\n");
			scanf("%d%*c",&Ap.dateAt.mois);
	}
	printf("Année:\n");
	scanf("%d%*c",&Ap.dateAt.annee);
	while(Ap.dateAt.annee<2017 || Ap.dateAt.annee>2100)
	{
			printf("Veuillez entrer une année correcte\n");
			printf("Année:\n");
			scanf("%d%*c",&Ap.dateAt.annee);
	}
	printf("Saisir le nombre d'inscrit maximum\n");
	scanf("%d%*c",&Ap.nbPersAp);
	apremT=insertionAt(apremT,Ap);
	return apremT;
}


ListeAt insertionAt (ListeAt apremT,Aprem at)
{
	if(videAt(apremT))
		return insertionEnTeteAt(apremT,at);
	if(at.numAt<apremT->at.numAt)
		return insertionEnTeteAt(apremT,at);
	if(at.numAt==apremT->at.numAt)
		{
			printf("L'après-midi thématique n°%d est déjà enregistrée dans la ludothèque\n",at.numAt);
			exit(1);
		}
	apremT->suivAt=insertionAt(apremT->suivAt,at);
	return apremT;
}

Booleen videAt (ListeAt at)
{
	if(at==NULL)
		return vrai;
	return faux;
}

Aprem lireAprem(FILE * flot)
{
    Aprem A;
    fscanf(flot,"%d%*c",&A.numAt);
    fgets(A.jeuAt,20,flot);
    A.jeuAt[strlen(A.jeuAt)-1]='\0';
    fscanf(flot,"%d%*c",&A.dateAt.jour);
    fscanf(flot,"%d%*c",&A.dateAt.mois);
    fscanf(flot,"%d%*c",&A.dateAt.annee);
    fscanf(flot,"%d%*c",&A.nbPersAp);
    return A;

}


ListeAt chargementAt(void)
{
	ListeAt la;
	la=listeVideAt();
	Aprem A;
	FILE *flote;
	flote=fopen("am_thematiques.txt","r");
	if(flote==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	A=lireAprem(flote);
	while(!feof(flote))
	{
		la=insertionAt(la,A);
		A=lireAprem(flote);
	}
	fclose(flote);
	return la;
	
}

void afficherAt(ListeAt l)
{
	printf("Numéro de l'après-midi thématique\tNom du Jeu\tDate\t\tNombre de personne maximum\n");
	while (l!=NULL)
	{
		printf("%d     \t\t\t\t\t%s     \t%d/%d/%d      \t%d",l->at.numAt,l->at.jeuAt,l->at.dateAt.jour,l->at.dateAt.mois,l->at.dateAt.annee,l->at.nbPersAp);
		l=l->suivAt;
		printf("\n");
	}
	printf("\n");
}

void sauvegardeAt(ListeAt l)
{
	FILE *flot;
	flot=fopen("am_thematiques.txt","w");
	if(flot==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	while(l!=NULL)
	{
		fprintf(flot, "%d\n%s\n%d\n%d\n%d\n%d\n\n",l->at.numAt,l->at.jeuAt,l->at.dateAt.jour,l->at.dateAt.mois,l->at.dateAt.annee,l->at.nbPersAp);
		l=l->suivAt;
	}
	fclose(flot);	
}


ListeAt suppTAt(ListeAt l)
{
	MaillonAt *m;
	if (l==NULL)
	{
		printf("opération interdite\n");
		exit(1);
	}
	m=l;
	l=l->suivAt;
	free(m);
	return l;
}

ListeAt suppAt(ListeAt l, int numAth)
{
	
	if(videAt(l))
		return l;
	if(l->at.numAt==numAth)
		return suppTAt(l);
	l->suivAt=suppAt(l->suivAt, numAth);
	return l;
}


int AppartientGlobalAT(ListeAt l)
{	
	int n;
	int numAt;
	char choix;
	printf("Quel après-midi thématique voulez-vous supprimer ?\n");
	scanf("%d%*c",&numAt);
	n=AppartientAT(l,numAt);
	printf("%d",n);
	while(n==-1)
	{
		printf("Cette après-midi thématique n'est pas disponible\n");
		printf("Voulez-vous ressaisir le numéro ? (O/N)\n");
		scanf("%c%*c",&choix);
		if(choix=='O')
		{
			printf("Saisir le numéro de l'après-midi thématique :\n");
			scanf("%d%*c",&numAt);
			n=AppartientAT(l,numAt);
		}
		if(choix=='N')
			exit(1);
	}
	return numAt;
}
int AppartientAT(ListeAt l, int numAth)
{
		while(l!=NULL)
		{
		if(numAth==l->at.numAt)
				return 1;
		if(numAth<l->at.numAt)
				return -1;
		l=l->suivAt;
		}
		return -1;
}



void triEchange(Adherent **tAd, int nb)
{
	int pge;
	while(nb>1)
	{
		pge=PlusGrand(tAd,nb);
		echanger(tAd,pge,nb-1);
		nb=nb-1;
	}
}

void echanger(Adherent **tAd, int i, int j)
{
	Adherent *aux;
	aux=tAd[i];
	tAd[i]=tAd[j];
	tAd[j]=aux;
}

int PlusGrand(Adherent **tAd, int nb)
{
	int pge=0;
	int i;
	for(i=1;i<nb;i++)
		if(tAd[i]->numAd>tAd[pge]->numAd)
			pge=i;
	return pge;
}


ListeP chargementPart(ListeP P)
{
	
	Partic Pa;
	FILE* flot;
	flot=fopen("inscriptions_am_th.txt","r");
	if(flot == NULL)
	{
		printf("Problemème ouverture\n");
		exit(1);
	}
	fscanf(flot,"%d\n%d\n%d",&Pa.numIns,&Pa.numP,&Pa.numAt);
	while (!feof(flot))
	{
		P=insertionP(P, Pa);
		fscanf(flot,"%d\n%d\n%d",&Pa.numIns,&Pa.numP,&Pa.numAt);
		}
	fclose(flot);
	return P;
}

ListeP insertionEnTeteP (ListeP p,Partic P)
{
	maillonP *pa;
	pa=(maillonP*)malloc(sizeof(maillonP));
	if(pa==NULL)
	{
		printf("Problème malloc");
		exit(1);
	}
	pa->p=P;
	pa->suivP=p;
	return pa;
}

ListeP ajouterP(ListeP P,Adherent **tAd,int nb,ListeAt l)
{
	Partic Pa;
	int i,at;
	afficherP(P);
	printf("Saisir le numéro de l'inscription:\n");
	scanf("%d%*c",&Pa.numIns);
	afficher(tAd,nb);
	printf("Saisir le numero du participant : \n");
	scanf("%d%*c",&Pa.numP);
	i=compareNumAd(Pa,tAd,nb);
	printf("%d\n",i );
	if(i!=1)
	{
		printf("Adhérents non-inscrit dans la ludothèque\n" );
		exit(1);
	}
	afficherAt(l);
	printf("Saisir le numéro de l'après-midi thématique:\n");
	scanf("%d%*c",&Pa.numAt);
	at=AppartientAT(l,Pa.numAt);
	if(at==-1)
	{
		printf("Après-midi thématique inexistente\nVeuillez en saisir une correct");
		scanf("%d%*c",&Pa.numAt);
	}
	P=insertionP(P,Pa);
	return P;
}

int compareNumAd (Partic e,Adherent **tAd,int nbAd)
{
	int i=0;
	while(i<nbAd)
	{
	if(tAd[i]->numAd==e.numP)
		return 1;
	i=i+1;
	}
	return -1;
}


ListeP insertionP (ListeP P, Partic Par)
{
	if(P==NULL)
		return insertionEnTeteP(P,Par);
	if(P->p.numIns>Par.numIns)
		return insertionEnTeteP(P,Par);
	if(P->p.numIns==Par.numIns && P->p.numP!=Par.numP)
		return insertionEnTeteP(P,Par);
	if(P->p.numP==Par.numP && P->p.numAt==Par.numAt)
		
		{
			printf("L'adherents %d est déjà inscrit à cette après-midi thémaique\n",Par.numP);
			exit(1);
		}
	P->suivP=insertionP(P->suivP,Par);
	return P;
}

void afficherP(ListeP pa)
{
	{
	printf("Numéro d'inscription\tNuméro Adhérent\tNuméro Après-midi Thématique\n");
	while (pa!=NULL)
	{
		printf("%d\t\t\t%d\t\t%d",pa->p.numIns,pa->p.numP,pa->p.numAt);
		pa=pa->suivP;
		printf("\n");
	}
	printf("\n");
}
}

void sauvegardeP(ListeP pa)
{

	FILE *flote;
	flote=fopen("inscriptions_am_th.txt","w");
	if(flote==NULL)
	{
		printf("Problème d'ouverture du fichier\n");
		exit(1);
	}
	while(pa!=NULL)
	{
		fprintf(flote, "%d\n%d\n%d\n\n",pa->p.numIns,pa->p.numP,pa->p.numAt);
		pa=pa->suivP;
		
	}
	fclose(flote);
}

Booleen videP (ListeP l)
{
	if(l==NULL)
		return vrai;
	return faux;
}


ListeP suppEnTeteP(ListeP l)
{
	maillonP *m;
	if (l==NULL)
	{
		printf("opération interdite\n");
		exit(1);
	}
	m=l;
	l=l->suivP;
	free(m);
	return l;
}



ListeP suppP(ListeP l, int numPart)
{
	
	if(videP(l))
		return l;
	if(l->p.numIns==numPart)
		return suppEnTeteP(l);
	l->suivP=suppP(l->suivP, numPart);
	return l;
}




int AppartientGlobalP(ListeP l)
{	
	int n;
	char choix;
	int numInscri;
	printf("Quelle inscription voulez-vous supprimer ?\n");
	scanf("%d%*c",&numInscri);
	n=AppartientP(l,numInscri);
	while(n==-1)
	{
		printf("Cette inscription n'est pas présent dans la ludothèque\n");
		printf("Voulez-vous ressaisir un numéro d'inscription ? (O/N)\n");
		scanf("%c%*c",&choix);
		if(choix=='O')
		{
			printf("Saisir le numéro d'inscription :\n");
			scanf("%d%*c",&numInscri);
			n=AppartientP(l,numInscri);
		}
		if(choix=='N')
			exit(1);
	
	}
	return numInscri;
}

int AppartientP(ListeP l, int numInscri)
{
		if(l==NULL)
			return -1;
		if(l->p.numIns==numInscri)
			return 1;
		if(l->p.numIns<numInscri)
			return AppartientP(l->suivP,numInscri);
		return -1;
	
}
