# 다시 풀기!
from collections import Counter
from sys import stdin, stdout

T = int(stdin.readline().rstrip())

for tc in range(T):
    N = int(stdin.readline().rstrip())
    c = Counter(stdin.readline().rstrip().split(" "))
    # stdout.write( "%s\n" % c)
    # print(c.items())
    # print(c)
    cs = sorted(c.items(), key=lambda x:(x[0],x[1]))
    stdout.write( "%s\n" % cs)