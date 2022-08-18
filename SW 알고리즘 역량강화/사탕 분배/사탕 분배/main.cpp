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
#include<climits>

using namespace std;

unsigned long long fpow(unsigned long long N, unsigned long long _sum) {
	if (N == 0) {
		return 1;
	}

	else {
		unsigned long long x = fpow(N / 2, _sum);
		if (N % 2 == 0) {
			if (x >= INT_MAX / x) {
				x = x % _sum;
			}
			return (x * x)%_sum;
		}

		else {
			if (x >= INT_MAX / x) {
				x = x % _sum;
			}
			return (x * x * (2%_sum))%_sum;
		}
	}
}

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
	unsigned long long A, B;
	unsigned long long K;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> A >> B >> K;

		unsigned long long _sum = A + B;
		unsigned long long check;
		int cnt = 0;
		/*
		if (A == B) {
			cout << "#" << test_case << " 0" << "\n";
		}

		else {
			if (A > B) {
				check = _sum / B;
				if ((_sum % B == 0) && (check & (check - 1)) == 0) {
					while (check > 1) {
						check >> 1;
						cnt++;
					}
				}

				if (cnt - 1 <= K) {
					cout << "#" << test_case << " 0" << "\n";
				}

			}

			else {
				check = _sum / A;
				if ((_sum % A == 0) && (check & (check - 1)) == 0) {
					while (check > 1) {
						check >> 1;
						cnt++;
					}
				}

				if (cnt - 1 <= K) {
					cout << "#" << test_case << " 0" << "\n";
				}
			}
		}
		*/

		unsigned long long result1 = (A%_sum * (fpow(K, _sum) % _sum)) % _sum;
		unsigned long long result2 = (B%_sum * (fpow(K, _sum) % _sum)) % _sum;

		cout << "#" << test_case << " " << min(result1, result2) << "\n";

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}