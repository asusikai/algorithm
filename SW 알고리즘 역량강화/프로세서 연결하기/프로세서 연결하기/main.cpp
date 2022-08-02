/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
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

// ans1 = ��ġ �ִ� ����
// ans2 = ���� �ּ� ����
// install = ��ġ ����
// sum = ���� ����

void dfs(int ind, int cnt, int install, int sum) {
    // ��� �ھ� �۾��� ���� ���
    if (cnt == core.size()) {
        // �ִ��� �ھ ��ġ���� ��, �ּ��� ���� ����
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

    // ��ġ�ϴ� ���
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
            // ���� ��ġ
            for (int j = 0; j < tmp.size(); j++) {
                map[tmp[j].x][tmp[j].y] = 2;
            }

            dfs(ib nd + 1, cnt + 1, install + 1, sum + (int)tmp.size());

            // ���� ��ü
            for (int j = 0; j < tmp.size(); j++) {
                map[tmp[j].x][tmp[j].y] = 0;
            }
        }
    }

    // ��ġ���� �ʴ� ���
    dfs(ind + 1, cnt + 1, install, sum);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
        core.clear();

        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];

                if (map[i][j] == 1) {
                    // �����ڸ� �ھ���� ����
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}