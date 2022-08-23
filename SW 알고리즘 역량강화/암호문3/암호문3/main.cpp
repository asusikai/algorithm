#include<iostream>
#include<list>

using namespace std;

list<int> code;

int N, M;
int x, y, s;
char order;

list<int>::iterator iter;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		code.clear();

		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> s;
			code.push_back(s);
		}

		cin >> M;

		for (int i = 0; i < M;i++) {
			cin >> order;
			if (order == 'I') {
				cin >> x >> y;

				iter = code.begin();

				for (int j = 0; j < x; j++) {
					iter++;
				}

				list<int> temp;

				for (int j = 0; j < y; j++) {
					cin >> s;
					temp.push_back(s);
				}

				code.insert(iter, temp.begin(), temp.end());
			}

			else if (order == 'D') {
				cin >> x >> y;
				iter = code.begin();

				for (int j = 0; j < x; j++) {
					iter++;
				}

				for (int j = 0; j < y; j++) {
					iter = code.erase(iter);
				}
			}

			else if (order == 'A') {
				cin >> y;
				iter = code.end();
				iter--;
				list<int> temp;
				for (int j = 0; j < y; j++) {
					cin >> s;
					temp.push_back(s);
				}
				code.insert(iter, temp.begin(), temp.end());
			}
		}

		iter = code.begin();
		cout << "#" << test_case << " ";
		for (int i = 0; i < 10; i++) {
			cout << *(iter++) << " ";
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}