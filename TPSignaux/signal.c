#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
  int Nb_Sig;
  void Traite_Sig(int);

  for(Nb_Sig = 1; Nb_Sig < NSIG ; Nb_Sig ++)
    {
      signal(Nb_Sig, Traite_Sig);
    }

  while(1)
    {
      sleep(5);
    }  /* Attendre des signaux   */

  return 0;
}

/************* Fonction de traitement **************/
void Traite_Sig (int Numero)
{
  printf("Coucou, recu signal %d !\n", Numero);
}
