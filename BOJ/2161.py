from sys import stdin
from collections import deque

input_num = int(stdin.readline())

cards = deque([i+1 for i in range(input_num)])

result = []

for i in range(input_num):
    result.append(cards.popleft())
    if cards:
        cards.append(cards.popleft())
            
    else:
        pass

print(" ".join(map(str, result)))