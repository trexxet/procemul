#ifndef STACK
#define STACK
#define MAX_STACK_SIZE 256

int stack[MAX_STACK_SIZE];

int stackInit();
int stackPush(int value);
int stackPop(int *out);
int *stackPTop(int *err);

#endif
