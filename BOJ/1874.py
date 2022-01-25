count = int(input())

series = []
stack = []
answer = []
c = 1

d= True
for i in range(count):
    
    num = int(input())
    series.append(num)
    
    while(num >= c):
        stack.append(c)
        answer.append("+")
        c = c+1
    
    
    if stack[-1] == num:
        stack.pop()
        answer.append("-")
    
    else:
        d= False

if d == True:
    for i in answer:
        print(i)
else:
    print("NO")