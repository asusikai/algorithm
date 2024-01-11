import heapq
from sys import stdin, stdout

N = int(stdin.readline().rstrip())

min_heap = []

for n in range(N):
    x = int(stdin.readline().rstrip())

    if x == 0:
        if len(min_heap) == 0:
            stdout.write("0\n")
        else:
            stdout.write("%d\n" % heapq.heappop(min_heap))

    else:
        heapq.heappush(min_heap, x)