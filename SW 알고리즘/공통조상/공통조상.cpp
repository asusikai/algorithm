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

#include<iostream>
#include<vector>

using namespace std;

struct Node{
	int node_num;
	Node* parent;
	Node* left;
	Node* right;
};
Node get_node(int node_num);
Node* make_tree(int V, int E);
vector<Node*> get_ancesters(Node* node);
int get_tree_size(Node* root);

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
	T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int V;
		int E;
		int node1, node2;

		cin>>V>>E>>node1>>node2;
		Node* root = make_tree(V, E);
		vector<Node*> first_ancesters;
		first_ancesters.clear();
		first_ancesters = get_ancesters(&root[node1]);
		
		/*
		for(size_t i=0; i<first_ancesters.size(); i++){
			cout<<first_ancesters.at(i)->node_num<<endl;
		}*/
		
		vector<Node*> second_ancesters;
		second_ancesters.clear();
		second_ancesters = get_ancesters(&root[node2]);
		/*
		for(size_t i=0; i<second_ancesters.size(); i++){
			cout<<second_ancesters.at(i)->node_num<<endl;
		}
		*/

		Node* closest_ancester;
		
		int flag=0;

		for(size_t i=0; i<first_ancesters.size(); i++){
			for(size_t j=0; j<second_ancesters.size(); j++){
				if(first_ancesters.at(i)->node_num == second_ancesters.at(j)->node_num){
					//cout<<"closest ancester:"<<first_ancesters.at(i)->node_num<<endl;
					flag = 1;
					closest_ancester = first_ancesters.at(i);
					break;
				}
			}
			if(flag == 1){
				break;
			}
		}
		int size = get_tree_size(closest_ancester);
		cout<<"#"<<test_case<<" "<<closest_ancester->node_num<<" "<<size<<endl;

		delete root;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

Node get_node(int node_num){
	Node new_node;
	new_node.node_num = node_num;
	new_node.left = nullptr;
	new_node.right = nullptr;
	new_node.parent =nullptr;

	return new_node;
}

Node* make_tree(int V, int E){
	Node* tree = new Node[V+1];

	for(int i=1; i<=V; i++){
		tree[i] = get_node(i);
		//cout<<tree[i].node_num<<endl;
	}

	for(int i=1; i<=E; i++){
		int parent, child;

		cin>>parent>>child;
		//cout<<"parent:"<<parent<<"child:"<<child<<"\n";

		if(tree[parent].left == nullptr){
			tree[parent].left = &tree[child];
			tree[child].parent = &tree[parent];
			//cout<<"inserted left"<<endl;

			continue;
		}

		if(tree[parent].right == nullptr){
			tree[parent].right = &tree[child];
			tree[child].parent = &tree[parent];
			//cout<<"inserted right"<<endl;
			continue;
		}

		cout<<"branch full!\n";
	}

	return tree;
}

vector<Node*> get_ancesters(Node* node){
	vector<Node*> ancesters;
	ancesters.clear();
	Node* temp = node;
	ancesters.push_back(temp);
	while(temp->parent != nullptr){
		ancesters.push_back(temp->parent);
		temp = temp->parent;
	}

	return ancesters;
}



int get_tree_size(Node* root){

	int lc = 0;
	int rc = 0;
	if(root->left != nullptr){
		lc = get_tree_size(root->left);
	}

	if(root->right != nullptr){
		rc = get_tree_size(root->right);
	}

	return lc+rc+1;

}