#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#ifndef MAX
#define MAX 15
#endif
void free( void * pointer );
typedef enum { false, true } bool;
int N=0;
struct livraison{
bool status;
float prix;

};
struct promotion{
bool status;
float valeur;

};
struct date{
int j;
int m;
int a;
};

struct sante{
char nom[20];
char marque[20];
int reference;
int stock;
float prix;
struct date delai;
struct livraison livr;
char a_propos[255];

};
struct tech{
char nom[20];
int reference;
char marque[20];
int stock;
float prix;
char couleur[20];
struct promotion promo;
struct livraison livr;
char a_propos[255];

};
struct alimentation{
char nom[20];
int reference;
char marque[20];
int stock;
float prix;
struct date delai;
float poids;
struct livraison livr;
char a_propos[255];

};
struct vetement{
char nom[20];
int reference;
char marque[20];
int stock;
float prix;
char matiere[20];
char couleur[20];
char sexe[20];
char taille[20];
struct promotion promo;
struct livraison livr;
char a_propos[255];

};
struct l_sante{
struct sante val;
struct l_sante *suiv;
};
struct l_tech{
struct tech val;
struct l_tech *suiv;
};
struct l_alim{
struct alimentation val;
struct l_alim *suiv;
};
struct l_vet{
struct vetement val;
struct l_vet *suiv;
};


struct l_sante* L1=NULL;
struct l_tech* L2=NULL;
struct l_alim* L3=NULL;
struct l_vet* L4=NULL;

bool test_sante(struct sante a,struct l_sante* L){
	struct l_sante* aux;
	struct sante b;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(a.nom,b.nom)==0)&&(strcmp(a.marque,b.marque)==0)){
            return true;
        }
        aux=aux->suiv;
    }
    return false;
}

bool test_tech(struct tech a,struct l_tech* L){
	struct l_tech* aux;
	struct tech b;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(a.nom,b.nom)==0)&&(strcmp(a.marque,b.marque)==0)&&(strcmp(a.couleur,b.couleur)==0)){
            return true;
        }
        aux=aux->suiv;
    }
    return false;
}

bool test_alim(struct alimentation a,struct l_alim* L){
	struct l_alim* aux;
	struct alimentation b;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(a.nom,b.nom)==0)&&(strcmp(a.marque,b.marque)==0)&&(a.poids==b.poids)){
            return true;
        }
        aux=aux->suiv;
    }
    return false;
}

bool test_vet(struct vetement a,struct l_vet* L){
	struct l_vet* aux;
	struct vetement b;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
	if((strcmp(a.nom,b.nom)==0)&&(strcmp(a.marque,b.marque)==0)&&(strcmp(a.matiere,b.matiere)==0)&&(strcmp(a.sexe,b.sexe)==0)&&(strcmp(a.couleur,b.couleur)==0)&&(a.taille==b.taille)){
		return true;
	}
	aux=aux->suiv;
}
return false;

}


struct l_sante* ajouter_sante(struct l_sante* L,struct sante s_produit){
    struct l_sante* aux1;
    struct l_sante* aux2;
    aux1=(struct l_sante*) malloc (sizeof (struct l_sante));
    aux1->val=s_produit;
    aux1->suiv=NULL;
    if(L==NULL){
        L=aux1;
    }
    else{
        aux2=L;
        while(aux2->suiv!=NULL){
            aux2=aux2->suiv;
        }
        aux2->suiv=aux1;

    }
    return(L);
}

struct l_tech* ajouter_tech(struct l_tech* L,struct tech t_produit){
    struct l_tech* aux1;
    struct l_tech* aux2;
    aux1=(struct l_tech*) malloc (sizeof (struct l_tech));
    aux1->val=t_produit;
    aux1->suiv=NULL;
    if(L==NULL){
        L=aux1;
    }
    else{
        aux2=L;
        while(aux2->suiv!=NULL){
            aux2=aux2->suiv;
        }
        aux2->suiv=aux1;

    }
    return(L);

}

struct l_alim* ajouter_alim(struct l_alim* L,struct alimentation a_produit){
    struct l_alim* aux1;
    struct l_alim* aux2;
    aux1=(struct l_alim*) malloc (sizeof (struct l_alim));
    aux1->val=a_produit;
    aux1->suiv=NULL;
    if(L==NULL){
        L=aux1;
    }
    else{
        aux2=L;
        while(aux2->suiv!=NULL){
            aux2=aux2->suiv;
        }
        aux2->suiv=aux1;

    }
    return(L);
}

