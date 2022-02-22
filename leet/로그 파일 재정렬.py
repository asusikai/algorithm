'''
로그의 가장 앞 부분은 식별자
문자로 구성된 로그가 숫자 로그보다 앞에 온다
식별자는 순서에 영향을 끼치지 않지만, 문자가 동일할 경우 식별자 순으로 한다.
숫자 로그는 입력 순서 대로 한다.
'''

logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]

single_log = list(logs[1].split())

log_list = [list(i.split()) for i in logs]
#print(log_list)

for i in log_list:
    print
