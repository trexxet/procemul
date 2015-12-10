#ifdef PROC
#define NO_PROGRAM 1
#define CANNOT_OPEN_PROGRAM 2
#define PROGRAM_IS_EMPTY 3
#define VERSION_MISMATCH 4
#define CANNOT_INIT_PROCESSOR 5
#define STACK_OVERFLOW 6
#define STACK_UNDERFLOW 7
#endif

#ifdef ASM
#define NO_SOURCE_CODE 1
#define CANNOT_OPEN_SOURCE 2
#define SOURCE_IS_EMPTY 3
#define VERSION_MISMATCH 4
#define CANNOT_INIT_ASSEMBLER 5
#define UNKNOWN_COMMAND 6
#define INVALID_REGISTER 7
#endif
