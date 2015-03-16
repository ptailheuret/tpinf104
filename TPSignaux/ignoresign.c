#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main(int argc, char *argv[]){
  int Nb_Sig;
  for(Nb_Sig = 1; Nb_Sig < NSIG ; Nb_Sig ++){

    signal(Nb_Sig,SIG_IGN);
    
    if(signal(Nb_Sig,SIG_IGN)==SIG_ERR)
      printf("Le processus %d présente une erreur",Nb_Sig);
  }
  while(1){
     sleep(5);
  }  /* Attendre des signaux   */
  return 0;
}
