from sys import stdin, stdout
from collections import defaultdict

N,M = map(int, stdin.readline().rstrip().split())

# stdout.write("%d\n" % N)
# stdout.write("%d" % M)

names = defaultdict(int)

for i in range(N+M):
    name = stdin.readline().rstrip()
    names[name]+=1

unknown = []

for name in names:
    if names[name] == 2:
        unknown.append(name)

unknown = sorted(unknown)

stdout.write("%d\n" % len(unknown))
stdout.write("%s" % "\n".join(unknown))