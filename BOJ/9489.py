from sys import stdin

repeat = int(stdin.readline())

target_num = int(stdin.readline())



while(True):
    tree =[]
    levels = []
    level = 0
    if repeat == 0 and target_num == 0:
        pass
    else:
        for i in range(repeat):
            node = int(stdin.readline())
            tree.append(node)
            if tree:
                if tree[-1]+1 == node:
                    levels.append(level)
                    
                else:
                    level+=1
                    levels.append(level)
                    
                    
            else:
                levels.append(level)
            
    
    target_index = tree.index(target_num)
    target_level = levels[target_index]
    

'''
1. 수를 받으면서 연결되지 않을 때마다 2중 리스트의 다음으로 넘어간다.
2. target 과 일치하는 수를 찾으면 그 부모의 리스트의 자식 개수를 출력한다.
'''