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
		li.clear();//����Ʈ �ʱ�ȭ
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

				cin >> x >> y;//�տ������� x�� ��ġ �ٷ� ������ y�� ���� ����
				for (int i = 0; i < x; i++) itr++;
				for (int i = 0; i < y; i++) {
					cin >> s;
					temp.push_back(s);
				}
				li.splice(itr, temp); //itr��ġ�� temp�����ֱ�
			}
			else if (cType == 'D') {
				itr = li.begin();
				cin >> x >> y;//�տ������� x�� ��ġ �ٷ� �������� y�� ���� ����
				for (int i = 0; i < x; i++)itr++;
				for (int i = 0; i < y; i++) itr = li.erase(itr); //erase�� itr�� return �Ѵ�
			}
			else if (cType == 'A') {
				cin >> y;//��ȣ�� �� �ڿ� y�� ���� �����δ�.
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