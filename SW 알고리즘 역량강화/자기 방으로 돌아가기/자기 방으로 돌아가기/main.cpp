#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

//����ü : �� ����
struct room {
    //���� �� ��ȣ, ���� �� ��ȣ
    int start, finish;
};

int N;
vector<room> v;
bool visited[400];
int answer;

//���� ����(���� �� ��ȣ�� ���� ����)
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

        //�ʱ�ȭ
        N = 0;
        v.clear();
        memset(visited, false, sizeof(visited));
        answer = 0;

        //�Է�
        cin >> N;
        for (int i = 0; i < N; i++) {

            int room1, room2;
            cin >> room1 >> room2;

            //���� ��ȣ �濡�� ū ��ȣ ������ ����ϵ��� ����
            if (room1 > room2) {
                v.push_back({ room2, room1 });
            }
            else {
                v.push_back({ room1, room2 });
            }
        }

        //����(���� �� ��ȣ�� ���� �������)
        sort(v.begin(), v.end(), compare);

        //�ð� ���
        while (true) {

            //��� �л��� ������ ���ư� ��� -> ����
            if (allStudentReturn()) {
                break;
            }

            int finish = 0;

            //��� �л� ����
            for (int i = 0; i < N; i++) {

                //���� ���� �̵����� ���Ͽ��� && ������ ��ġ�� ���� ��� -> ���ÿ� ������ �� ����
                if (!visited[i] && v[i].start > finish) {

                    //�湮 ó��
                    visited[i] = true;

                    //���� Ȧ���� ��� -> ���� ������ �ᱹ �� ��ȣ�� ¦���� ���� ����
                    if (v[i].finish % 2 == 1) {
                        finish = v[i].finish + 1;
                    }
                    else {
                        finish = v[i].finish;
                    }
                }
            }

            //�ð� + 1
            answer++;
        }

        //��� ���
        cout << "#" << test_case << " " << answer << "\n";
    }

    //����
    return 0;
}
