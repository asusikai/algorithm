'''
문자열 리스트를 받아서 애너그램 단위로 그룹핑하라.

1. 문자열을 받아서 정렬
2. 같으면 같은 리스트에 추가
3. 다르면 다른 리스트에 추가
'''


inputs = ["eat", "tea", "tan", "ate", "nat", "bat"]

annagrams = []

for i in inputs:
    inside = False
    if annagrams:
        for j in range(len(annagrams)):
            if sorted(i) == sorted(annagrams[j][0]):
                annagrams[j].append(i)
                inside = True
                break
        if inside == True:
            pass
        else:
            annagrams.append([i])
    
    else:
        annagrams.append([i])
            
            
        
        
print(annagrams)