struct l_vet* ajouter_vetement(struct l_vet* L,struct vetement v_produit){
    struct l_vet* aux1;
    struct l_vet* aux2;
    aux1=(struct l_vet*) malloc (sizeof (struct l_vet));
    aux1->val=v_produit;
    aux1->suiv=NULL;
    if(L==NULL){
        L=aux1;
    }
    else{
        aux2=L;
        while(aux2->suiv!=NULL){
            aux2=aux2->suiv;
        }
        aux2->suiv=aux1;

    }
    return(L);
} 
void rech_cle1(struct l_sante* L,char* c){
    struct l_sante* aux;
	struct sante b;
	int p=0;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(c,b.nom)==0)||(strcmp(c,b.marque)==0)){
        	p=p+1;
        	if(p==1){char *row1[] = {"Nom", "Marque", "Reference"};
			printf("%*s | %*s | %*s\n", -15, row1[0], -MAX, row1[1], MAX, row1[2]);
			}
            printf("%-15s | %-15s | %15i\n",b.nom,b.marque,b.reference);
            
        }
        aux=aux->suiv;
    }
    if(p==0){printf("Aucun Produit contient ce cle!!\n");
	}
}
void rech_cle2(struct l_tech* L,char* c){
    struct l_tech* aux;
	struct tech b;
	int p=0;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(c,b.nom)==0)||(strcmp(c,b.marque)==0)||(strcmp(c,b.couleur)==0)){
        	p=p+1;
        	if(p==1){char *row1[] = {"Nom", "Marque", "Couleur", "Reference"};
			printf("%*s | %*s | %*s | %*s\n", -15, row1[0], -MAX, row1[1], -MAX, row1[2], MAX, row1[3]);
			}
            printf("%-15s | %-15s | %-15s | %15i\n",b.nom,b.marque,b.couleur,b.reference);
            
        }
        aux=aux->suiv;
    }
    if(p==0){printf("Aucun Produit contient ce cle!!\n");
	}
}
void rech_cle3(struct l_alim* L,char* c){
    struct l_alim* aux;
	struct alimentation b;
	int p=0;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(c,b.nom)==0)||(strcmp(c,b.marque)==0)||atof(c)==b.poids){
        	p=p+1;
        	if(p==1){char *row1[] = {"Nom", "Marque", "Poids", "Reference"};
			printf("%*s | %*s | %*s | %*s\n", -15, row1[0], -MAX, row1[1], -MAX, row1[2], MAX, row1[3]);
			}
            printf("%-15s | %-15s | %-15f | %15i\n",b.nom,b.marque,b.poids,b.reference);
            
        }
        aux=aux->suiv;
    }
    if(p==0){printf("Aucun Produit contient ce cle!!\n");
	}
	
}
void rech_cle4(struct l_vet* L,char* c){
    struct l_vet* aux;
	struct vetement b;
	int p=0;
	aux=L;
	while(aux!=NULL){
		b=aux->val;
        if((strcmp(c,b.nom)==0)||(strcmp(c,b.marque)==0)||(strcmp(c,b.sexe)==0)||(strcmp(c,b.taille)==0)||(strcmp(c,b.couleur)==0)||(strcmp(c,b.matiere)==0)){
        	p=p+1;
        	if(p==1){char *row1[] = {"Nom", "Marque", "Couleur", "Sexe", "Taille", "Matiere", "Reference"};
			printf("%*s | %*s | %*s | %*s| %*s| %*s| %*s\n", -15, row1[0], -MAX, row1[1], -MAX, row1[2], -MAX, row1[3], -MAX, row1[4], -MAX, row1[5], MAX, row1[6]);
			}
            printf("%-15s | %-15s | %-15s | %-15s | %-15s | %-15s | %15i\n",b.nom,b.marque,b.couleur,b.sexe,b.taille,b.matiere,b.reference);
        }
        aux=aux->suiv;
    }
    if(p==0){printf("Aucun Produit contient ce cle!!\n");
	}
	
}
void ajout(int i){
        int n1;
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                                 AJOUT D'UN PRODUIT\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Categories:\n\n");
        printf("1. Sante\n\n");
        printf("2. Technologies\n\n");
        printf("3. Alimentation et boissons\n\n");
        printf("4. Vetements\n\n");
        printf("\n0. Menu principale\n\n");
        printf("Choisir une categorie: ");
        scanf("%i",&n1);
        while((n1<0)||(n1>4)){
            printf("Entree invalide!!\n");
            printf("Categories:\n\n");
            printf("1. Sante\n\n");
            printf("2. Technologies\n\n");
            printf("3. Alimentation et boissons\n\n");
            printf("4. Vetements\n\n");
            printf("\n0. Menu principale\n\n");
            printf("Choisir une categorie: ");
            scanf("%i",&n1);
        }
        switch(n1){
            case 1:{
                struct sante s_produit;
                printf("------------------------------------------------------SANTE-------------------------------------------------------------\n");
                printf("Entrer le nom: ");
                scanf("%s",&s_produit.nom);
                printf("Entrer la marque: ");
                scanf("%s",&s_produit.marque);
                if(!test_sante(s_produit,L1)){
                	s_produit.reference=N+1;
                	N++;
                    printf("Entrer le prix: ");
                    scanf("%f",&s_produit.prix);
                    printf("Entrer la date d'exipration\n");
                    printf("jour: ");
                    scanf("%i",&s_produit.delai.j);
                    printf("mois: ");
                    scanf("%i",&s_produit.delai.m);
                    printf("annee: ");
                    scanf("%i",&s_produit.delai.a);
                    printf("livraison(oui/non): ");
                    char cha[4];
                    scanf("%s",&cha);
                    if(!strcmp(cha,"oui")){
                        s_produit.livr.status=true;
                        printf("Entrer le prix de la livraison:\n ");
                        scanf("%f",&s_produit.livr.prix);
                    }
                    else{
                       s_produit.livr.status=false;
                        s_produit.livr.prix=0;
                    }
                    printf("Entrer la description: ");
                    scanf("%s",&s_produit.a_propos);
                    //fgets(s_produit.a_propos,255,stdin);
                    printf("Entrer le stock: ");
                    scanf("%i",&s_produit.stock);
                    L1=ajouter_sante(L1,s_produit);
                    	int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |      Ajout     |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,s_produit.reference,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
                    printf("La reference du produit est: %i\n",N);
                }
                else{
                    int n;
                    struct l_sante* aux;
                    struct sante b,c;
                    aux=L1;
                    while(aux!=NULL){
                        b=aux->val;
                        if((strcmp(s_produit.nom,b.nom)==0)&&(strcmp(s_produit.marque,b.marque)==0)){
                        break;
                        }
                        else{
                            aux=aux->suiv;
                        }
                    }
                    printf("Le produit existe deja sous reference: %i\n",b.reference);
                    printf("Entrer le stock: ");
                    scanf("%i",&n);
                    (aux->val).stock+=n;
                    printf("Nouveau stock de produit: %i",(aux->val).stock);
                }
				//char c = N+'0';FILE *F1=fopen("Nbr_T.txt","w");fputs(c,F1);
                break;
            }
            case 2:{
                char ch2_1[4],ch2_2[4];
                struct tech t_produit;
                printf("--------------------------------------------------TECHNOLOGIES----------------------------------------------------------\n");
                printf("Entrer le nom: ");
                scanf("%s",t_produit.nom);
                printf("Entrer la marque: ");
                scanf("%s",t_produit.marque);
                printf("Entrer la couleur: ");
                scanf("%s",t_produit.couleur);
                if(!test_tech(t_produit,L2)){
                	t_produit.reference=N+1;
                	N++;
                	printf("Entrer le prix: ");
                    scanf("%f",&t_produit.prix);
                    printf("Livraison ?(oui/non): ");
                    scanf("%s",ch2_1);
                    if(!strcmp(ch2_1,"oui")){
                        t_produit.livr.status=true;
                        printf("Entrer le prix de la livraison: ");
                        scanf("%f",&t_produit.livr.prix);
                    }
                    else{
                        t_produit.livr.status=false;
                        t_produit.livr.prix=0;
                    }
                    printf("Promotion ?(oui/non): ");
                    scanf("%s",ch2_2);
                    if(!strcmp(ch2_2,"oui")){
                        t_produit.promo.status=true;
                        printf("Entrer la promotion: ");
                        scanf("%f",&t_produit.promo.valeur);
                    }
                    else{
                        t_produit.promo.status=false;
                        t_produit.promo.valeur=0;
                    }
                    printf("Entrer la description: ");
                    scanf("%s",&t_produit.a_propos);
                    printf("Entrer le stock: ");
                    scanf("%i",&t_produit.stock);
                    L2=ajouter_tech(L2,t_produit);
                    int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |      Ajout     |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,t_produit.reference,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");                fclose(F);
                    printf("La reference du produit est: %i\n",N);
				}
				else{
                    int n;

                    struct l_tech* aux;
                    struct tech b;
                    aux=L2;
                    while(aux!=NULL){
                        b=aux->val;
                        if((strcmp(t_produit.nom,b.nom)==0)&&(strcmp(t_produit.marque,b.marque)==0)&&(strcmp(t_produit.couleur,b.couleur)==0)){
                            break;
                        }
                        else{
                            aux=aux->suiv;
                        }
                    }
                    printf("Le produit existe deja sous reference: %i\n",b.reference);
                    printf("Entrer le stock: ");
                    scanf("%i",&n);
                    (aux->val).stock+=n;
                    printf("Nouveau stock de produit: %i",(aux->val).stock);
				}
                
                break;
            }
            case 3:{
                char ch3[4];
                struct alimentation a_produit;
                printf("------------------------------------------------ALIMENTATION ET BOISSONS------------------------------------------------\n");
                printf("Entrer le nom: ");
                scanf("%s",a_produit.nom);
                printf("Entrer la marque: ");
                scanf("%s",a_produit.marque);
                printf("Entrer le poids: ");
                scanf("%f",&a_produit.poids);
                if(!test_alim(a_produit,L3)){
                	a_produit.reference=N+1;
                	N++;
                	printf("Entrer le prix: ");
                    scanf("%f",&a_produit.prix);
                    printf("Entrer la date d'expiration\n");
                    printf("jour: ");
                    scanf("%i",&a_produit.delai.j);
                    printf("mois: ");
                    scanf("%i",&a_produit.delai.m);
                    printf("annee: ");
                    scanf("%i",&a_produit.delai.a);
                    printf("Livraison ?(oui/non): ");
                    scanf("%s",ch3);
                    if(!strcmp(ch3,"oui")){
                        a_produit.livr.status=true;
                        printf("Entrer le prix de la livraison: ");
                        scanf("%f",&a_produit.livr.prix);
                    }
                    else{
                        a_produit.livr.status=false;
                        a_produit.livr.prix=0;
                    }
                    printf("Entrer la description: ");
                    scanf("%s",&a_produit.a_propos);
                    //fgets(a_produit.a_propos,255,stdin);
                    printf("Entrer le stock: ");
                    scanf("%i",&a_produit.stock);
                    L3=ajouter_alim(L3,a_produit);
                    int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |      Ajout     |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,a_produit.reference,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
                    printf("La reference du produit est: %i\n",N);
				}
				else{
                    int n;
                    struct l_alim* aux;
                    struct alimentation b;
                    aux=L3;
                    while(1){
                        b=aux->val;
                        if((strcmp(a_produit.nom,b.nom)==0)&&(strcmp(a_produit.marque,b.marque)==0)&&(a_produit.poids==b.poids)){
                            break;
                        }
                        else{
                            aux=aux->suiv;
                        }
                    }
                    printf("Le produit existe deja sous reference: %i\n",b.reference);
                    printf("Entrer le stock: ");
                    scanf("%i",&n);
                    (aux->val).stock+=n;
                    printf("Nouveau stock de produit: %i",(aux->val).stock);
				}
				
                break;
            }
            case 4:{
                char ch4_1[4],ch4_2[4];
                struct vetement v_produit;
                printf("--------------------------------------------------------VETEMENT--------------------------------------------------------\n");
                printf("Entrer le nom: ");
                scanf("%s",v_produit.nom);
                printf("Entrer la marque: ");
                scanf("%s",v_produit.marque);
                printf("Entrer la couleur: ");
                scanf("%s",v_produit.couleur);
                printf("Entrer la matiere: ");
                scanf("%s",v_produit.matiere);
                printf("Entrer le sexe: ");
                scanf("%s",v_produit.sexe);
                printf("Entrer la taille: ");
                scanf("%s",v_produit.taille);
                if(!test_vet(v_produit,L4)){
                	v_produit.reference=N+1;
                	N++;
                	printf("Entrer le prix: ");
                    scanf("%f",&v_produit.prix);
                    printf("Livraison ?(oui/non): ");
                    scanf("%s",ch4_1);
                    if(!strcmp(ch4_1,"oui")){
                        v_produit.livr.status=true;
                        printf("Entrer le prix de la livraison: ");
                        scanf("%f",&v_produit.livr.prix);
                    }
                    else{
                        v_produit.livr.status=false;
                        v_produit.livr.prix=0;
                    }
                    printf("Promotion ?(oui/non): ");
                    scanf("%s",ch4_2);
                    if(!strcmp(ch4_2,"oui")){
                        v_produit.promo.status=true;
                        printf("Entrer la promotion: ");
                        scanf("%f",&v_produit.promo.valeur);
                    }
                    else{
                        v_produit.promo.status=false;
                        v_produit.promo.valeur=0;
                    }
                    printf("Entrer la description: ");
                    scanf("%s",&v_produit.a_propos);
                    //fgets(v_produit.a_propos,255,stdin);
                    printf("Entrer le stock: ");
                    scanf("%i",&v_produit.stock);
                    L4=ajouter_vetement(L4,v_produit);
                    int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |      Ajout     |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,v_produit.reference,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
                    printf("La reference du produit est: %i\n",N);
				}
				else{
                    int n;
                    struct l_vet* aux;
                    struct vetement b;
                    aux=L4;
                    while(aux!=NULL){
                        b=aux->val;
                        if((strcmp(v_produit.nom,b.nom)==0)&&(strcmp(v_produit.marque,b.marque)==0)&&(strcmp(v_produit.matiere,b.matiere)==0)&&(strcmp(v_produit.sexe,b.sexe)==0)&&(strcmp(v_produit.couleur,b.couleur)==0)&&(v_produit.taille==b.taille)){
                            break;
                        }
                        else{
                            aux=aux->suiv;
                        }
                    }
                    printf("Le produit existe deja sous reference: %i\n",b.reference);
                    printf("Entrer le stock: ");
                    scanf("%i",&n);
                    (aux->val).stock+=n;
                    printf("Nouveau stock de produit: %i",(aux->val).stock);
				}
				
                break;
            }
            case 0:i=9;break;
        }
}

