dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def search(bat, visited, y, x):

    if visited[y][x] or bat[y][x] == 0:
        return 0
    
    stk = [[y,x]]

    while(len(stk) > 0):
        current = stk.pop()

        for idx in range(4):
            ny = current[0]+dy[idx]
            nx = current[1]+dx[idx]

            if ny<0 or ny >= N or nx<0 or nx>=M :
                continue

            if visited[ny][nx]:
                continue

            if bat[ny][nx] == 0:
                continue

            stk.append([ny,nx])
            visited[ny][nx] = True

    return 1
T:int = int(input())

for tc in range(T):
    M, N, K = map(int, input().split())

    bat = [[0 for i in range(M)] for j in range(N)]

    for _ in range(K):
        X, Y = map(int, input().split())
        bat[Y][X] = 1


    visited = [[False for i in range(M)] for j in range(N)]

    bug = 0
    for n in range(N):
        for m in range(M):
            bug += search(bat, visited, n,m)

    print(bug) 






