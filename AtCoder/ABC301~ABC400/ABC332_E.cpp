/*�A���S���Y���ƍH�v�_(Lucky bag/CPU: 830 ms  Memory: 12616 KB  Length: 845 B)
20!�ȏ�̌v�Z�ʂɂȂ邱�Ƃ���A���I�v��@���^���ׂ��������B���������_���܂ތv�Z�ł̌덷�������闝�R��������ꂸ�AAC�܂Ŏ��Ԃ����������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 15
#define MAX_D 15
#define INF 8e18
using namespace std;

int n, d;
long double a[MAX_N + 1], sum[1 << MAX_N], dp[1 << MAX_N][MAX_D + 1];

int main() {
	int i, j, k;
	double ave;
	scanf("%d%d", &n, &d);
	rep(i, n)
		scanf("%Lf", &a[i]);
	rep(i, 1 << n) {
		sum[i] = 0;
		rep(j, n)
			if (i & (1 << j))
				sum[i] += a[j];
	}
	ave = sum[(1 << n) - 1] / (long double)d;
	rep(i, 1 << n) {
		dp[i][1] = pow(sum[i] - ave, 2.0);
		for (j = 2; j <= d; j++) {
			dp[i][j] = dp[i][j - 1] + dp[0][1];
			k = i;
			while (k > 0) {
				dp[i][j] = min(dp[i - k][j - 1] + dp[k][1], dp[i][j]);
				k = (k - 1) & i;
			}
			//printf("%.3llf ",dp[i][j]/(long double)d);
		}
		//puts("");
	}
	printf("%.7Lf\n", dp[(1 << n) - 1][d] / ((long double)d));
	return 0;
}