void recherche(int i){
    int n1;
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                          RECHERCHE D'UN PRODUIT\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Categories:\n\n");
    printf("1. Sante\n\n");
    printf("2. Technologies\n\n");
    printf("3. Alimentation et boissons\n\n");
    printf("4. Vetements\n\n");
    printf("\n0. Menu principale\n\n");
    printf("Choisir une categorie: ");
    scanf("%i",&n1);
    while((n1<0)||(n1>4)){
            printf("\nEntree invalide!!\n");
            printf("Categories:\n\n");
            printf("1. Sante\n\n");
            printf("2. Technologies\n\n");
            printf("3. Alimentation et boissons\n\n");
            printf("4. Vetements\n\n");
            printf("\n0. Menu principale\n\n");
            printf("Choisir une categorie: ");
            scanf("%i",&n1);
    }
    switch(n1){
        case 1:{
            struct l_sante* aux;
            int r;
            bool trouve=false;
            aux=L1;
            printf("------------------------------------------------------SANTE-------------------------------------------------------------\n");
            char c[20];
            printf("Entrer un mot cle : ");
            scanf("%s",c);
            printf("\n");
            rech_cle1(L1,c);
            printf("\nEntrer la reference du produit : ");
            scanf("%i",&r);
            printf("\n");
            while((trouve==false)&&(aux!=NULL)){
                    if(r==(aux->val).reference){
                        trouve=true;
                    }
                    else{
                        aux=aux->suiv;
                    }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                printf("Nom: %s\n",(aux->val).nom);
                printf("Marque: %s\n",(aux->val).marque);
                printf("Reference: %i\n",(aux->val).reference);
                printf("Stock: %i\n",(aux->val).stock);
                printf("Prix: %f\n",(aux->val).prix);
                printf("Date d'expiration: %i/%i/%i\n",(aux->val).delai.j,(aux->val).delai.m,(aux->val).delai.a);
                if((aux->val).livr.status==false){
                    printf("Livraison: pas de livraison\n");
                }
                else{
                    printf("Livraison: %f\n",(aux->val).livr.prix);
                }
                printf("A propos: %s\n",(aux->val).a_propos);
            }
            break;
        }
        case 2:{
            struct l_tech* aux;
            int r;
            bool trouve=false;
            aux=L2;
            printf("--------------------------------------------------TECHNOLOGIES----------------------------------------------------------\n");
            char c[20];
            printf("Entrer un mot cle : ");
            scanf("%s",c);
            printf("\n");
            rech_cle2(L2,c);
            printf("\nEntrer la reference du produit : ");
            scanf("%i",&r);
            printf("\n");
            while((trouve==false)&&(aux!=NULL)){
                if(r==(aux->val).reference){
                    trouve=true;
                }
                else{
                    aux=aux->suiv;
                }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                printf("Nom: %s\n",(aux->val).nom);
                printf("Reference: %i\n",(aux->val).reference);
                printf("Marque: %s\n",(aux->val).marque);
                printf("Stock: %i\n",(aux->val).stock);
                printf("Prix: %f\n",(aux->val).prix);
                printf("Couleur: %s\n",(aux->val).couleur);
                if((aux->val).promo.status==false){
                    printf("Promotion: pas de promotion\n");
                }
                else{
                    printf("Promotion: %f\n",(aux->val).promo.valeur);
                }
                if((aux->val).livr.status==false){
                    printf("Livraison: pas de livraison\n");
                }
                else{
                    printf("Livraison: %f\n",(aux->val).livr.prix);
                }
                printf("A propos: %s\n",(aux->val).a_propos);
            }
            break;
        }
        case 3:{
            struct l_alim* aux;
            int r;
            bool trouve=false;
            aux=L3;
            printf("------------------------------------------------ALIMENTATION ET BOISSONS------------------------------------------------\n");
            char c[20];
            printf("Entrer un mot cle : ");
            scanf("%s",c);
            printf("\n");
            rech_cle3(L3,c);
            printf("\nEntrer la reference du produit : ");
            scanf("%i",&r);
            printf("\n");
            while((trouve==false)&&(aux!=NULL)){
                if(r==(aux->val).reference){
                    trouve=true;
                }
                else{
                    aux=aux->suiv;
                }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                printf("Nom: %s\n",(aux->val).nom);
                printf("Reference: %i\n",(aux->val).reference);
                printf("Marque: %s\n",(aux->val).marque);
                printf("Stock: %i\n",(aux->val).stock);
                printf("Prix: %f\n",(aux->val).prix);
                printf("Date d'expiration: %i/%i/%i\n",(aux->val).delai.j,(aux->val).delai.m,(aux->val).delai.a);
                printf("Poids: %f\n",(aux->val).poids);
                if((aux->val).livr.status==false){
                    printf("Livraison: pas de livraison\n");
                }
                else{
                    printf("Livraison: %f\n",(aux->val).livr.prix);
                }
                printf("A propos: %s\n",(aux->val).a_propos);
            }
            break;
        }
        case 4:{
            struct l_vet* aux;
            int r;
            bool trouve=false;
            aux=L4;
            printf("--------------------------------------------------------VETEMENT--------------------------------------------------------\n");
            char c[20];
            printf("Entrer un mot cle : ");
            scanf("%s",c);
            printf("\n");
            rech_cle4(L4,c);
            printf("\nEntrer la reference du produit : ");
            scanf("%i",&r);
            printf("\n");
            while((trouve==false)&&(aux!=NULL)){
                if(r==(aux->val).reference){
                    trouve=true;
                }
                else{
                    aux=aux->suiv;
                }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                printf("Nom: %s\n",(aux->val).nom);
                printf("Reference: %i\n",(aux->val).reference);
                printf("Marque: %s\n",(aux->val).marque);
                printf("Stock: %i\n",(aux->val).stock);
                printf("Prix: %f\n",(aux->val).prix);
                printf("Matiere: %s\n",(aux->val).matiere);
                printf("Couleur: %s\n",(aux->val).couleur);
                printf("Sexe: %s\n",(aux->val).sexe);
                printf("Taille: %s\n",(aux->val).taille);
                if((aux->val).promo.status==false){
                    printf("Promotion: pas de promotion\n");
                }
                else{
                    printf("Promotion: %f\n",(aux->val).promo.valeur);
                }
                if((aux->val).livr.status==false){
                    printf("Livraison: pas de livraison\n");
                }
                else{
                    printf("Livraison: %f\n",(aux->val).livr.prix);
                }
                printf("A propos: %s\n",(aux->val).a_propos);
            }
            break;
        }
        case 0:i=9;break;
    }
}

