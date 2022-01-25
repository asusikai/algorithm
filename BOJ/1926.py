import sys
sys.setrecursionlimit(10**6)

n,m = map(int, input().split())

graph = []

for i in range(n):
    graph.append(list(map(int, input().split())))

count = 0
def dfs(x,y):
    
    if x<0 or x>=n or y<0 or y>=m:
        pass
    
    elif(graph[x][y]):
        graph[x][y] = 0
        
        global count 
        count+= 1
        
        dfs(x+1,y)
        dfs(x-1,y)
        dfs(x,y+1)
        dfs(x,y-1)
        
        return 1

result = []

for i in range(n):
    for j in range(m):
        if(dfs(i,j) == 1):
            result.append(count)
            count = 0

if(len(result) == 0):
    print(0)
    print(0)            

else:
    print(len(result))
    print(max(result))