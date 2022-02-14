'''
1. 입력 받기
2. 팰린드롬 체크 - 문자열과 숫자만, 대소문자 구분 없음
3. true / false 출력
'''

import re

pal_check = input()

pal_check = pal_check.lower()
#print(pal_check)

stripped = re.sub('[^a-zA-Z0-9]','', pal_check).strip()
#print(stripped)

length = len(stripped)

for i in range(length):
    if stripped[i] != stripped[length-i-1]:
        print('false')
        exit()

print('true')