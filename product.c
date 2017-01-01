//using parallel programming to calculate product
#include <stdio.h>

#define N 30

int main() {
  int i, product;
  #pragma omp parallel for reduction(*:product)
  for(i=1; i<=N; i++)
    product*=i;    
  printf("Result = %d\n", product);
  return 0;
}

