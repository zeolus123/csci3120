/**
 *test.c
 *test the implementation of the pid manager
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
#include "pid.h"

//thread related variables
int length = PID_MAX - PID_MIN;
pthread_t tid[30];
int r;

//this is the function for running threads
void *test(void *d){
  int rand_time = rand() % 30;
  int pid = allocate_pid();
  if(pid == -1){
    printf("Can't create process\n");
    return;
  }
  printf("process created: %d\n", pid);
  sleep(rand_time);
  release_pid(pid);
  printf("finished process %d in %d seconds\n", pid, rand_time);
}

int main (void){
  int i = 0;
  // allocating the map
  int map = allocate_map();
  if(map == 1){
    printf("map allocated\n");
  }else{
    printf("map not allocated\n");
  }
  
  //creating threads
  for(i; i < 30; i++){
     r = pthread_create(&tid[i], NULL, test, NULL);
     if(r != 0){
       printf("cant create thread.\n");
     }
  }

  //closing threads
  for(i = 0; i < 30; i++){
    pthread_join(tid[i], NULL);
  }

}
