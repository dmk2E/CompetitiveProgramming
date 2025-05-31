/*�A���S���Y���ƍH�v�_(Divide and Divide/CPU: 1 ms  Memory: 3892 KB  Length: 564 B)
N��2�Ŋ��葱����1�ȉ��ɂȂ�̂ɂ́Alog2(N) �񂾂�2�Ŋ���΂悢�B���̂��߁A�������ċA�ŉ�����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

typedef unsigned long long ull;

ull n;
map<ull, ull> dp;

ull ans(ull x) {
	if (x <= 1)
		return 0;
	ull a, b, sum = x;
	if (x % 2 == 0)
		a = b = x / 2;
	else {
		a = x / 2;
		b = a + 1;
	}
	if (dp[a] > 0)
		sum += dp[a];
	else
		sum += (dp[a]=ans(a));
	if (dp[b] > 0)
		sum += dp[b];
	else
		sum += (dp[b] = ans(b));
	return sum;
}

int main() {
	scanf("%llu", &n);
	dp[0] = dp[1] = 0;
	dp[2] = 2;
	printf("%llu\n", ans(n));
	return 0;
}