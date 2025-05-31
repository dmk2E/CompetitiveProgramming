/*�A���S���Y���ƍH�v�_(���P�l�̉œ���/CPU: 0 ms  Memory: 3564 KB  Length: 634 B)
���Ғl���傫������D��I�Ɍ�q���Ă��炤�A�×~�@�ŉ�����B�ň��v�Z�ʂ�O(n*log2(n))�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 10000
using namespace std;

typedef struct data {
	int d, p;

	bool operator<(const data& k) {
		return p < k.p;
	}
}Data;

int n, m;
Data d[MAX_N];

int main() {
	int i, sum;
	while (1) {
		scanf("%d%d", &n, &m);
		if (!(n || m))
			break;
		sum = 0;
		rep(i, n) {
			scanf("%d%d", &d[i].d, &d[i].p);
			sum += d[i].d*d[i].p;
		}
		sort(d, d + n);
		for (i = n - 1; m >= 0 && i >= 0; i--) {
			if (m >= d[i].d) {
				m -= d[i].d;
				sum -= d[i].d * d[i].p;
			}
			else {
				sum -= d[i].p * m;
				break;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}