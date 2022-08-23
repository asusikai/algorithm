#include<iostream>
#include<queue>

#define MAX_N 10001

using namespace std;

int depth[MAX_N];
int parents[MAX_N][15];

int N;
int node_num;
int height;

void init() {

	for (int i = 0; i < MAX_N; i++) {
		depth[i] = 0;
	}
	depth[1] = 1;

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < 15; j++) {
			parents[i][j] = 0;
		}
	}

	height = 1;
}

void set_height(int child, int parent) {
	depth[child] = depth[parent] + 1;
	height = max(height, depth[child]);
}

void set_parent(int child, int parent) {
	parents[parent][0] = child;
}

void fill_parents() {
	for (int i = 1; i < height; i++) {
		for (int j = 1; j < N + 1; j++) {
			parents[j][i] = parents[parents[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	int ad = depth[a];
	int bd = depth[b];

	if (ad < bd) {
		int temp = ad;
		ad = bd;
		bd = temp;
	}

	for (int i = height-1; i >= 0; i--) {
		if (ad - bd >= (1 << i)) {
			a = parents[a][i];
		}
	}

	if (a == b) return a;

	for (int i = height; i >= 0; i--) {
		if (parents[a][i] != parents[b][i]) {
			a = parents[a][i];
			b = parents[b][i];
		}
	}
	// 반복이 끝났으면 공통된 조상노드 직전까지 온 상태

	return parents[a][0];
}

queue<int> bfs() {
	bool visited[MAX_N];
	queue<int> q;
	queue<int> result;
	q.push(1);
	
	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		result.push(front);
		visited[front] = true;
		
		for (int i = 0; i < MAX_N; i++) {
			if (parents[i][0] == front) {
				q.push(i);
			}
		}
	}

	return result;
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();

		cin >> N;
		for (int i = 2; i <= N; i++) {
			cin >> node_num;
			set_parent(i, node_num);
			set_height(i, node_num);
		}

		queue<int> res = bfs();

		int route = 0;
		int front = res.front();
		res.pop();
		int end;
		for (int i = 1; i < N; i++) {

			end = res.front();
			res.pop();

			route += depth[front] - depth[LCA(front, end)] + depth[end] - depth[LCA(front, end)];
			front = end;
		}

		cout << "#" << test_case << " " << route << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}