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
#include<iostream>
#include<deque>


#define MAX_SIZE 300

using namespace std;

int dx[8] = { -1,0,1,1,1,0,-1,-1 };
int dy[8] = { -1,-1,-1,0,1,1,1,0 };

struct Node {
	int x, y;
	
	Node() { }
	Node(int _x, int _y) : x(_x),y(_y) {}
};

int N;//map size
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
deque<Node> dq;
int click;


void bfs_init() {

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
	dq.clear();
	click = 0;	
}

bool check_mines(int x, int y) {

	int nx, ny;

	for (int i = 0; i < 8; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[ny][nx] == '*') {
			return true;
		}
	}

	return false;
}

void bfs(int x, int y) {
	
	dq.push_back(Node(x, y));

	visited[y][x] = true;

	while (!dq.empty()) {
		Node curr = dq.front();
		dq.pop_front();

		
		for (int i = 0; i < 8; i++) {
			int nx = curr.x + dx[i];
			int ny = curr.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny][nx] && map[ny][nx] == '.') {

				visited[ny][nx] = true;
				
				if (!check_mines(nx, ny)) {
					dq.push_back(Node(nx, ny));
					
					
				}
			}
		}
		
	}
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
		bfs_init();
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '.' && !visited[i][j] && !check_mines(j,i)) {

					click++;
					bfs(j,i);
					
				}
			}
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && map[j][k] == '.') {
					click++;
				}
			}
		}

		cout << "#" << test_case << " " << click << endl;


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}