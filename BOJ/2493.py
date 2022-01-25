from sys import stdin

def top(stack):
    if len(stack) != 0:
        return stack[-1]
    
    else:
        return -1

repeat = int(stdin.readline())
heights = []

for i in range(repeat):
    num = int(stdin.readline())
    heights.append(num)

pass_count = 0
position = repeat
answers = []
for i in range(repeat):
    current_height = heights.pop()
    position -= 1

    if current_height <= top(heights):
        answers.append(position)
        while(pass_count > 0):
            answers.append(position)
            pass_count -= 1


    else:
        pass_count += 1

while(pass_count > 0):
    answers.append(0)
    pass_count -= 1

answers.append(0)

for i in range(repeat):
    print(answers.pop())
        
        

'''
1. 스택을 쌓는다.
2. pop을 한다.
3. pop 한 수와 스택의 top을 비교한다.
4-1. top이 크면 바로 수신.
4-2. 아니라면 pass 한다.
5. pass 후에 만나면 pass한 횟수만큼 수신.
6. 못 만나면 pass 횟수만큼 0
'''