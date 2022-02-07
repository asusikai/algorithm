'''
1. 방문여부 check , 방문 순서 상관 없음
2. 칸 내용 합, 칸 개수 count
3. bfs 반복 횟수 count -> 아무 변화 없으면 종료
'''

from collections import deque
from sys import stdin

size, min_diff, max_diff = map(int, stdin.readline().split())

graph = []

for i in range(size):
    graph.append(list(map(int, stdin.readline().split())))

visited = []

def movement(graph, x,y):
    start_point = list([x,y])
    if start_point in visited:
        return False
    
    que = deque([start_point])
    visited.append(start_point)
    population = 0
    country_num = 0
    
    while(que):
        front = que.popleft()
        x = front[0]
        y = front[1]
        population += graph[x][y]
        country_num += 1
        
        if (x>=0 and x<size and y-1>=0 and y-1<size) and ([x,y-1] not in visited) and (max_diff >= abs(graph[x][y-1] - graph[x][y]) >= min_diff):
            que.append([x,y-1])
            visited.append([x,y-1])
        
        if (x>=0 and x<size and y+1>=0 and y+1<size) and ([x,y+1] not in visited) and (max_diff >= abs(graph[x][y+1] - graph[x][y]) >= min_diff):
            que.append([x,y+1])
            visited.append([x,y+1])
            
        if (x-1>=0 and x-1<size and y>=0 and y<size) and ([x-1,y] not in visited) and (max_diff >= abs(graph[x-1][y] - graph[x][y]) >= min_diff):
            que.append([x-1,y])
            visited.append([x-1,y])
            
        if (x+1>=0 and x+1<size and y>=0 and y<size) and ([x+1,y] not in visited) and (max_diff >= abs(graph[x+1][y] - graph[x][y]) >= min_diff):
            que.append([x+1,y])
            visited.append([x+1,y])
    
    if country_num == 1:
        return False

    avg_population = (population//country_num)

    for i in visited[visited.index(start_point):]:
        graph[i[0]][i[1]] = avg_population
    
    return True

count = 0

rt = True

while( rt == True):
    rt = False
    for i in range(size):
        for j in range(size):
            result = movement(graph, i,j)
            if result:
                rt = True
    if rt:
        count += 1
    
    visited = []

print(count)