inputs = []

while(True):
    sen = input()
    
    if(sen =="."):
        break
    else:
        inputs.append(sen)
    

def top(stack):
    if len(stack) != 0 :
        return stack[-1]
    
    else:
        return False

for i in inputs:
    stack = []
    for w in i:
        
        if(w == '[' or w == '('):
            stack.append(w)
            
        elif(w == ']' and top(stack) != '['):
            stack.append(w)
            
        elif(w == ')' and top(stack) != '('):
            stack.append(w)
        
        elif(w == ']' and top(stack) == '['):
            stack.pop()
            
        elif(w == ')' and top(stack) == '('):
            stack.pop()
        
        else:
            pass
    if len(stack) == 0:
        print("yes")
    else:
        print("no")