/******************************************************

 Exclusion mutuelle sur l'acces a un fichier partage.

 Remarque : les processus qui n'utilisent pas lockf 
            accedent sans controle au fichier partage.
 Pour verifier ceci, faire une redirection vers ce fichier
 pendant que deux processus se synchronisent en utilisant 
 lockf.

********************************************************/ 
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char *argv[])
{
  int Ret_lock, Ret_write, Sortie ;
  char Tab[256];
  if (argc != 2) 
    {
      printf(" Utilisation : %s fic_sortie ! \n", argv[0]);
      exit(2);
    }
   /*-----------------------------------------------------
    Pour verifier le bon fonctionnement du code,
    faire les sorties sur une fenetre dont ou aura pris le nom 
    avec la commande tty et que l'on passera sur la ligne 
    de commande.
    ----------------------------------------------------- */

  if ((Sortie = open (argv[1], O_RDWR)) == -1) 
    {
      perror ("open 2"); 
      exit (1); 
    }
  
  while (1)
    { 
      /*  ---- synchronisation pas faite, a faire !  ----  */
      lockf(argv[1],F_LOCK,(off_t)10000);


      printf("Pid %d : entree dans SC\n", (int)getpid() ); 
    
      
      /*----------------------------------------------
	Debut de section critique 
	----------------------------------------------*/ 
      while ( fgets(Tab, sizeof(Tab), stdin) )
	{
	  /*----------------------------------------------
	    On reste dans la  boucle de lecture-ecriture
	    tant qu'on n'a pas tape la chaine "fin".
	    ----------------------------------------------*/ 
      	  if (!strncmp (Tab, "fin", 3)) break;
	  Ret_write = write (Sortie, Tab, strlen(Tab));
	  if (Ret_write < 0)
	    {
	      printf ("Erreur d'ecriture vers %s\n", argv[1]);
	      break;
	    }
	}
      
      /*----------------------------------------------
	Fin de section critique 
	----------------------------------------------*/ 
      
      printf ("Pid %d : arret temporaire d'utilisation de %s\n", 
	      (int)getpid(), argv[1]); 

      lseek(argv[1],(off_t)10000,SEEK_SET);
      lockf(argv[1],F_ULOCK,(off_t)10000);
      /*  ---- synchronisation pas faite, a faire !  ----  */
	    sleep(1);

      printf ("sortie SC, Ret_lock =  %d\n", Ret_lock);
    }  /* fin de la boucle while */
} 
