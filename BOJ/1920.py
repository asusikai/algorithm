check_list = []
num_list = []

def num_check(check , num):
    for i in num:
        if i in check:
            print(1)
        else:
            print(0)
        


check_count = int(input())
check_list = list(map(int,input().split()))

num_count = int(input())

num_list = list(map(int,input().split()))
    
num_check(check_list, num_list)