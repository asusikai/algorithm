#include<iostream>
#include<list>

using namespace std;

struct treeNode {

	int parent;
	int first;
	int second;
};

treeNode tree[10001];
list<int> first_parents;
list<int> second_parents;

int V, E, node1, node2;
int tree_size;

void init() {

	for (int i = 0; i < 10001; i++) {
		
		tree[i].parent = 0;
		tree[i].first = 0;
		tree[i].second = 0;
	}

	first_parents.clear();
	second_parents.clear();

	tree_size = 0;
}

void set_node(int num, int child) {

	tree[child].parent = num;

	if (tree[num].first == 0) {
		tree[num].first = child;
	}

	else {
		tree[num].second = child;
	}
}

void find_parents(int num, list<int>* L) {
	
	int temp;
	temp = tree[num].parent;
	
	while (temp >= 1) {
		(* L).push_back(temp);
		temp = tree[temp].parent;
	}
}

void travel(int root) {

	tree_size++;
	if (tree[root].first != 0) {
		travel(tree[root].first);
	}

	if (tree[root].second != 0) {
		travel(tree[root].second);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();

		cin >> V >> E >> node1 >> node2;
		int parent, child;
		for (int i = 0; i < E; i++) {
			cin >> parent >> child;
			set_node(parent, child);
		}

		find_parents(node1, &first_parents);
		find_parents(node2, &second_parents);
		int flag = 0;
		int subroot = 1;
		for (auto i = first_parents.begin(); i != first_parents.end(); i++) {

			for (auto j = second_parents.begin(); j != second_parents.end(); j++) {

				if (*i == *j) {
					subroot = (*i);
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}

		if (subroot == 0) {
			tree_size = V;
		}
		else {
			travel(subroot);
		}

		cout << "#" << test_case << " " << subroot << " " << tree_size << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}