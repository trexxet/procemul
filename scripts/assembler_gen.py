import re

procCommands = open('generated/commands.h')
asm = open('generated/assembler_generated.c', 'w')
prevWord = ''
for line in procCommands:
    words = re.split('[\s_+]', line)
    if prevWord != words[1]:
        if prevWord != '':
            asm.write('}\n\n')
        asm.write('IFCMD(' + words[1].lower() + ')\n{\n')
        prevWord = words[1]
    if words[2] == 'NUM':
        asm.write('\tif (arg1Type == NUM)\n\t{\n\t\t')
        asm.write('CHECK_PROGRAM_SIZE(2);\n\t\t')
        asm.write('NEXT_COMMAND = ' + words[1] + '_NUM;\n\t\t')
        asm.write('NEXT_COMMAND = atoi(arg1);\n\t\t')
        asm.write('return 0;\n\t}\n')
    elif words[2] == 'REG':
        asm.write('\tif (arg1Type == REG)\n\t{\n')
        if words[3] == 'NUM':
            asm.write('\t\tif (arg2Type == NUM)\n\t\t{\n\t\t\t')
            asm.write('CHECK_PROGRAM_SIZE(3);\n\t\t\t')
            asm.write('NEXT_COMMAND = ' + words[1] + '_REG_NUM;\n\t\t\t')
            asm.write('NEXT_COMMAND = REG_NUM(arg1);\n\t\t\t')
            asm.write('NEXT_COMMAND = atoi(arg2);\n\t\t\t')
            asm.write('return 0;\n\t\t}\n')
        elif words[3] == 'REG':
            asm.write('\t\tif (arg2Type == REG)\n\t\t{\n\t\t\t')
            asm.write('CHECK_PROGRAM_SIZE(3);\n\t\t\t')
            asm.write('NEXT_COMMAND = ' + words[1] + '_REG_REG;\n\t\t\t')
            asm.write('NEXT_COMMAND = REG_NUM(arg1);\n\t\t\t')
            asm.write('NEXT_COMMAND = REG_NUM(arg2);\n\t\t\t')
            asm.write('return 0;\n\t\t}\n')
        else:
            asm.write('\t\tif (arg2Type == NONE)\n\t\t{\n\t\t\t')
            asm.write('CHECK_PROGRAM_SIZE(3);\n\t\t\t')
            asm.write('NEXT_COMMAND = ' + words[1] + '_REG;\n\t\t\t')
            asm.write('NEXT_COMMAND = REG_NUM(arg1);\n\t\t\t')
            asm.write('return 0;\n\t\t}\n')
        asm.write('\t}\n')
    else:
        asm.write('\tif (arg1Type == NONE)\n\t{\n\t\t')
        asm.write('CHECK_PROGRAM_SIZE(1);\n\t\t')
        asm.write('NEXT_COMMAND = ' + words[1] + ';\n\t\t')
        asm.write('return 0;\n\t}\n')
asm.write('}')
procCommands.close()
asm.close()
