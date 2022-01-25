def sort(list):
    list.sort(key=len)

    for i in range(len(list)):
        for j in range(i,len(list)-1):
            if list[j]>list[j+1] and len(list[j]) == len(list[j+1]):
                list[j], list[j+1] = list[j+1], list[j]

repeat = int(input())
words = []

for i in range(repeat):
    word = input()
    if word not in words:
        words.append(word)

sort(words)

for i in words:
    
    print(i)