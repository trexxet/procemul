#define _VERSION 1
#define DIVIDER " ,\n"
#define REGISTERS "abcdefghjklmnopq"
#define CHECK_PROGRAM_SIZE(incsize) \
	if (maxProgramSize - programSize < incsize) \
		program = (int *)realloc(program, (maxProgramSize *= 2) * sizeof(int))
#define NONE 0
#define NUM 1
#define REG 2
#define IFCMD(cmd) if (strcmp(command, #cmd) == 0)
#define IS_REG(arg) (arg != NULL && arg[2] == 0 && arg[1] == 'x' && strchr(REGISTERS, arg[0]))
#define IS_NUM(arg) (arg != NULL && strspn(arg, "0123456789") == strlen(arg))
#define NEXT_ARG strtok(NULL, DIVIDER)
#define NEXT_COMMAND program[programSize++]
#define REG_NUM(reg) strchr(REGISTERS, reg[0]) - REGISTERS

#include <string.h>
#include <stdlib.h>
#include "generated/commands.h"
#include "errors.h"

#ifdef DEBUG
#include <stdio.h>
#endif

int *program;
size_t maxProgramSize;
size_t programSize;

int assemblerInit(int initProgramSize)
{
	program = (int *)calloc(initProgramSize, sizeof(int));
	if (program == NULL)
		return CANNOT_INIT_ASSEMBLER;
	maxProgramSize = initProgramSize;
	programSize = 1;
	program[0] = _VERSION;
	return 0;
}

int assembleString(char *sourceString)
{	
	char *command = strtok(sourceString, DIVIDER);
	char *arg1 = strtok(NULL, DIVIDER);
	char *arg2 = strtok(NULL, DIVIDER);
	int arg1Type = NONE, arg2Type = NONE; //0 - NULL, 1 - num, 2 - register
	arg1Type += IS_NUM(arg1) + 2 * IS_REG(arg1);
	arg2Type += IS_NUM(arg1) + 2 * IS_REG(arg2);
	if ((arg1 != NULL && arg1Type == 0) || (arg2 != NULL && arg2Type == 0))
		return INVALID_REGISTER;
	#include "generated/assembler_generated.c"
	return UNKNOWN_COMMAND;
}
