def solution(arr1, arr2):
    answer = [[]]
    answer = [0 for _ in range(len(arr1[0])) for _ in range(len(arr1))]
    x1=0
    for a1, a2 in arr1, arr2:
        for i,j in enumerate(a1),enumerate(a2):
            answer[1][1] = i[1]+j[1]
        x1+=1
        
    
    return answer


arr1 = [[1,2],[2,3]]
arr2 = [[3,4],[5,6]]

print(solution(arr1, arr2))