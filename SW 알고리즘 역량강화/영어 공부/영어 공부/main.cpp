#include <stdio.h>

#define MAX_NODE 1500000

int study_cnt;
int hacking_cnt;
int dp[MAX_NODE] = { 0 };
int Binary_study[MAX_NODE] = { 0 };

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
}

void Binary_dp_get()
{
	int Binary_max = Binary_study[study_cnt - 1] + study_cnt + hacking_cnt;
	for (int i = 1; i <= Binary_max; i++)
	{
		if (dp[i] == 1)
		{
			dp[i] = dp[i - 1] + 1;
			continue;
		}
		dp[i] = dp[i - 1];
	}
}

int term(int start, int end)
{
	return dp[end] - dp[start - 1];
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
	return start;
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d", &study_cnt, &hacking_cnt);
		for (int i = 0; i < study_cnt; i++)
		{
			scanf("%d", &Binary_study[i]);
			dp[Binary_study[i]] = 1;
		}

		first_date = study_date[0] > p ? study_date[0] - p : 0;
		last_date = study_date[N - 1] + p;
		fill_study_count();
		find_max_date(first_date, last_date);

		cout << "#" << test_case << " " << max_val << endl;
	}
} 