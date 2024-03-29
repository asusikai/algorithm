/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 12
#define INF 987654321

using namespace std;

struct node {
	int x, y;

	node() { }
	node(int _x, int _y) : x(_x), y(_y) { }
};

int n, ans1, ans2;
int map[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<node> core;

// ans1 = 설치 최대 개수
// ans2 = 전선 최소 개수
// install = 설치 개수
// sum = 전선 개수

void dfs(int ind, int cnt, int install, int sum) {
    // 모든 코어 작업을 끝낸 경우
    if (cnt == core.size()) {
        // 최대의 코어를 설치했을 때, 최소의 전선 개수
        if (install > ans1) {
            ans1 = install;
            ans2 = sum;
        }
        else if (install == ans1) {
            ans1 = install;
            ans2 = min(ans2, sum);
        }

        return;
    }

    // 설치하는 경우
    for (int i = 0; i < 4; i++) {
        vector<node> tmp;

        bool flag = false;
        int nr = core[ind].x;
        int nc = core[ind].y;

        while (1) {
            if (nr == 0 || nc == 0 || nr == n - 1 || nc == n - 1) {
                flag = true;
                break;
            }

            nr += dx[i];
            nc += dy[i];

            if (map[nr][nc] == 0) {
                tmp.push_back(node(nr, nc));
            }
            else {
                break;
            }
        }

        if (flag) {
            // 전선 설치
            for (int j = 0; j < tmp.size(); j++) {
                map[tmp[j].x][tmp[j].y] = 2;
            }

            dfs(ib nd + 1, cnt + 1, install + 1, sum + (int)tmp.size());

            // 전선 해체
            for (int j = 0; j < tmp.size(); j++) {
                map[tmp[j].x][tmp[j].y] = 0;
            }
        }
    }

    // 설치하지 않는 경우
    dfs(ind + 1, cnt + 1, install, sum);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
        core.clear();

        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];

                if (map[i][j] == 1) {
                    // 가장자리 코어들은 제외
                    if (i == 0 || j == 0 || i == n - 1 || j == n - 1) continue;

                    core.push_back(node(i, j));
                }
            }
        }

        ans1 = 0;
        ans2 = INF;
        dfs(0, 0, 0, 0);

        cout << "#" << test_case << " " << ans2 << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}