#define MAX_STACK_SIZE 256

#include <stdlib.h>
#include "errors.h"

int stack[MAX_STACK_SIZE];
int stackSize;

int stackInit()
{
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		stack[i] = 0;
	stackSize = 0;
	return 0;
}

int stackPush(int value)
{
	if (stackSize <= MAX_STACK_SIZE)
	{
		stack[stackSize++] = value;
		return 0;
	}
	return STACK_OVERFLOW;
}

int stackPop(int *out)
{
	if (stackSize > 0)
	{
		if (out)
			*out = stack[stackSize - 1];
		stack[--stackSize] = 0;
		return 0;
	}
	return STACK_UNDERFLOW;
}

int *stackPTop(int *err)
{
	if (stackSize > 0)
	{
		*err = 0;
		return &stack[stackSize - 1];
	}
	*err = STACK_IS_EMPTY;
	return NULL;
}
