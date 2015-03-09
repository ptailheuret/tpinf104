#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  pid_t enfant_pid;

  enfant_pid = fork ();
  if (enfant_pid > 0) {
    sleep (20);
  }
  else {
    exit (0);
  }
  return 0;
}
