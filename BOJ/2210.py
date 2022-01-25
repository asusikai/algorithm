def dfs(x,y,comb):
    
    if(len(comb) == 6):
        if comb not in result:
            result.append(comb)
        return
            
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    for i in range(4):
        nx=x+dx[i]
        ny=y+dy[i]
        if nx<0 or nx>=5 or ny<0 or ny>=5:
            continue
        else:
            dfs(nx,ny,comb+graph[nx][ny])
        

graph = []
for i in range(5):
    graph.append(list(map(str, input().split())))
    
result = []

for j in range(5):
    for k in range(5):
        dfs(j,k,graph[j][k])

print(len(result))