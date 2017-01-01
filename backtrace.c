
#include <sys/types.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//prints information of backtrace
void print_trace (void)
{
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  printf ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     printf ("%s\n", strings[i]);

  free (strings);
}
//handles SEG fault signal
void seg_handler(int sig){
  printf("SIGSEGV signal caught. Backtrace: \n");
  print_trace();
}

//registers and sends SIGSEGV to process
int main(){
  signal(SIGSEGV, seg_handler);
  raise(SIGSEGV);
}
