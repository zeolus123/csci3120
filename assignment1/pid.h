#ifndef PID_H
#define PID_H

#define PID_MIN 100
#define PID_MAX 150


int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);

#endif
