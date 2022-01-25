# K번 이상 등장하는 요소를 추출하라.

nums = [1,1,1,2,2,3]
k = 2

def count(list):
    count_list ={}
    for i in list:
        if i not in count_list:
            count_list[i] = 1
        else:
            count_list[i] = count_list[i]+1
            
    return count_list

result = count(nums)
print(result)

#dictionary를 for문에 활용할 때, enumerate로 key,value 따로 받기
for key,val in enumerate(result):
    if val >= k:
        print(key)
