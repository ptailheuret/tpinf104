#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  int i;
  pid_t enfant_pid[i];

  for(i=1;i<10;i++)
    {
      enfant_pid[i] = fork ();
      if (enfant_pid[i] > 0) {
	sleep (i);
      }
      else {
	exit (0);
      }
    }
  return 0;
}
