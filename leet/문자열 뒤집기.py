'''
1. 문자로 이루어진 리스트 입력 받기
2. 리스트 자체를 reverse 하기
3. 리스트 반환하기
'''
from collections import deque

input_list = list(map(str, input().split()))

stack = list()
length = len(input_list)
for _ in range(length):
    stack.append(input_list.pop(0))

for _ in range(length):
    input_list.append(stack.pop())

print(input_list)