#include<iostream>
#include<queue>

#define MAX_N 100001
#define MAX_HEIGHT 19
using namespace std;

int depth[MAX_N];
int parents[MAX_N][MAX_HEIGHT];

int N;
int node_num;
int height;

bool visited[MAX_N] = { false };
queue<int> q;
queue<int> result;

void init() {

	for (int i = 0; i < MAX_N; i++) {
		depth[i] = 0;
	}

	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_HEIGHT; j++) {
			parents[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_N; i++) {
		visited[i] = false;
	}

	while (!q.empty()) {
		q.pop();
	}

	while (!result.empty()) {
		result.pop();
	}

	height = 1;
	depth[1] = 1;
}

void set_height(int child, int parent) {
	depth[child] = depth[parent] + 1;
	height = max(height, depth[child]);
}

void set_parent(int child, int parent) {
	parents[child][0] = parent;
}

void fill_parents() {
	for (int i = 1; i <= height; i++) {
		for (int j = 0; j <= N; j++) {
			parents[j][i] = parents[parents[j][i - 1]][i - 1];
		}
	}
}

int LCA(int a, int b) {
	
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = height; i >= 0; i--) {
		long long diff = depth[a] - depth[b];
		if (diff >= (1 << i)) {
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

	return parents[a][0];
}

queue<int> bfs() {

	int f;

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		f = q.front();
		q.pop();
		result.push(f);
		
		for (int i = 1; i <= N ; i++) {
			if (parents[i][0] == f && !visited[i]) {
				q.push(i);
				visited[i] = true;
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
11;		for (int i = 2; i <= N; i++) {
			cin >> node_num;
			set_parent(i, node_num);
			set_height(i, node_num);
		}
		
		fill_parents();
		bfs();
		long long route = 0;
		int f = result.front();
		result.pop();
		int end, lca;
		while(!result.empty()) {

			end = result.front();
			result.pop();
			lca = LCA(f, end);
			route += (depth[f] - depth[lca]);
			route += (depth[end] - depth[lca]);
			f = end;
		}

		cout << "#" << test_case << " " << route << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}