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

#define MAX_N 200000
#define MAX_P 200000
#define MAX_DATE 1000000

using namespace std;

int study_count[MAX_DATE + 2 * MAX_P + 1];
int study_date[MAX_N];
int first_date;
int last_date;
int N, p;
int max_val;

void init() {

	for (int i = 0; i < MAX_DATE + 2 * MAX_P + 1; i++) {
		study_count[i] = 0;
	}

	max_val = 0;
}

void fill_study_count() {

	for (int i = 0; i < N; i++) {
		study_count[study_date[i]] = 1;
	}

	for (int j = 1; j <= last_date; j++) {
		if (study_count[j] == 1) {
			study_count[j] = study_count[j - 1] + 1;
		}
		else {
			study_count[j] = study_count[j - 1];
		}
	}
}

void find_max_date(int first, int last) {

	if (last <= first) {
		return;
	}

	int mid_date = first + (last - first) / 2;

	int x = p;

	if (mid_date == 0) {
		while (true) {
			if (study_count[x - 1] >= x - p) {
				x++;
			}
			else {
				break;
			}
		}
	}

	else {
		while (true) {
			if (study_count[mid_date - 1 + x] >= x + study_count[mid_date - 1] - p) {
				x++;
			}
			else {
				break;
			}
		}
	}

	
	max_val = max(max_val, x - 1);

	if ((study_count[mid_date]*2) >= N) {
		find_max_date(first, mid_date-1);
	}

	else {
		find_max_date(mid_date + 1, last);
	}

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();

		cin >> N >> p;

		for (int i = 0; i < N; i++) {
			cin >> study_date[i];
		}

		first_date = study_date[0] > p ? study_date[0] - p : 0;
		last_date = study_date[N - 1] + p;
		fill_study_count();
		find_max_date(first_date, last_date);

		cout << "#" << test_case << " " << max_val << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}