from sys import stdin, stdout

N = int(stdin.readline().rstrip())

meetings = list()

for n in range(N):
    meetings.append(list(map(int, stdin.readline().rstrip().split())))

sorted_meetings = sorted(meetings, key=lambda x: (x[1],x[0]))

total_meetings = len(sorted_meetings)


max_meetings = 0
last = 0

def find_max(idx, last, reserved_meetings):
    global max_meetings
    if idx == total_meetings:
        if max_meetings < reserved_meetings:
            max_meetings = reserved_meetings
        
        return
    
    if total_meetings - idx + reserved_meetings < max_meetings:
        return

    if (1<<31 - 1) <= last:
        return

    if sorted_meetings[idx][0] >= last:
        find_max(idx+1, sorted_meetings[idx][1], reserved_meetings+1)
        
    find_max(idx+1, last, reserved_meetings)


for meeting in sorted_meetings:
    
    if meeting[0] >= last:
        max_meetings+=1
        last = meeting[1]

print(max_meetings)
