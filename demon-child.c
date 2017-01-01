//process that spins indefinitely unless ctrl z is used

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int sign)
{
  printf("Signal caught %d\n", sign);
  //forks instead of exiting when signal is called
  fork();
}

int main()
{
  //register sig
  signal(SIGINT, signal_handler);
  while(1)
  {
    printf("processing.....\n");
    sleep(1);
  }
  return EXIT_SUCCESS;
}
