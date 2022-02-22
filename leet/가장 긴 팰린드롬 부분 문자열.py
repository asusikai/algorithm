'''

양 방향 포인터 2쌍을 사용하여 체크한다
짝수 팰린드롬, 홀수 팰린드롬 체크

'''

from collections import deque

palindrome = deque()

inputs = "12345678987654321"

def checker(string, front, end):
    
    if front <0 or end>=len(string):
        return
    
    if string[front] == string[end]:
        if front != end:
            palindrome.appendleft(string[front])
            palindrome.append(string[end])
            
        
        else:
            palindrome.append(string[front])
        
        checker(string, front-1, end+1)

final = deque()

for i in range(len(inputs)):
    checker(inputs, i, i)
    final = final if len(final) > len(palindrome) else palindrome.copy()
    palindrome.clear()
    
    checker(inputs, i, i+1)
    final = final if len(final) > len(palindrome) else palindrome.copy()
    palindrome.clear()

print("".join(final))
