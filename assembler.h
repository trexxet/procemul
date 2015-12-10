#ifndef ASSEMBLER_EP1
#define ASSEMBLER_EP1

#define VERSION "0.1a-a1\n"

int *program;
size_t maxProgramSize;
size_t programSize;

int assemblerInit(int initProgramSize);
int assembleString(char *sourceString);

#endif
