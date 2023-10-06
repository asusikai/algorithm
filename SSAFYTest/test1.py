
T = int(input())
for test_case in range(1, T + 1):
    #######################################################################################################

    N, S = map(int, input().split())

    points: list = list(map(int, input().split()))

    points.sort()
    answer: int = 0
    if S < points[0]:
        answer = points[-1]-S

    elif S > points[-1]:
        answer = S-points[0]

    else:
        if S-points[0] > points[-1]-S:
            answer = points[-1] - S + points[-1] - points[0]
        else:
            answer = S - points[0] + points[-1] - points[0]

    #######################################################################################################

    # 표준출력(화면)으로 답안을 출력합니다.
    print(f"#{test_case} {answer}")
