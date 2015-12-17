#define _VERSION 1
#define NUM_OF_REGISTERS 16

#define NEXT_NUM program[position++]
#define NEXT_REG registers[NEXT_NUM]
#define CURR_REG registers[program[position - 1]]
#define REG[TMP1] registers[NUM_OF_REGISTERS]
#define REG[TMP2] registers[NUM_OF_REGISTERS + 1]
#define BACK position--
#define STACK_POP(PREG) err = stackPop(PREG)
#define STACK_PUSH(DATA) err = stackPush(DATA)
#define STACK_TOP (stackPTop(&err) != NULL ? *stackPTop(&err) : REG[TMP2])

#include <stdio.h>
#include <stdlib.h>
#include "generated/commands.h"
#include "errors.h"

size_t programSize;
int *program;
int registers[NUM_OF_REGISTERS + 2];

int processorInit()
{
	program = (int *)calloc(programSize, sizeof(int));
	if ((program == NULL) || (stackInit() != 0))
		return CANNOT_INIT_PROCESSOR;
	for (int i = 0; i < NUM_OF_REGISTERS; i++)
		registers[i] = 0;
	return 0;
}

int processorExecute()
{
	size_t position = 1;
	int command;
	int err = 0;

	while ((position < programSize) && (err == 0))
	{
		command = NEXT_COMMAND;
		switch (command)
		{
			#include "generated/processor.c"
		}
	}
	return err;
}
