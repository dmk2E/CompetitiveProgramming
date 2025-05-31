/*�A���S���Y���ƍH�v�_(Island Tour/CPU: 22 ms  Memory: 5352 KB  Length: 789 B)
��i����������̍ŒZ����min�ƂȂ鎞�Asum[i]=min �ƂȂ�悤�Ȕz��sum���쐬����Bimos�@�𗘗p���邱�ƂŁA�ň��v�Z�ʂ�O(n+m)�ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 200000
#define MAX_M 200000
using namespace std;

int n, m;
long long sum[MAX_N + 1] = { 0 };

int main() {
	int i, s, e, j;
	scanf("%d%d", &n, &m);
	scanf("%d", &s);
	s--;
	rep(i, m - 1) {
		scanf("%d", &e);
		e--;
		if (s < e) {
			sum[s] += s + n - e;
			sum[e] += -(s + n - e);
			sum[e] += e - s;
			sum[n] += -(e - s);
			sum[0] += e - s;
			sum[s] += -(e - s);
		}
		else {
			sum[e] += n - s + e;
			sum[s] += -(n - s + e);
			sum[s] += s - e;
			sum[n] += -(s - e);
			sum[0] += s - e;
			sum[e] += -(s - e);
		}
		s = e;
	}
	rep(i, n)
		sum[i + 1] += sum[i];
	s = 0;
	rep(i, n) {
		if (sum[s] > sum[i])
			s = i;
	}
	printf("%lld\n", sum[s]);
	return 0;
}