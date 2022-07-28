/*
1. 잠기는 높이 입력받기
2. 배열에 해수면 입력 받기
3. 칸마다 체크할것 - 잠겼는지 여부, 방문 여부
4. 한 덩이 끝나면 count 증가

*/

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
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제 
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

int matrix[101][101]={0};	
int visited[101][101]={0};
int ans[101]={0};

int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};

void dfs(int n, int m, int h){
	int i;
	visited[n][m]=1;
	//printf("[%d, %d] ", n, m);
	for(i=0;i<4;i++){
		if((visited[n+dx[i]][m+dy[i]]==0) && (matrix[n+dx[i]][m+dy[i]]>h)){
			dfs(n+dx[i], m+dy[i], h);
		}
	}
}

void init(int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			visited[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrix[i][j]=0;
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	printf("%d",T);

	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		int n, m, i, j, k=0, h, max=0;
		k=0;
		scanf("%d", &n);
		for(i=0;i<n;i++){
			for(j=0; j<n; j++){
				int num;
				scanf("%d", &num);
				if(num>max){
					max=num;
				}
				matrix[i][j]=num;
			}
		}

		for(h=0; h<=max; h++){ //높이0부터 max까지 
			init(n);

			for(i=0; i<n; i++){
				for(j=0; j<n; j++){
					if((matrix[i][j]>h) && (visited[i][j]==0)){
						dfs(i, j, h);
						ans[h]++;

					}
				}
			}

		}

		k=0;

		for(i=0;i<h;i++){ //정답배열중에 가장큰수 
			if(ans[i]>k){

				k=ans[i];
			}
		}
		printf("%d", k);

		for(i = 0; i<n; i++){
			for(j=0; j<n; j++){
				matrix[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for(i=0; i<h; i++){
			ans[h] = 0;
		}
		
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}