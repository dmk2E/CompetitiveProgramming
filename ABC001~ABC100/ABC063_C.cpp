/*�A���S���Y���ƍH�v�_(Bugged/CPU: 13 ms  Memory: 4096 KB  Length: 536 B)
i��ڂ܂łŁA���_������_���̏W��dp[i]�Ƃ���ƁAdp[i]=(dp[i-1]�̑S�Ă̐����l)+Si�ƂȂ�B�܂��ő哾�_��10000�ł��邱�Ƃ���Adp[i].size<=10^4 �ƂȂ邩��A�ň��v�Z�ʂ�O(n*max(dp[i].size))<=10^6 �ƂȂ邩��A
�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 100
using namespace std;

int n, s;

int main() {
	int i, max = 0;
	set<int> v;
	stack<int> sta;
	scanf("%d", &n);
	v.insert(0);
	rep(i, n) {
		scanf("%d", &s);
		for (int x : v) {
			if ((x + s) % 10 > 0 && x + s > max)
				max = x + s;
			sta.push(x + s);
		}
		while (sta.size()) {
			v.insert(sta.top()); sta.pop();
		}
		//printf("max:%d\n", max);
		//printf("size:%d\n", v.size());
	}
	printf("%d\n", max);
	return 0;
}