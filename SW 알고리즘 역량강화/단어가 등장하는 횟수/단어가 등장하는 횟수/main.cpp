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
#define HASH_VALUE1 11
#define HASH_VALUE2 23

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int pow(int x, int n) {
	for (int i = 1; i < n; i++) {
		x *= x;
	}

	return x;
}

int find_match(string t, string p) {

	int t_size = t.size();
	int p_size = p.size();

	int Count = 0;

	int t_val1 = 0;
	int p_val1 = 0;
	int t_val2 = 0;
	int p_val2 = 0;

	for (int i = 0; i < p_size; i++) {

		t_val1 = t_val1 * HASH_VALUE1 + int(t[i]);
		p_val1 = p_val1 * HASH_VALUE1 + int(p[i]);

		t_val2 = t_val2 * HASH_VALUE2 + int(t[i]);
		p_val2 = p_val2 * HASH_VALUE2 + int(p[i]);
	}

	if (t_val1 == p_val1 && t_val2 == p_val2) {
		Count++;
	}

	for (int i = p_size; i < t_size; i++) {
		
		t_val1 = (t_val1 - int(t[i-p_size]) * pow(HASH_VALUE1, p_size - 1)) * HASH_VALUE1 + int(t[i]);
		t_val2 = (t_val2 - int(t[i-p_size]) * pow(HASH_VALUE2, p_size - 1)) * HASH_VALUE2 + int(t[i]);

		if (t_val1 == p_val1 && t_val2 == p_val2) {

			Count++;
		}
	}
	return Count;
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
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string text, pattern;

		cin >> text >> pattern;

		int result = find_match(text, pattern);

		//cout << "#" << test_case << " " << result << endl;
		printf("#%d %d\n", test_case, result);

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}