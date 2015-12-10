import re

instr = open('instructions')
procCommands = open('generated/commands.h', 'w')
for line in instr:
    words = re.split('\W+', line)
    if words[0].isdigit():
        string = '#define ' + words[1].upper()
        if (words[2] == 'reg') or (words[2] == 'reg1'):
            string += '_REG'
        elif words[2] == 'num':
            string += '_NUM'
        if words[3] == 'reg2':
            string += '_REG'
        elif words[3] == 'num':
            string += '_NUM'
        procCommands.write(string + ' ' + words[0].lstrip('0') + '\n')
procCommands.close()
instr.close()
