from sys import stdin,stdout
from collections import deque
T:int = int(stdin.readline().rstrip())

for tc in range(T):
    p = stdin.readline().rstrip()
    n = int(stdin.readline().rstrip())
    x = stdin.readline().rstrip()[1:-1]
    x_list = deque(x.split(","))

    reverse = False
    error = False
    for c in p:
        if c == "R":
            reverse = not reverse
        elif c == "D":
            if n == 0:
                error=True
                break
            else:
                n-=1
                if reverse:
                    x_list.pop()
                else:
                    x_list.popleft()

    if error:
        print("error")
    else:
        if reverse:
            x_list.reverse()
        
        print(f"[{','.join(x_list)}]")