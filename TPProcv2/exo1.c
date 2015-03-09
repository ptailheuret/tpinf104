#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (){ 
  pid_t valeur;
  printf("printf-0 Avant fork : ici processus numero %d\n", (int)getpid());
  valeur = fork();
  if (valeur == 0) sleep (2);
  printf("printf-1 Valeur retournee par la fonction fork: %d\n", (int)valeur);
  printf("printf-2 Je suis le processus numero %d\n", (int)getpid());
  return 0;
}
