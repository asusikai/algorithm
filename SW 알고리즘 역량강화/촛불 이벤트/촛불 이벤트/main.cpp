#include<stdio.h>
#include<math.h>
int ok(long long cmp, long long N) {
	if (((cmp * cmp) + cmp) == N)
		return 1;
	else if (((cmp * cmp) + cmp) > N)
		return -1;
	else return 0;
}
long long solve(long long N) {
	long long start = 1;
	long long end = sqrt(N);
	long long mid;
	long long value = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		int o = ok(mid, N);
		if (o == 1) return mid;
		if (o == -1) {
			end = mid - 1;
		}
		else if (o == 0) {
			start = mid + 1;
		}
	}
	return -1;
}
int main() {
	int tc; scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		long long N;
		scanf("%lld", &N);
		N *= 2;
		printf("#%d %lld\n", t, solve(N));
	}
	return 0;
}