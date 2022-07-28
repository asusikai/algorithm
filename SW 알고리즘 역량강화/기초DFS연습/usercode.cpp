// #include<iostream>
using namespace std;

int graph[100][6];

void dfs_init(int N, int path[100][2])
{
	for(int i=0; i<100; i++){
		for(int j=0; j<6; j++){
			graph[i][j] = 0;
		}
	}

	for(int i=0; i<N-1; i++){
		for(int j=1; j<6; j++){
			if(graph[path[i][0]][j] == 0){
				graph[path[i][0]][j] = path[i][1];
				break;
			}
		}
	}
	// cout<<"=====path check start\n";
	// for(int i=0; i<N-1; i++){
	// 	for(int j=0; j<2; j++){
	// 			cout<<path[i][j];
	// 	}

	// 	cout<<endl;
	// }
	// cout<<"=====path check done\n";
	// cout<<"=====graph check start\n";
	// for(int i=0; i<100; i++){
	// 	for(int j=1; j<6; j++){
	// 		if(graph[i][j] != 0){
	// 			cout<<i<<":"<<graph[i][j]<<endl;
	// 		}
			
	// 	}
	// }
	// cout<<"=====graph check done\n";
}

int dfs(int n)
{
	bool visited[100] = {false, };
	int top = -1;
	int stack[100];
	// cout<<"dfs start:"<<n<<endl;
	
	stack[++top] = n;
	while(top != -1){
		// cout<<"=====graph check start\n";
		// for(int i=0; i<100; i++){
		// 	for(int j=1; j<6; j++){
		// 		if(graph[i][j] != 0){
		// 			cout<<i<<":"<<graph[i][j]<<endl;
		// 		}
			
		// 	}
		// }
		// cout<<"=====graph check done\n";
		int curr = stack[top--];
		//cout<<"current node:"<<curr<<endl;
		if(!visited[curr]){
			if(curr > n){
				//cout <<"return"<<curr<<endl;
				return curr;
			}
			
			visited[curr] = true;
			for(int i = 5; i>0; i--){
				if(!visited[graph[curr][i]] && graph[curr][i] != 0){
					//cout<<"push:"<<graph[n][i]<<endl;
					stack[++top] = graph[curr][i];
				}

				// else{
				// 	if(visited[graph[n][i]]){
				// 		cout<<"visited "<<graph[n][i]<<endl;
				// 	}
				// 	else{
				// 		cout<<"just no push:"<<graph[n][i]<<endl;
				// 	}
					
				// }
			}
			//cout<<endl;
		}
	}

	//cout<<"return -1\n";

	return -1;
	
}