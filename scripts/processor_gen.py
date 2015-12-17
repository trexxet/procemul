import re

commands = open('generated/commands.h')
cmd = []
for line in commands:
    words = re.split('\s+', line)
    cmd.append(words[1])
commands.close()
oper = open('operations')
proc = open('generated/processor_generated.c', 'w')
for line in oper:
    fword = line.rstrip(':')
    if fword.isdigit():
        currNum = int(fword)
        proc.write('case ' + cmd[currNum - 1] + ':\n')
    else:
        proc.write('\t' + line)
proc.close()
oper.close()
