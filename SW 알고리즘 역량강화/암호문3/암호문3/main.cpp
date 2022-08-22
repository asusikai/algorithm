#include <iostream>
#include <list>
using namespace std;

int N;
int target;
int commandNo;
char cType;
list <int> li;
auto itr = li.begin();
int main() {
	for (int tc = 1; tc <= 10; tc++) {
		li.clear();//리스트 초기화
		itr = li.begin();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> target;
			li.push_back(target);
		}
		cin >> commandNo;
		for (int cc = 0; cc < commandNo; cc++) {
			cin >> cType;
			int x, y, s;
			if (cType == 'I') {

				itr = li.begin();
				list<int> temp;

				cin >> x >> y;//앞에서부터 x의 위치 바로 다음에 y개 숫자 삽입
				for (int i = 0; i < x; i++) itr++;
				for (int i = 0; i < y; i++) {
					cin >> s;
					temp.push_back(s);
				}
				li.splice(itr, temp); //itr위치에 temp끼워넣기
			}
			else if (cType == 'D') {
				itr = li.begin();
				cin >> x >> y;//앞에서부터 x의 위치 바로 다음부터 y개 숫자 삭제
				for (int i = 0; i < x; i++)itr++;
				for (int i = 0; i < y; i++) itr = li.erase(itr); //erase는 itr을 return 한다
			}
			else if (cType == 'A') {
				cin >> y;//암호문 맨 뒤에 y개 숫자 덧붙인다.
				for (int i = 0; i < y; i++) {
					cin >> s;
					li.push_back(s);
				}
			}
		}

		itr = li.begin();
		printf("#%d ", tc);
		for (int i = 0; i < 10; i++) {
			printf("%d ", *(itr++));
		}
		printf("\n");

	}

	return 0;
}