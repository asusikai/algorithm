/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		priority_queue<int, vector<int>, less<int>> low_que;
		priority_queue<int, vector<int>, greater<int>> high_que;

		int N, first_num;

		int mid_num;

		int _sum = 0;

		cin >> N >> first_num;

		mid_num = first_num;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;

			if (a >= mid_num) {
				high_que.push(a);
			}

			else {
				low_que.push(a);
			}

			if (b >= mid_num) {
				high_que.push(b);
			}

			else {
				low_que.push(b);
			}

			if (high_que.size() == low_que.size()) {

				_sum = (_sum + mid_num) % 20171109;
			}

			else if (high_que.size() > low_que.size()) {
				int temp;
				while (high_que.size() != low_que.size()) {
					temp = high_que.top();
					low_que.push(mid_num);
					high_que.pop();
					mid_num = temp;
				}

				_sum =(_sum + mid_num) % 20171109;
			}

			else if (high_que.size() < low_que.size()) {
				int temp;
				while (high_que.size() != low_que.size()) {
					temp = low_que.top();
					high_que.push(mid_num);
					low_que.pop();
					mid_num = temp;
				}

				_sum = (_sum + mid_num) % 20171109;
			}
		}

		cout << "#" << test_case << " " << _sum << endl;

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}