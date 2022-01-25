from sys import stdin
from collections import deque

buffer_size = int(stdin.readline())
buffer = deque()

while(True):
    packet = stdin.readline().strip()
    if packet == "-1":
        break
    
    elif packet == "0":
        
        if len(buffer) != 0:
            buffer.popleft()
    
    else:
        if len(buffer) <buffer_size:
            buffer.append(packet)

print(" ".join(map(str, buffer)))