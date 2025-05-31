/*�A���S���Y���ƍH�v�_(Maximum Average Sets/CPU: 1 ms  Memory: 3928 KB  Length: 1303 B)
n�̒�����j�̕i����I�񂾎��́A���l�̍ő�l�́A�udp[i][j]:1�`i+1�Ԗڂ̕i���̒�����j�i����I�񂾎��́A���l�̑��a�̍ő�l�v�Ƃ������I�v��@�ŉ�����B�]���āA�I�񂾕i���̉��l�̕��ς̍ő�l�́A
max(dp[n-1][j]/j(a<=j<=b))�ƂȂ�B
���ɁA���̍ő�l�����i���̑I�ѕ��́Adp�̊e�l�Ƌ��ɁA�z��cnt�ɖ��߂Ă���(cnt[i][j]:���l�̑��a��dp[i][j]�ƂȂ鎞�́A�I�ѕ��̑���)�Bdp[i-1][j-1]+v!=dp[i-1][j] �̂Ƃ��Adp[i][j]=max(dp[i-1][j-1]+v,dp[i-1][j])�ƂȂ邩��A
cnt[i][j]=max(cnt[i-1][j-1],dp[i-1][j])�Bdp[i-1][j-1]+v=dp[i-1][j] �̎��Adp[i][j]�̒l�́A���̓�ʂ�̕��@�ō���邩��Acnt[i][j]=cnt[i-1][j-1]+cnt[i-1][j] �ƂȂ�B
�ň��v�Z��O(n^2)<10^4 ���A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 50
#define EPS (1e-10)
using namespace std;

int n, a, b;
long long dp[MAX_N][MAX_N + 1] = { 0 }, cnt[MAX_N][MAX_N + 1] = { 0 };

long double fAbs(long double a) {
	return a <EPS ? -a : a;
}

void showDP() {
	int i, j;
	puts("dp");
	rep(i, n) {
		rep(j, n+1)
			printf("%lld ", dp[i][j]);
		puts("");
	}
	puts("cnt");
	rep(i, n) {
		rep(j, n + 1)
			printf("%lld ", cnt[i][j]);
		puts("");
	}
}

int main() {
	int i, j;
	long long count = 0, v;
	long double max = -1.0, tmp;   //double�^���ƁA�덷�H��1����WA�ɂȂ�B
	scanf("%d%d%d",&n,&a,&b);
	scanf("%lld",&v);
	dp[0][1] = v;
	cnt[0][0] = cnt[0][1] = 1;
	rep(i, n-1) {
		scanf("%lld",&v);
		rep(j, n + 1) {
			dp[i + 1][j] = dp[i][j];
			cnt[i + 1][j] = cnt[i][j];
			if (j - 1 >= 0){
				if (dp[i + 1][j] < dp[i + 1][j - 1] + v) {
					dp[i + 1][j] = dp[i][j - 1] + v;
					cnt[i + 1][j] = cnt[i][j - 1];
				}
				else if(dp[i + 1][j] == dp[i][j - 1] + v){
					cnt[i + 1][j] += cnt[i][j-1];
				}
			}
		}
	}
	//showDP();
	for (j = a;j<=b;j++){
		if ((tmp = (long double)dp[i][j] / (long double)j) > max) {
			max = tmp;
			count = cnt[i][j];
		}
		else if (fAbs(tmp - max)<EPS)   //���������_���^�̒l�̓������Z�́A�����ȒlEPS��p���čs���B
			count += cnt[i][j];
	}
	printf("%.7Lf\n%lld\n",max,count);
	return 0;
}