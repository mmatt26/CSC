#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <crypt.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <pthread.h>

void ith(char *password, int index, int n) {
  for (int i=1; i<=n; i++) {
    password[i-1] = (index % 26) + 'a';
    index /= 26;
  }
  password[n] = '\0';
}


int main() {

  char *hash;
  char target[16];
  char password[5];
  char salt[3];
   
  char *copy;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_t tid[NUM];
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);

  int N=pow(26, 4);
  int M=pow(26, 2);
  int t;
  
  int fd  = open("hash", 'r');
  int num = read(fd, target, 16);
  if (num) target[num-1] = 0;
  else     exit(0);
  close(fd);
  for (t=0; t<NUM; t++)
    pthread_create(&tid[t], &attr, hash, password);
    ith(password, i, 4);
  for (int j=0; j<M; j++) {
    ith(salt,     j, 2);
    for (int i=0; i<N; i++) {
        pthread_mutex_lock(&mutex);
        hash = crypt(password, salt);
        copy = tid[i];
        pthread_equal(copy,tid);
        if (0==strcmp(hash, target)) {
        printf("Password: %s\t\tSalt: %s\t\tHash: %s\t\tTarget: %s\n", password, salt, hash, target);
        exit(1);
      } else printf("Trying %s...\r", password);
    }
  }

}
