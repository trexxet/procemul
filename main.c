#ifdef ASM
#define SOURCE_STRING_LENGTH 255
#define INIT_PROGRAM_SIZE 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assembler.h"
#include "errors.h"

int main(int argc, char * argv[])
{
	if (argc == 1)
	{
		fprintf(stderr, "Error: no source code set\n");
		return NO_SOURCE_CODE;
	}
	FILE *source = fopen(argv[1], "r");
	if (!source)
		return CANNOT_OPEN_SOURCE;
	char sourceString[SOURCE_STRING_LENGTH];
	if (!fgets(sourceString, SOURCE_STRING_LENGTH, source))
	{
		fprintf(stderr, "Error: source file is empty\n");
		return SOURCE_IS_EMPTY;
	}
	if (strcmp(sourceString, VERSION) != 0)
	{
		fprintf(stderr, "Error: version mismatch\n");
		return VERSION_MISMATCH;
	}

	int err = assemblerInit(INIT_PROGRAM_SIZE);
	int line = 1;
	while (fgets(sourceString, SOURCE_STRING_LENGTH, source) && (err == 0))
	{
		err = assembleString(sourceString);
		line++;
	}
	fclose(source);
	switch (err)
	{
		case CANNOT_INIT_ASSEMBLER:
			fprintf(stderr, "Error: cannot initialize assembler\n");
			return err;
		case UNKNOWN_COMMAND:
			fprintf(stderr, "Error: unknown command at line %d\n", line);
			return err;
		case INVALID_REGISTER:
			fprintf(stderr, "Error: invalid register at line %d\n", line);
			return err;
	}

	#ifdef DEBUG
	for (int i = 0; i < programSize; i++)
	       printf("%d ", program[i]);
	printf("\n");
	#endif

	char *outputName = argc == 3 ? argv[2] : "a.ep"; 
	FILE *out = fopen(outputName, "wb");
	fwrite(&programSize, sizeof(size_t), 1, out);
	fwrite(program, sizeof(int), programSize, out);
	fclose(out);
	
	printf("%s compiled to %s succesfully\n", argv[1], outputName);
	return 0;
}
#endif

#ifdef PROC
#define _VERSION 1

#include <stdio.h>
#include "processor.h"
#include "errors.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		fprintf(stderr, "Error: no program set\n");
		return NO_PROGRAM;
	}
	FILE *input = fopen(argv[1], "rb");
	if (input == NULL)
	{
		fprintf(stderr, "Error: can't open %s\n", argv[1]);
		return CANNOT_OPEN_PROGRAM;
	}

	fread(&programSize, sizeof(size_t), 1, input);
	if (processorInit() == CANNOT_INIT_PROCESSOR)
	{
		fprintf(stderr, "Error: can't initialize processor\n");
		return CANNOT_INIT_PROCESSOR;
	}
	fread(program, sizeof(int), programSize, input);
	fclose(input);
	if (program[0] != _VERSION)
	{
		fprintf(stderr, "Error: version mismatch\n");
		return VERSION_MISMATCH;
	}

	#ifdef DEBUG
	for (int i = 0; i < programSize; i++)
		printf("%d ", program[i]);
	printf("\n");
	#endif

	int err = processorExecute();
	switch (err)
	{
		case STACK_OVERFLOW:
			fprintf(stderr, "Error: stack overflow\n");
			return err;
		case STACK_UNDERFLOW: 
			fprintf(stderr, "Error: stack underflow\n");
			return err;
	}

	printf("Program executed\n");
	return 0;
}
#endif
