from sys import stdin, stdout

T:int = int(stdin.readline().rstrip())

S = 0
for tc in range(T):
    cmd = list(stdin.readline().split())

    if cmd[0] == "add":
        S |= 1 << (int(cmd[1])-1)
    elif cmd[0] == "remove":
        S &= ~(1 << (int(cmd[1])-1))
    elif cmd[0] == "check":
        if (S & (1<<(int(cmd[1])-1))) == 1<<(int(cmd[1])-1):
            stdout.write("1\n")
        else:
            stdout.write("0\n")
    elif cmd[0] == "toggle":
        S ^= 1 << (int(cmd[1])-1)
    elif cmd[0] == "all":
        S = 0b11111111111111111111
    elif cmd[0] == "empty":
        S = 0
