from ast import Delete


from sys import stdin
default_input = stdin.readline().strip()

cursor = len(default_input)

def order(order_input,string_input, cursor):
    if order_input[0] == 'L' and cursor != 0:
        cursor -= 1
        return string_input,cursor
    
    elif order_input[0] == 'D' and len(string_input) > cursor:
        cursor += 1
        return string_input,cursor
    
    elif order_input[0] == 'B' and cursor != 0:
        a = string_input[:cursor-1]+string_input[cursor:]
        cursor -= 1
        return a , cursor
    
    elif order_input[0] == 'P':
        return string_input[:cursor] + order_input[1] + string_input[cursor:],cursor+1
    
    else:
        return string_input, cursor


order_num = int(input())
result = default_input
for i in range(order_num):
    o = input().split()
    result,cursor = order(o,result, cursor)

print(result)