
def check(word):
    stack = []
    for a in word:
        if(a not in stack):
            stack.append(a)
        elif(a == stack[-1]):
            pass
        else:
            return 0
    
    return 1
            

repeat = int(input())
words = []
result_num = 0

for i in range(repeat):
    word_input = input()
    result_num += check(word_input)
    
print(result_num)