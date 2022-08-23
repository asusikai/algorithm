#include <stdio.h>

#define MAX_NODE 1500000

int study_cnt;
int hacking_cnt;
int dp[MAX_NODE] = { 0 };
int Binary_study[MAX_NODE] = { 0 };

void reset()
{
	for (int i = 0; i < MAX_NODE; i++)
	{
		dp[i] = 0;
		Binary_study[i] = 0;
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

int check_study(int mid)
{
	for (int i = Binary_study[0]; i <= Binary_study[study_cnt - 1]; i++)
	{
		if (term(i, i + mid) > mid - hacking_cnt || mid <= hacking_cnt) return 1;
	}
	return -1;
}

int Binary_search(int min, int max)
{
	int start = min;
	int end = max;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (check_study(mid) == 1) start = mid + 1;
		if (check_study(mid) == -1) end = mid - 1;
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
		Binary_dp_get();
		printf("#%d %d\n", test_case, Binary_search(0, study_cnt + hacking_cnt));
		reset();
	}
}