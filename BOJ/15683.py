N, M = map(int, input().split())

min_zero = N*M
office = list()
cctvs = list()
walls = list()
for r in range(N):
    row = list(map(int, input().split()))
    office.append(row)
    for c,item in enumerate(row):
        if item != 0 and item != 6:
            cctvs.append([item,r,c])

cctv_cnt = len(cctvs)

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


def copy_office(office):
    new_office = [[0 for j in range(M)] for i in range(N)]
    for n in range(N):
        for m in range(M):
            new_office[n][m] = office[n][m]
    return new_office

def check_site(current_office, arr):

    for idx in range(cctv_cnt):
        if cctvs[idx][0] == 1:
            r = cctvs[idx][1]
            c = cctvs[idx][2]
            while(r >= 0 and r <N and c>=0 and c<M):
                if current_office[r][c] == 6:
                    break
                current_office[r][c] = "#"
                r += dr[arr[idx]]
                c += dc[arr[idx]]

                
        elif cctvs[idx][0] == 2:
            
            for x in range(0,3,2):

                r = cctvs[idx][1]
                c = cctvs[idx][2]

                while(r >= 0 and r <N and c>=0 and c<M):
                    if current_office[r][c] == 6:
                        break
                    current_office[r][c] = "#"
                    r += dr[arr[idx]+x]
                    c += dc[arr[idx]+x]
        
        elif cctvs[idx][0] == 3:
            for x in range(2):

                r = cctvs[idx][1]
                c = cctvs[idx][2]

                while(r >= 0 and r <N and c>=0 and c<M):
                    if current_office[r][c] == 6:
                        break
                    current_office[r][c] = "#"
                    r += dr[(arr[idx]+x)%4]
                    c += dc[(arr[idx]+x)%4]
        elif cctvs[idx][0] == 4:
            for x in range(3):

                r = cctvs[idx][1]
                c = cctvs[idx][2]

                while(r >= 0 and r <N and c>=0 and c<M):
                    if current_office[r][c] == 6:
                        break
                    current_office[r][c] = "#"
                    r += dr[(arr[idx]+x)%4]
                    c += dc[(arr[idx]+x)%4]
        elif cctvs[idx][0] == 5:
            for x in range(4):

                r = cctvs[idx][1]
                c = cctvs[idx][2]

                while(r >= 0 and r <N and c>=0 and c<M):
                    if current_office[r][c] == 6:
                        break
                    current_office[r][c] = "#"
                    r += dr[(arr[idx]+x)%4]
                    c += dc[(arr[idx]+x)%4]
    return current_office


def make_cases(total, picked, arr:list):
    global min_zero
    if picked == total:
        # print(arr)
        co = copy_office(office)
        checked_office = check_site(co, arr)
        # print(checked_office)
        zero_cnt = 0
        for n in range(N):
            zero_cnt+= checked_office[n].count(0)
        
        # print(f"zero:{zero_cnt}")
        if zero_cnt < min_zero:
            min_zero = zero_cnt
        return
    

        
    if cctvs[picked][0] in [1,3,4]:
        for dir in range(4):
            arr.append(dir)
            make_cases(total, picked+1, arr)
            arr.pop()
        
    elif cctvs[picked][0] == 2:
        for dir in range(2):
            arr.append(dir)
            make_cases(total, picked+1, arr)
            arr.pop()

    else:
        arr.append(0)
        make_cases(total, picked+1, arr)
        arr.pop()


make_cases(cctv_cnt, 0, [])

print(min_zero)