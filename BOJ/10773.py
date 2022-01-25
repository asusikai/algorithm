repeat = int(input())

nums = []

for i in range(repeat):
    num = int(input())
    if num == 0:
        nums.pop()
    else:
        nums.append(num)

answer = 0

for i in nums:
    answer += i
    
print(answer)

