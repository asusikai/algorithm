#dfs - graph = 탐색할 그래프, n은 그래프 크기

def dfs(graph, n, point, count):
            
    #스택 선언
    stack = []
    
    #시작
    visit[point[0]][point[1]] = 1
    stack.append(point)
    
    #인접 노드 방문
    
    while(stack): #종료 조건 = 스택이 비었을 때
        #상
        if(point[1]>0 and graph[point[0]][point[1]-1] != 0 and visit[point[0]][point[1]-1] == 0):
            point[1] -= 1
            stack.append(point)
            visit[point[0]][point[1]] = 1
        
        #하
        elif(point[1]<n-1 and graph[point[0]][point[1]+1] != 0 and visit[point[0]][point[1]+1] == 0):
            point[1] += 1
            stack.append(point)
            visit[point[0]][point[1]] = 1
        
        #좌
        elif(point[0]>0 and graph[point[0]-1][point[1]] != 0 and visit[point[0]-1][point[1]] == 0):
            point[0] -= 1
            stack.append(point)
            visit[point[0]][point[1]] = 1
            
        #우
        elif(point[0]<n-1 and graph[point[0]+1][point[1]] != 0 and visit[point[0]+1][point[1]] == 0):
            point[0]+= 1
            stack.append(point)
            visit[point[0]][point[1]] = 1

        #막힐 경우
        else:
            point = stack.pop()
    
    #인접 종료 후
    
    count+=1
    return point
##########################

g1 = [[1,1,0,1,0],
        [0,0,0,0,1],
        [1,1,0,0,0],
        [1,0,1,0,1],
        [1,1,1,0,1]]

count = 0

#방문 여부 초기화
visit = []
for i in range(5):
        for j in range(5):
            visit.append(0)
            
point =[0,0]

while(0 in visit):
    if(g1[point[0]][point[1]] != 0 and visit[point[0]][point[1]] == 0):
        dfs(g1,5,point,count)
    
    if(point[0] == 4):
        if(point[1]<4):
            point[1] += 1
    else:
        point[0] += 1

print(count)
'''
dfs 함수
1. 모든 값이 0으로 초기화 된 방문 여부 리스트 선언
2. 방문 노드를 쌓을 스택 선언
3. 인접 노드 방문 -> 스택에 추가 & 방문여부 체크, 막히면 pop하여 이전 노드로 회귀
4. 다 막히면 전부 pop 하고 영역 count 추가
5. 다음 미방문 영역을 찾아 나선다.

전체
1. 머리아파
'''