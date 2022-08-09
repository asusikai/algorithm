#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

//구조체 : 방 정보
struct room {
    //시작 방 번호, 도착 방 번호
    int start, finish;
};

int N;
vector<room> v;
bool visited[400];
int answer;

//정렬 기준(시작 방 번호에 따라 정렬)
bool compare(room r1, room r2) {
    if (r1.start == r2.start) {
        return r1.finish < r2.finish;
    }
    return r1.start < r2.start;
}

bool allStudentReturn() {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; test_case++) {

        //초기화
        N = 0;
        v.clear();
        memset(visited, false, sizeof(visited));
        answer = 0;

        //입력
        cin >> N;
        for (int i = 0; i < N; i++) {

            int room1, room2;
            cin >> room1 >> room2;

            //작은 번호 방에서 큰 번호 방으로 출발하도록 설정
            if (room1 > room2) {
                v.push_back({ room2, room1 });
            }
            else {
                v.push_back({ room1, room2 });
            }
        }

        //정렬(시작 방 번호가 작은 순서대로)
        sort(v.begin(), v.end(), compare);

        //시간 계산
        while (true) {

            //모든 학생이 방으로 돌아간 경우 -> 종료
            if (allStudentReturn()) {
                break;
            }

            int finish = 0;

            //모든 학생 점검
            for (int i = 0; i < N; i++) {

                //아직 방을 이동하지 못하였고 && 복도가 겹치지 않을 경우 -> 동시에 움직일 수 있음
                if (!visited[i] && v[i].start > finish) {

                    //방문 처리
                    visited[i] = true;

                    //방이 홀수인 경우 -> 쓰는 복도는 결국 방 번호가 짝수인 경우와 같다
                    if (v[i].finish % 2 == 1) {
                        finish = v[i].finish + 1;
                    }
                    else {
                        finish = v[i].finish;
                    }
                }
            }

            //시간 + 1
            answer++;
        }

        //결과 출력
        cout << "#" << test_case << " " << answer << "\n";
    }

    //종료
    return 0;
}
