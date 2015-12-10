all:
	python3 scripts/commands_gen.py
	python3 scripts/assembler_gen.py
	gcc main.c processor.c -std=c99 -D=PROC -o proc
	gcc main.c assembler.c -std=c99 -D=ASM -o asm
proc:
	python3 scripts/commands_gen.py
	gcc main.c processor.c -std=c99 -D=PROC -o proc
proc-debug:
	python3 scripts/commands_gen.py
	gcc main.c processor.c -std=c99 -D=PROC -g -D=DEBUG -o proc
asm:
	python3 scripts/commands_gen.py
	python3 scripts/assembler_gen.py
	gcc main.c assembler.c -std=c99 -D=ASM -o asm
asm-debug:
	python3 scripts/commands_gen.py
	python3 scripts/assembler_gen.py
	gcc main.c assembler.c -std=c99 -D=ASM -g -D=DEBUG -o asm
