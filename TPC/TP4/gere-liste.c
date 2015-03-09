#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tpselc-types.h"

/********************    nouveau_maillon   *******************
 * Creer un nouvel element ayant  la valeur NULL dans
 * le second champ.
 * Renvoie un pointeur sur le nouvel element de la chaine.
 ********************************************************/
Maillon_t * nouveau_maillon(Eleve_t Un_eleve){
  Maillon_t *Ptr;
  Ptr = (Maillon_t*) malloc (sizeof(Maillon_t));

  if (Ptr==NULL)
    exit(1);
  Ptr -> eleve = Un_eleve;
  Ptr -> suivant = NULL;
  
  return Ptr;
}

/********************    chainer   *******************
 * Ajouter le nouveau maillon  en tete 
 * de la liste chainee de debut "debut".
 * Renvoie le nouveau debut de la liste.
 ********************************************************/
Maillon_t * chainer(Maillon_t *debut, Maillon_t * maillon_a_chainer){
    Maillon_t *Ptr;
    Ptr = (Maillon_t*) malloc (sizeof(Maillon_t));
    if (Ptr==NULL)
      exit(1);
    Ptr =  maillon_a_chainer;	
    Ptr -> suivant = debut;
    
    return Ptr;
}

/********************   ecrire_liste   *******************
 * Ecrit sur la sortie standard (printf) les donnees de 
 * la liste chainee de debut "debut".
 * Ne renvoie auncune valeur;
 ********************************************************/
void ecrire_liste(Maillon_t *debut){
    Maillon_t *Ptr;
    int i=0;
    printf("Debut de liste\n");
    Ptr = (Maillon_t*) malloc (sizeof(Maillon_t));
    if (Ptr==NULL)
      exit(1);
    Ptr = debut;
    while(Ptr!=NULL){
      printf("Nom = %s \t\t Prenom = %s \t\t Info = %d \n",(Ptr->eleve).nom,(Ptr->eleve).prenom,(Ptr->eleve).info);
      debut = debut -> suivant;
    }
    printf("Fin de liste\n");
    
    return;
}


/************************* ecrire_fic_liste   ***********
 * Ecrit dans un fichier  (fprintf) le contenu de 
 * la liste chainee de debut "debut".
 * Le parametre passe en entree est le nom du fichier 
 * dans lequel on a lu les donnees. 
 * Le nom du fichier de sortie  est cree par concatenation
 * de ".out" au nom de ce fichier. 
 * Renvoie le nombre d elements de la liste
 * ecrits dans le fichier de sortie.
 ********************************************************/
int ecrire_fic_liste (Maillon_t * debut,  char * nom_fichier){
	FILE *fichier;
	Maillon_t *Ptr;
	char nom_fichier_sor[80];
    int i=0;
	
	/******** creation du nom du fichier de sortie
	 nom-fic-sortie = nom-fic-entree suivi de .out
	 ********/
	strcpy(nom_fichier_sor, nom_fichier);
	strcat(nom_fichier_sor, ".out");
	
	/******** ouverture du fichier de sortie ********/
	fichier = fopen(nom_fichier_sor, "w");
	if (fichier == NULL) {
		printf("erreur ouverture\n");
		return 0;
	}
	
	/****** visualisation a l ecran et ecriture dans le fichier de sortie *******/
	
	
	/* A COMPLETER */
    
	
	return i;
	
}

