//accepts either one or two command-line arguments, and outputs different page size depending on the number of command-line arguments

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#define SIZE 4096

int main(int argc, char *argv[]) {
  if(argc == 2)
  {
   unsigned char *hex;
    hex = argv[1];
    int addr = (int)strtol(hex, NULL, 16);
    int pg = addr/SIZE;
    int offset = addr - (pg*SIZE);
    printf("Page #: %d\n", pg);
    printf("Offset: %d\n", offset);
   }
   else if(argc == 3){
      int pg = atoi(argv[1]);
      int offset = atoi(argv[2]);
      int addr = SIZE * pg + offset;
      printf("Virtual Address-> %d\n", addr);
   }
   else{
    printf("Incorrect Number of Arguments!");
    return 0;
   }
}
