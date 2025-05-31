/*�A���S���Y���ƍH�v�_(Leftover Recipes/CPU: 72 ms  Memory: 3936 KB  Length: 932 B)
����A��x���ƌŒ肵�����A����B��������邱�Ƃ��ł��邩�́A�����Ă���ޗ����Ȃ��Ȃ�܂ŗ���B�����΂悭�A���̎��̌�y�Ƃ���ƁA�S�̂Ƃ��č�邱�Ƃ��ł��闿���̐���x+y�ɂȂ�B����y�͓񕪒T���ŋ��߂�
���Ƃ��ł���B�]���āA�ň��v�Z�ʂ́AO(MAX_Q*(n+log2(MAX_Q)))<10^8 �ƂȂ荂���ɋ��߂邱�Ƃ��ł���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 10
#define MAX_Q 1000000
using namespace std;

int n, a[MAX_N], b[MAX_N], q[MAX_N];

bool judge(int x) {
	int i;
	rep(i, n) {
		if ((long long)q[i] < (long long)a[i] * x)
			return false;
	}
	return true;
}

int searchMax() {
	int left = 0, right = MAX_Q + 1, mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (judge(mid))
			left = mid + 1;
		else
			right = mid;
	}
	return left - 1;
}

int main() {
	int i, j, max = -1, temp;
	scanf("%d",&n);
	rep(i, n)
		scanf("%d",&q[i]);
	rep(i, n)
		scanf("%d", &a[i]);
	rep(i, n)
		scanf("%d", &b[i]);
	j = 0;
	while(1) {
		if ((temp = searchMax() + j) > max)
			max = temp;
		//printf("j:%d,temp:%d\n", j, temp);
		rep(i, n) {
			q[i] -= b[i];
			if (q[i] < 0)
				break;
		}
		if (i < n)
			break;
		j++;
	}
	printf("%d\n", max);
	return 0;
}