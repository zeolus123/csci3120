/**assignment 1: pid manager 
 * 
 */

#include<stdlib.h>
#include<stdio.h>
#include"pid.h"

int size = PID_MAX - PID_MIN;
int *bitmap, *pid_collection;

int allocate_map(){
  int i, success = 1, j = PID_MIN;
  //setting the pid_collection array;
  pid_collection = (int *)calloc(size, sizeof(int));
  //if it couldn't allocate the memory, then it fails
  if(pid_collection == NULL){
    success = -1;
  }
  for(i = 0; i <= size; i++){
    pid_collection[i] = j;
    j++;
  }
  
  //allocating the bitmap;
  bitmap = (int *)calloc(size, sizeof(int));
  //again, if it couldn't allocate memory it fails
  if(bitmap == NULL){
    success = -1;
  }
  memset(bitmap, 0, sizeof(bitmap));
  
  return success;
}

void testMaps(){
  int i;
  for(i = 0; i < size; i++){
    printf("bitmap: %d, pid: %d\n", bitmap[i], pid_collection[i]);
  }

}
//allocates each pid itself from the list
int allocate_pid(){
  int success = -1, i;
  /*iterates through the bitmap array and looks for the first value of 0, which   *indicates that the given pid in the pid_collections array is free then it
   *just sets the return value and sets the value of bitmap to 1 meaning taken
   *and breaks out of the loop
   */
  for(i = 0; i < size; i++){
    if(bitmap[i]  == 0){
      success = pid_collection[i];
      bitmap[i] = 1;
      break;
    }
  }

  return success;
}

//checks to see if pid is taken, then releases it
void release_pid(int pid){
  int i, index = find_index(pid);
  if(index == -1){
    printf("Can't find %d \n", pid);
    return;
  }else{
    bitmap[index] = 0;
    printf("process released.");
  }
}

//helper function for release_pid()
int find_index(int pid){
  int index = -1, i;
  for(i = 0; i < size; i++){
    if(pid_collection[i] == pid){
      index = i;
      break;
    }
  }
  return index;
  
}
