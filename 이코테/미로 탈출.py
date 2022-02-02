from collections import deque

n,m = map(int, input().split())

maze = []

for i in range(n):
    line = list(map(int, input()))

    maze.append(line)

def bfs(a,b):
    
    que = deque()
    que.append((a,b))
    
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    
    while que:
        a,b = que.popleft()
                    
        for i in range(4):
            nx, ny = a+dx[i], b+dy[i]
            
            if nx<0 or nx>=n or ny<0 or ny>=m:
                continue
            
            if maze[nx][ny] == 0:
                continue
            
            if maze[nx][ny] == 1:
                maze[nx][ny] = maze[a][b]+1
                que.append((nx,ny))
                
    return maze[n-1][m-1]

print(bfs(0,0))