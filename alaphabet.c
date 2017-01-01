//use parallel programming to print alphabet

#include <stdio.h>

int main() {
  char c;
  #pragma omp parallel for mun_threads(4)
    for(c=97; c<=122; c++)
      printf("%c \n", c);
    return 0;
}
  
