T = int(input())


called_count = [[0, 0] for _ in range(41)] 
called_count[0] = [1,0]
called_count[1] = [0,1]

for idx in range(2, 41):
    called_count[idx][0] = called_count[idx-1][0]+ called_count[idx-2][0]
    called_count[idx][1] = called_count[idx-1][1]+ called_count[idx-2][1]


for tc in range(1,T+1):
    seq:int = int(input())
    print(f"{called_count[seq][0]} {called_count[seq][1]}")

