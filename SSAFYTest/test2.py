"""
N개의 양수 혹은 음수의 정수 값을 가진 수열 A[1], A[2], …, A[N]이 주어진다.



수열의 전체 합이 2N (N 곱하기 2) 이상이 되도록 하고 싶다. 할 수 있는 작업은 어떤 i(1 ≤ i ≤ N)를 선택하여 A[i]를 max(A[i] + i, i)로 바꾸는 것이다.



여기서, max(A[i] + i, i)는 A[i] + i와 i 중 큰 값을 말한다. 동일한 원소에 대해서는 작업을 최대 한번만 할 수 있음에 주의하라.





예를 들어 N = 4이고 A[1] = 1, A[2] = -2, A[3] = 2, A[4] = 3이라고 하자.



A[1]을 바꾼다면 max(A[1]+1, 1)이 2가 되므로 2로 바꿀 수 있다. A[3]을 바꾼다면 마찬가지로 max(A[3]+3, 3)인 5로 바꿀 수 있다.



A[1] = 1, A[2] = -2, A[3] = 2, A[4] = 3에서 최소 작업 횟수로 조건을 만족하도록 만드는 방법 중 한가지는 A[2]를 바꾸는 것인데,



A[2]를 max(A[2]+2, 2)인 2로 바꾸면 전체 합이 1 + 2 + 2 + 3 = 8이 되어서 N의 두 배 이상이 된다.


이 예에서는 한번만 바꾸면 목표가 달성되었지만, 다른 예에서는 여러 번의 작업을 해야 할 수 있다.



또, 주어진 수열이 이미 목표를 만족하는 경우에는 작업을 할 필요가 없어서 최소 작업 횟수는 0이 된다.



수열을 입력으로 받아 목표를 달성하기 위한 최소 작업 횟수를 계산하는 프로그램을 작성하라.





[제약사항]

1.     수열의 길이 N은 4 이상 1,000 이하이다. (4 ≤ N ≤ 1,000)

2.     수열의 각 원소는 절대값이 100,000이하인 정수이다.





[입력]

가장 첫 줄에는 테스트 케이스의 총 수가 주어진다. 그 다음 줄부터 각 테스트 케이스가 주어지며, 각 테스트 케이스는 2줄로 구성된다.

각 테스트 케이스의 첫 줄에는 N이 주어진다. 다음 줄에 수열의 원소가 순서대로 주어진다.



[출력]

출력의 각 줄은 ‘#x’로 시작하고, 공백을 한 칸 둔 다음 최소 작업 회수를 출력한다. 단, x는 테스트 케이스의 번호이다.

[입력 예]

4                       // 테스트 케이스의 수

4                       // N=4, 테스트 케이스 #1

1 -2 2 3

4                       // N=4, 테스트 케이스 #2

8 1 1 2

7                       // N=7, 테스트 케이스 #3

3 -6 -4 5 -1 1 -6

9                       // N=9, 테스트 케이스 #4

-9 1 -7 -1 -3 -9 0 1 -3



[출력 예]

#1 1

#2 0

#3 3

#4 5
"""


T = int(input())
for test_case in range(1, T + 1):
    #######################################################################################################
    N = int(input())
    nums = list(map(int, input().split()))

    table = [[i+1, v] for i, v in enumerate(nums)]

    table.sort(lambda x: max(x[1]+x[0], x[0])-x[1], reverse=True)

    count: int = 0
    total: int = sum(nums)

    if total >= 2*N:
        pass
    else:
        for pair in table:
            total += max(pair[1] + pair[0], pair[0]) - pair[1]
            count += 1
            if total >= 2*N:
                break

    #######################################################################################################

    # 표준출력(화면)으로 답안을 출력합니다.
    print(f"#{test_case} {count}")