void supprimer(int i){
    int n1;
    int r;
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                           SUPPRESSION D'UN PRODUIT\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Categories:\n\n");
    printf("1. Sante\n\n");
    printf("2. Technologies\n\n");
    printf("3. Alimentation et boissons\n\n");
    printf("4. Vetements\n\n");
    printf("\n0. Menu principale\n\n");
    printf("Choisir une categorie: ");
    scanf("%i",&n1);
    while((n1<0)||(n1>4)){
            printf("Entree invalide!!\n");
            printf("Categories:\n\n");
            printf("1. Sante\n\n");
            printf("2. Technologies\n\n");
            printf("3. Alimentation et boissons\n\n");
            printf("4. Vetements\n\n");
            printf("\n0. Menu principale\n\n");
            printf("Choisir une categorie: ");
            scanf("%i",&n1);
    }
    switch(n1){
        case 1:{
            printf("Entrer la reference du produit a supprimer: ");
            scanf("%i",&r);
            struct l_sante* aux1;
            aux1=L1;
            if(r==(aux1->val).reference){
                L1=(L1->suiv);
                free(aux1);
            }
            else{
                if((aux1->suiv)==NULL){
                    printf("Le produit n'existe pas");
                }
                else{
                    struct l_sante* aux2;
                    aux2=(L1->suiv);
                    bool trouve=false;
                    while((trouve==false)&&(aux2!=NULL)){
                        if(r==(aux2->val).reference){
                            trouve=true;
                        }
                        else{
                            aux1=aux1->suiv;
                            aux2=aux2->suiv;
                        }
                    }
                    if(trouve==true){
                        aux1->suiv=aux2->suiv;
                        free(aux2);

                    }
                    else{
                        printf("Le produit n'existe pas");
                    }
                }
            }
            int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |   Suppression  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 2:{
            printf("Entrer la reference du produit a supprimer: ");
            scanf("%i",&r);
            struct l_tech* aux1;
            aux1=L2;
            if(r==(aux1->val).reference){
                L2=(L2->suiv);
                free(aux1);
            }
            else{
                if((aux1->suiv)==NULL){
                    printf("Le produit n'existe pas");
                }
                else{
                    struct l_tech* aux2;
                    aux2=(L2->suiv);
                    bool trouve=false;
                    while((trouve==false)&&(aux2!=NULL)){
                        if(r==(aux2->val).reference){
                            trouve=true;
                        }
                        else{
                            aux1=aux1->suiv;
                            aux2=aux2->suiv;
                        }
                    }
                    if(trouve==true){
                        aux1->suiv=aux2->suiv;
                        free(aux2);

                    }
                    else{
                        printf("Le produit n'existe pas");
                    }
                }
            }
            int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |   Suppression  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 3:{
            printf("Entrer la reference du produit a supprimer: ");
            scanf("%i",&r);
            struct l_alim* aux1;
            aux1=L3;
            if(r==(aux1->val).reference){
                L3=(L3->suiv);
                free(aux1);
            }
            else{
                if((aux1->suiv)==NULL){
                    printf("Le produit n'existe pas");
                }
                else{
                    struct l_alim* aux2;
                    aux2=(L3->suiv);
                    bool trouve=false;
                    while((trouve==false)&&(aux2!=NULL)){
                        if(r==(aux2->val).reference){
                            trouve=true;
                        }
                        else{
                            aux1=aux1->suiv;
                            aux2=aux2->suiv;
                        }
                    }
                    if(trouve==true){
                        aux1->suiv=aux2->suiv;
                        free(aux2);

                    }
                    else{
                        printf("Le produit n'existe pas");
                    }
                }
            }
            int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |   Suppression  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 4:{
            printf("Entrer la reference du produit a supprimer: ");
            scanf("%i",&r);
            struct l_vet* aux1;
            aux1=L4;
            if(r==(aux1->val).reference){
                L4=(L4->suiv);
                free(aux1);
            }
            else{
                if((aux1->suiv)==NULL){
                    printf("Le produit n'existe pas");
                }
                else{
                    struct l_vet* aux2;
                    aux2=(L4->suiv);
                    bool trouve=false;
                    while((trouve==false)&&(aux2!=NULL)){
                        if(r==(aux2->val).reference){
                            trouve=true;
                        }
                        else{
                            aux1=aux1->suiv;
                            aux2=aux2->suiv;
                        }
                    }
                    if(trouve==true){
                        aux1->suiv=aux2->suiv;
                        free(aux2);

                    }
                    else{
                        printf("Le produit n'existe pas");
                    }
                }
            }
            int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |   Suppression  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 0:i=9;break;
    }
}
void modifier(int i){
    int n1;
    char ch[20];
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                              MODIFICATION D'UN PRODUIT\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Categories:\n\n");
    printf("1. Sante\n\n");
    printf("2. Technologies\n\n");
    printf("3. Alimentation et boissons\n\n");
    printf("4. Vetements\n\n");
    printf("\n0. Menu principale\n\n");
    printf("Choisir une categorie: ");
    scanf("%i",&n1);
    while((n1<0)||(n1>4)){
            printf("\nEntree invalide!!\n");
            printf("Categories:\n\n");
            printf("1. Sante\n\n");
            printf("2. Technologies\n\n");
            printf("3. Alimentation et boissons\n\n");
            printf("4. Vetements\n\n");
            printf("\n0. Menu principale\n\n");
            printf("Choisir une categorie: ");
            scanf("%i",&n1);
    }
    switch(n1){
        case 1:{
            struct l_sante* aux;
            int r;
            bool trouve=false;
            int n2;
            aux=L1;
            printf("------------------------------------------------------SANTE-------------------------------------------------------------\n");
            printf("Entrer la reference du produit a modifier: ");
            scanf("%i",&r);
            while((trouve==false)&&(aux!=NULL)){
                    if(r==(aux->val).reference){
                        trouve=true;
                    }
                    else{
                        aux=(aux->suiv);
                    }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                char ch2[3];
                do{
                    printf("\n1.Nom\n");
                    printf("2.Marque\n");
                    printf("3.Stock\n");
                    printf("4.Prix\n");
                    printf("5.Date d'expiration\n");
                    printf("6.Livraison\n");
                    printf("7.A propos\n");
                    printf("\nChoisir l'element que vous souhaitez modifier: ");
                    scanf("%i",&n2);
                    while((n2<1)||(n2>7)){
                        printf("\nEntree invalide!!\n");
                        printf("\n1.Nom\n");
                        printf("2.Marque\n");
                        printf("3.Stock\n");
                        printf("4.Prix\n");
                        printf("5.Date d'expiration\n");
                        printf("6.Livraison\n");
                        printf("7.A propos\n");
                        printf("\nChoisir l'element que vous souhaitez modifier: ");
                        scanf("%i",&n2);
                    }
                        switch(n2){
                        case 1:{
                            printf("\nNom: ");
                            scanf("%s",aux->val.nom);
                            break;
                        }
                        case 2:{
                            printf("\nMarque: ");
                            scanf("%s",aux->val.marque);
                            break;
                        }
                        case 3:{
                            printf("\nStock: ");
                            scanf("%i",&aux->val.stock);
                            break;
                        }
                        case 4:{
                            printf("\nPrix: ");
                            scanf("%f",&aux->val.prix);
                            break;
                        }
                        case 5:{
                            printf("\nJour: ");scanf("%i",&aux->val.delai.j);
                            printf("Mois: ");scanf("%i",&aux->val.delai.m);
                            printf("Annee: ");scanf("%i",&aux->val.delai.a);
                            break;
                        }
                        case 6:{
                            char ch1[3];
                            printf("\nLivraison(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.livr.status=true;
                                printf("Prix: ");
                                scanf("%f",&aux->val.livr.prix);
                            }
                            else{
                                aux->val.livr.status=false;
                                aux->val.livr.prix=0;
                            }
                            break;
                        }
                        case 7:{
                            printf("\nA propos: ");
                            scanf("%s",aux->val.a_propos);
                            //fgets(aux->val.a_propos,255,stdin);
                            break;
                        }
                    }
                    printf("\nModifier un autre element?(oui/non): ");
                    scanf("%s",ch2);
                }
                while(!strcmp(ch2,"oui"));
            }
            int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                 %i/%-4i |  Modification  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 2:{
            struct l_tech* aux;
            int r;
            bool trouve=false;
            int n2;
            aux=L2;
            printf("--------------------------------------------------TECHNOLOGIES----------------------------------------------------------\n");
            printf("Entrer la reference du produit a modifier: ");
            scanf("%i",&r);
            while((trouve==false)&&(aux!=NULL)){
                    if(r==(aux->val).reference){
                        trouve=true;
                    }
                    else{
                        aux=aux->suiv;
                    }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                char ch2[3];
                do{
                    printf("\n1.Nom\n");
                    //printf("2.Reference\n");
                    printf("2.Marque\n");
                    printf("3.Stock\n");
                    printf("4.Prix\n");
                    printf("5.Couleur\n");
                    printf("6.Promotion\n");
                    printf("7.Livraison\n");
                    printf("8.A propos\n");
                    printf("\nChoisir l'element que vous souhaitez modifier: ");
                    scanf("%i",&n2);
                    while((n2<1)||(n2>8)){
                        printf("\nEntree invalide!!\n");
                        printf("\n1.Nom\n");
                        //printf("2.Reference\n");
                        printf("2.Marque\n");
                        printf("3.Stock\n");
                        printf("4.Prix\n");
                        printf("5.Couleur\n");
                        printf("6.Promotion\n");
                        printf("7.Livraison\n");
                        printf("8.A propos\n");
                        printf("\nChoisir l'element que vous souhaitez modifier: ");
                        scanf("%i",&n2);
                    }
                    switch(n2){
                        case 1:{
                            printf("\nNom: ");
                            scanf("%s",aux->val.nom);
                            break;
                        }
                       /* case 2:{
                            printf("\nReference: ");
                            scanf("%s",aux->val.reference);
                            break;
                        }*/
                        case 2:{
                            printf("\nMarque: ");
                            scanf("%s",aux->val.marque);
                            break;
                        }
                        case 3:{
                            printf("\nStock: ");
                            scanf("%i",&aux->val.stock);
                            break;
                        }
                        case 4:{
                            printf("\nPrix: ");
                            scanf("%f",&aux->val.prix);
                            break;
                        }
                        case 5:{
                            printf("\nCouleur: ");
                            scanf("%s",aux->val.couleur);
                            break;
                        }
                        case 6:{
                            char ch1[3];
                            printf("\nPromotion(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.promo.status=true;
                                printf("\nValeur: ");
                                scanf("%f",&aux->val.promo.valeur);
                            }
                            else{
                                aux->val.promo.status=false;
                                aux->val.promo.valeur=0;
                            }
                            break;
                        }
                        case 7:{
                            char ch1[3];
                            printf("\nLivraison(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.livr.status=true;
                                printf("\nPrix: ");
                                scanf("%f",&aux->val.livr.prix);
                            }
                            else{
                                aux->val.livr.status=false;
                                aux->val.livr.prix=0;
                            }
                            break;
                        }
                        case 8:{
                            printf("\nA propos: ");
                            scanf("%s",aux->val.a_propos);
                            //fgets(aux->val.a_propos,255,stdin);
                            break;
                        }
                    }
                    printf("\nModifier un autre element?(oui/non): ");
                    scanf("%s",ch2);
                }
                while(!strcmp(ch2,"oui"));
            }
                        int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |  Modification  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 3:{
            struct l_alim* aux;
            int r;
            bool trouve=false;
            int n2;
            aux=L3;
            printf("----------------------------------------------ALIMENNTATION ET BOISSONS------------------------------------------------\n");
            printf("Entrer la reference du produit a modifier: ");
            scanf("%i",&r);
            while((trouve==false)&&(aux!=NULL)){
                    if(r==(aux->val).reference){
                        trouve=true;
                    }
                    else{
                        aux=aux->suiv;
                    }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                char ch2[3];
                do{
                    printf("\n1.Nom\n");
                    //printf("2.Reference\n");
                    printf("2.Marque\n");
                    printf("3.Stock\n");
                    printf("4.Prix\n");
                    printf("5.Date d'expiration\n");
                    printf("6.Poids\n");
                    printf("7.Livraison\n");
                    printf("8.A propos\n");
                    printf("\nChoisir l'element que vous souhaitez modifier: ");
                    scanf("%i",&n2);
                    while((n2<1)||(n2>8)){
                        printf("\nEntree invalide!!\n");
                        printf("\n1.Nom\n");
                        //printf("2.Reference\n");
                        printf("2.Marque\n");
                        printf("3.Stock\n");
                        printf("4.Prix\n");
                        printf("5.Date d'expiration\n");
                        printf("6.Poids\n");
                        printf("7.Livraison\n");
                        printf("8.A propos\n");
                        printf("\nChoisir l'element que vous souhaitez modifier: ");
                        scanf("%i",&n2);
                    }
                    switch(n2){
                        case 1:{
                            printf("\nNom: ");
                            scanf("%s",aux->val.nom);
                            break;
                        }
                       /* case 2:{
                            printf("\nReference: ");
                            scanf("%s",aux->val.reference);
                            break;
                        }*/
                        case 2:{
                            printf("\nMarque: ");
                            scanf("%s",aux->val.marque);
                            break;
                        }
                        case 3:{
                            printf("\nStock: ");
                            scanf("%i",&aux->val.stock);
                            break;
                        }
                        case 4:{
                            printf("\nPrix: ");
                            scanf("%f",&aux->val.prix);
                            break;
                        }
                        case 5:{
                            printf("\nJour: ");scanf("%i",&aux->val.delai.j);
                            printf("Mois: ");scanf("%i",&aux->val.delai.m);
                            printf("Annee: ");scanf("%i",&aux->val.delai.a);
                            break;
                        }
                        case 6:{
                            printf("\nPoids: ");
                            scanf("%f",&aux->val.poids);
                            break;
                        }
                        case 7:{
                            char ch1[3];
                            printf("\nLivraison(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.livr.status=true;
                                printf("\nPrix: ");
                                scanf("%f",&aux->val.livr.prix);
                            }
                            else{
                                aux->val.livr.status=false;
                                aux->val.livr.prix=0;
                            }
                            break;
                        }
                        case 8:{
                            printf("\nA propos: ");
                            scanf("%s",aux->val.a_propos);
                            //fgets(aux->val.a_propos,255,stdin);
                            break;
                        }
                    }
                    printf("\nModifier un autre element?(oui/non): ");
                    scanf("%s",ch2);
                }
                while(!strcmp(ch2,"oui"));
            }
                int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |  Modification  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 4:{
            struct l_vet* aux;
            int r;
            bool trouve=false;
            int n2;
            aux=L4;
            printf("--------------------------------------------------------VETEMENT--------------------------------------------------------\n");
            printf("Entrer la reference du produit a modifier: ");
            scanf("%i",&r);
            while((trouve==false)&&(aux!=NULL)){
                    if(r==(aux->val).reference){
                        trouve=true;
                    }
                    else{
                        aux=aux->suiv;
                    }
            }
            if(trouve==false){
                printf("\nLe produit n'existe pas\n");
            }
            else{
                char ch2[3];
                do{
                    printf("\n1.Nom\n");
                    //printf("2.Reference\n");
                    printf("2.Marque\n");
                    printf("3.Stock\n");
                    printf("4.Prix\n");
                    printf("5.Matiere\n");
                    printf("6.Couleur\n");
                    printf("7.Sexe\n");
                    printf("8.Taille\n");
                    printf("9.Promotion\n");
                    printf("10.Livraison\n");
                    printf("11.A propos\n");
                    printf("\nChoisir l'element que vous souhaitez modifier: ");
                    scanf("%i",&n2);
                    while((n2<1)||(n2>11)){
                        printf("\nEntree invalide!!\n");
                        printf("\n1.Nom\n");
                        //printf("2.Reference\n");
                        printf("2.Marque\n");
                        printf("3.Stock\n");
                        printf("4.Prix\n");
                        printf("5.Matiere\n");
                        printf("6.Couleur\n");
                        printf("7.Sexe\n");
                        printf("8.Taille\n");
                        printf("9.Promotion\n");
                        printf("10.Livraison\n");
                        printf("11.A propos\n");
                        printf("\nChoisir l'element que vous souhaitez modifier: ");
                        scanf("%i",&n2);
                    }
                    switch(n2){
                        case 1:{
                            printf("\nNom: ");
                            scanf("%s",aux->val.nom);
                            break;
                        }
                        /*case 2:{
                            printf("\nReference: ");
                            scanf("%s",aux->val.reference);
                            break;
                        }*/
                        case 2:{
                            printf("\nMarque: ");
                            scanf("%s",aux->val.marque);
                            break;
                        }
                        case 3:{
                            printf("\nStock: ");
                            scanf("%i",&aux->val.stock);
                            break;
                        }
                        case 4:{
                            printf("\nPrix: ");
                            scanf("%f",&aux->val.prix);
                            break;
                        }
                        case 5:{
                            printf("\nMatiere: ");
                            scanf("%s",aux->val.matiere);
                            break;
                        }
                        case 6:{
                            printf("\nCouleur: ");
                            scanf("%s",aux->val.couleur);
                            break;
                        }
                        case 7:{
                            printf("\nSexe: ");
                            scanf("%s",aux->val.sexe);
                            break;
                        }
                        case 8:{
                            printf("\nTaille: ");
                            scanf("%s",aux->val.taille);
                            break;
                        }
                        case 9:{
                            char ch1[3];
                            printf("\nPromotion(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.promo.status=true;
                                printf("\nValeur: ");
                                scanf("%f",&aux->val.promo.valeur);
                            }
                            else{
                                aux->val.promo.status=false;
                                aux->val.promo.valeur=0;
                            }
                            break;
                        }
                        case 10:{
                            char ch1[3];
                            printf("\nLivraison(oui/non): ");
                            scanf("%s",ch1);
                            if(!strcmp(ch1,"oui")){
                                aux->val.livr.status=true;
                                printf("\nPrix: ");
                                scanf("%f",&aux->val.livr.prix);
                            }
                            else{
                                aux->val.livr.status=false;
                                aux->val.livr.prix=0;
                            }
                            break;
                        }
                        case 11:{
                            printf("\nA propos: ");
                            scanf("%s",aux->val.a_propos);
                            //fgets(aux->val.a_propos,255,stdin);
                            break;
                        }
                    }
                    printf("\nModifier un autre element?(oui/non): ");
                    scanf("%s",ch2);
                }
                while(!strcmp(ch2,"oui"));
            }
                int h, m, s, jour, mois, an;
                char b[30];
                char ch_mois[10];
                char ch_jour[10];
				FILE *F=fopen("Historique.txt","a");
                time_t t;
                time(&t);
                struct tm *local = localtime(&t);
                h = local->tm_hour;
                m = local->tm_min;
                s = local->tm_sec;
                jour = local->tm_mday;
                mois = local->tm_mon + 1;
                an = local->tm_year + 1900;
                fprintf(F,"                                  %i/%-4i |  Modification  |      0000%-4i | %-1i:%-1i:%-6i \n",jour,mois,r,h,m,s );
                fprintf(F,"                             -------------------------------------------------------------\n");
                fclose(F);
            break;
        }
        case 0:i=9;break;
    }
}
void H(){
	FILE *F;
	char ch[255];

                                    F = fopen("./Historique.txt", "r");

                                    if(F==NULL){
                                        printf("Erreur lors de l'ouverture d'un fichier");
                                        exit(1);
                                    }

                                    while( fgets(ch,255,F) != NULL){
                                        puts(ch);
                                        //printf("%s", ch);
                                    }
                                    fclose(F);
}
void save_s(){
    FILE* F1;
    F1=fopen("./Produits_sante.dat","a");
    if(F1==NULL){exit(1);}
    struct l_sante* aux;
    struct sante b;
    aux=L1;
    while(aux!=NULL){
    	b=aux->val;
    	
        fwrite(&b,sizeof(b),1,F1); 
        aux=aux->suiv;
    }
    free(L1);
    fclose(F1);
}
void save_t(){
    FILE* F2;
    F2=fopen("./Produits_tech.dat","w");
    if(F2==NULL){exit(1);}
    struct l_tech* aux;
    struct tech b;
    aux=L2;
    while(aux!=NULL){
    	b=aux->val;
        fwrite(&b,sizeof(b),1,F2);
        aux=aux->suiv;
    }
    free(aux);
    fclose(F2);
}

void save_a(){
    FILE* F3;
    F3=fopen("./Produits_alim.dat","w");
    if(F3==NULL){exit(1);}
    struct l_alim* aux;
    struct alimentation b;
    aux=L3;
    while(aux!=NULL){
    	b=aux->val;
        fwrite(&b,sizeof(b),1,F3);
        aux=aux->suiv;
    }
    free(aux);
    fclose(F3);
}

void save_v(){
    FILE* F4;
    F4=fopen("./Produits_vet.dat","w");
    if(F4==NULL){exit(1);}
    struct l_vet* aux;
    struct vetement b;
    aux=L4;
    while(aux!=NULL){
    	b=aux->val;
        fwrite(&b,sizeof(b),1,F4);
        aux=aux->suiv;
    }
    free(aux);
    fclose(F4);
}
void recup_s(){
    FILE* F;
    F=fopen("./Produits_sante.dat","r");
    if(feof(F)){L1=NULL;}
    else{
	
        struct sante lecture;
        while(!feof(F)){
            fread(&lecture,sizeof(lecture),1,F);
            L1=ajouter_sante(L1,lecture);
        }}
    
    fclose(F);
}
void recup_t(){
    FILE* F;
    F=fopen("./Produits_tech.dat","r");
    if(feof(F)){L2=NULL;}
    else{
        struct tech lecture;
        while(!feof(F)){
            fread(&lecture,sizeof(lecture),1,F);
            L2=ajouter_tech(L2,lecture);
        }
    }
    fclose(F);
}
void recup_a(){
    FILE* F;
    F=fopen("./Produits_alim.dat","r");
    if(feof(F)){L3=NULL;}
    else{
        struct alimentation lecture;
        while(!feof(F)){
            fread(&lecture,sizeof(lecture),1,F);
            L3=ajouter_alim(L3,lecture);
        }
    }
    fclose(F);
}
void recup_v(){
    FILE* F;
    F=fopen("./Produits_vet.dat","r");
    if(feof(F)){L4=NULL;}
    else{
        struct vetement lecture;
        while(!feof(F)){
            fread(&lecture,sizeof(lecture),1,F);
            L4=ajouter_vetement(L4,lecture);
        }
    }
    fclose(F);
}
/*void save_n(n){
    FILE* F;
    F=fopen("./Produits_n.txt","w");
    fwrite(&n,sizeof(int),1,F);
    fclose(F);
}*/

void save_n(int n){

    FILE *fptr;
    fptr = fopen("./integers.txt", "w");
    putw(n, fptr);
    fclose(fptr);
}
/*int recup_n(){
    FILE* F;
    F=fopen("./Produits_n.txt","r");
    int n;
    fread(&n,sizeof(n),1,F);
    fclose(F);
    return(n);
}*/
int recup_n(){
    FILE *fptr;
    int num,n;
    fptr = fopen("./integers.txt", "r");
  while ( (num = getw(fptr)) != EOF ) {
    n=num;
  }
  fclose(fptr);

    return(n);
}
/*int recup_n(){
    FILE* F;
    F=fopen("./Produits_n.txt","r");
    int n;
    fread(&n,sizeof(n),1,F);
    fclose(F);
    return(n);
}*/
/*int recup_k(){
    FILE *fptr;
    int num,n;
    fptr = fopen("./k.txt", "r");
  while ( (num = getw(fptr)) != EOF ) {
    n=num;
  }
  fclose(fptr);

    return(n);
}*/
	
/*void titre(){
	char ch[255];
	FILE *F= fopen("Untitled-2.txt", "r");
	if(F==NULL){
    printf("Erreur lors de l'ouverture d'un fichier");
    exit(1);
    }

    while( fgets(ch,255,F) != NULL){
    puts(ch);
                                        //printf("%s", ch);
    }
    fclose(F);
	
}*/

void aide(int i){
	int k;
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                     AIDE\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n1. Aide Ajout\n\n");
    printf("2. Aide Recherche\n\n");
    printf("3. Aide Modification\n\n");
    printf("4. Aide suppression\n\n\n");
    printf("\n0. Menu principale\n\n");
    printf("Votre choix : ");
    scanf("%i",&k);
    
    switch(k){
    	case 1:{printf("------------------------------------------------------------------------------------------------------------------------\n");printf("Ajout:\n\nTout d'abord vous devez choisir la categerie de votre produit p (sante,technologie ,alimentation ou vetement)\nensuite tapez les caracteristiques de p.\n\n   Note: le programme va vous generer une reference automatiquement et la sauvegarder.\n");break;}
    	case 2:{printf("------------------------------------------------------------------------------------------------------------------------\n");printf("Recherche:\nVous devez choisir la categorie de votre produit p (sante,technologie ,alimentation ou vetement).\nEnsuite on a developpe un mode de recherche avec mot cle c'est a dire il suffit de connais une caracteristique \nde votre produit souhaite vous pouvez l'acceder\n\n   Note: le programme va afficher tous produits(de meme categorie) contenant ce mot cle et a vous de tapez la reference\n de votre produit.\n");break;}
    	case 3:{printf("------------------------------------------------------------------------------------------------------------------------\n");printf("Modification:\n\nDe meme vous devez choisir la categorie de votre produit p (sante,technologie ,alimentation ou vetement).\n  Ensuite taper la reference de p puis choisir l'element a modifier .\n");break;}
    	case 4:{printf("------------------------------------------------------------------------------------------------------------------------\n");printf("Suppression:\n\nDe meme vous devez choisir la categorie de votre produit p (sante,technologie,alimentation ou vetement).\n  Ensuite taper la reference de p .\n");break;}
    	case 0:i=9;break;
	}
}
void a_propos(){
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                 A PROPOS\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Cree en 2022, SBM-Services est le leader de la vente de produits\nHigh-Tech, sante et beaute, alimentation et habillement en Tunisie.\n\n");
    printf("Dotee d'une grande experience avec une equipe passionnee,\nSBM-Services s'engage a satisfaire vos exigences.\n\n");
    printf("Ainsi, nos specialistes selectionnent avec soin nos references\nafin de vous offrir le meilleur rapport qualite/prix.\n\n");
    printf("Contact:\n\n");
    printf("        . Siege social: 64, Rue de L'independance Charguia | 2027 Tunis, Tunisie\n");
    printf("        . Telephone: +216 71 986 347\n");
    printf("        . WhatsApp:  +216 25 698 478\n");
    printf("        . E-mail:    store@SBM-Services.tn\n\n");
    printf("Nos magasins: \n\n");
    printf("        . Magasin Charguia 1\n");
    printf("        . Magasin Av.Habib Bourguiba Tunis 1\n");
    printf("        . Magasin Nabeul centre\n");
    printf("        . Magasin Sousse centre\n\n\n");
    printf("      Facilite de paiement          Livraison en 24h          Ouvert 7/7 (8h a 19h)\n\n\n");
}
    
int main()
{    
    N=recup_n();
    if(N==0){
    	FILE* F1;
    	FILE* F2;
    	FILE* F3;
    	FILE* F4;
    	FILE* F5;
	F1=fopen("Produits_sante.dat","w");
	F2=fopen("Produits_tech.dat","w");
	F3=fopen("Produits_alim.dat","w");
	F4=fopen("Produits_vet.dat","w");
	F5=fopen("Historique.txt","w");
	fclose(F1);
	fclose(F2);
	fclose(F3);
	fclose(F4);
	fclose(F5);}
	recup_s();
    recup_t();
    recup_a();
    recup_v();
    //titre();
        printf("************************************************************************************************************************\n\n");
        printf("                                            BIENVENUE CHEZ SBM-StockManager\n\n");
        printf("************************************************************************************************************************\n");
    //L1=(struct l_sante*) malloc (sizeof (struct l_sante));
    time_t ta;   // not a primitive datatype
    time(&ta);
    printf("This program has been executed at : %s", ctime(&ta));
    //char a[255];
    //strcpy(a,ctime(&ta));
    //a=ctime(&ta);
    //printf("%s",&a[4]);
    int n;
    system("color 0A");

    while(1){
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                     MENU\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("[1] Ajouter un produit\n\n");
        printf("[2] Recherche d'un produit\n\n");
        printf("[3] Supprimer un produit\n\n");
        printf("[4] Modifier un produit\n\n");
        printf("[5] Afficher l'historique\n\n\n");
        printf("[6] Aide\n\n");
        printf("[7] A Propos\n\n");
        printf("[00] Quitter\n\n");
        printf("Saisir votre choix: ");
        scanf("%i",&n);
        while((n<0)||(n>7)){
            //system ("cls");
            printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                     MENU\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
            printf("\nEntree invalide!!\n\nVeuillez saisir de nouveau votre choix.\n\n");
            printf("[1] Ajouter un produit\n\n");
        printf("[2] Recherche d'un produit\n\n");
        printf("[3] Supprimer un produit\n\n");
        printf("[4] Modifier un produit\n\n");
        printf("[5] Afficher l'historique\n\n\n");
        printf("[6] Aide\n\n");
        printf("[7] A Propos\n\n");
        printf("[00] Quitter\n\n");
        printf("Saisir votre choix: ");
            scanf("%i",&n);
        }
        if(n==00){
            break;
        }
        else{
            switch(n){
                case 1:{ajout(n);break;}
                case 2:{recherche(n);break;}
                case 3:{supprimer(n);break;}
                case 4:{modifier(n);break;}
                case 5:{printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                                     HISTORIQUE\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                            |*************************************************************|\n");
    printf("                            |      DATE   |    OPERATION   |   REFERENCE   |    HEURE     |\n");
    printf("                            |*************************************************************|\n");
				H();break;}
                case 6:{aide(n);break;}
                case 7:{a_propos();break;}
            }
        }
    }
  /*  FILE* F=fopen("Produits_sante.dat","r");
rewind(F);
fclose(F);*/
    save_s();
    save_t();
    save_a();
    save_v();
    save_n(N);
    return 0;
}
