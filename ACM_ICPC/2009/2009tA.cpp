/*�A���S���Y���ƍH�v�_(Luck Manipulator/CPU: 10 ms  Memory: 3412 KB  Length: 603 B)
����now�t���[���ڂɂ����闐���lx�Ƃ��āAnow��x�𓯎��ɍX�V���Ă����V�~�����[�V�����ŉ�����B�ň��v�Z�ʂ�O(n+max(now))��10^4 �ƂȂ�\�������B
�{�^����1�t���[���̊Ԃɕ����������Ƃ͂ł��Ȃ����Ƃɒ��ӁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 100
#define MAX_F 10000
using namespace std;

int n, a, b, c, x, y[MAX_N];

int main() {
	int i, now;
	while (1) {
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &x);
		if (!(n || a || b || c || x))
			break;
		now = 0;
		rep(i, n)
			scanf("%d", &y[i]);
		rep(i, n) {
			while (x != y[i] && now < MAX_F) {
				//printf("now:%d x:%d\n", now, x);
				now++;
				x = (a * x + b) % c;
			}
			if (x != y[i])
				break;
			now++;
			x = (a * x + b) % c;
		}
		if (i == n)
			printf("%d\n", now - 1);
		else
			puts("-1");
	}
	return 0;
}