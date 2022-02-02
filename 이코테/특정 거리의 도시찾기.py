from collections import deque

city_num, road_num, distance, start_city = map(int, input().split())

graph = dict()

for _ in range(road_num):
    start, end = map(int, input().split())
    
    if start in graph:
        graph[start].append(end)
    
    else:
        graph[start] = [end]

def bfs(graph, start):
    
    que = deque()
    que.append(start)
    
    distance_list = [-1]*(city_num+1)
    distance_list[start] = 0
    
    while que:
        front = que.popleft()
        
        if front not in graph:
            continue
        
        for next_city in graph[front]:
            if distance_list[next_city] == -1:
                distance_list[next_city] = distance_list[front]+1
                que.append(next_city)
    
    return distance_list

distance_result=bfs(graph, start_city)

result = []

for i in range(city_num+1):
    if distance_result[i] == distance:
        result.append(i)

if result:
    print(result)
else:
    print(-1)