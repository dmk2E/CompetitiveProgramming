/*�A���S���Y���ƍH�v�_(��������/CPU: 50 ms  Memory: 3408 KB  Length: 627 B)
���[���ɏ]���ăV�~�����[�V�������邾���B�v�Z�ʂ�O((�ő�X�e�b�v��)) �ƂȂ�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 50
using namespace std;

int n, p, stone[MAX_N];

int main() {
	int i, now, cnt;   //now:�q�������Ă���l�̔ԍ� cnt:1���ȏ㏬�΂������Ă���l�̐�
	while (1) {
		scanf("%d%d", &n, &p);
		if (!(n || p))
			break;
		cnt = now = 0;
		rep(i, n)
			stone[i] = 0;
		while (1) {
			if (p == 0) {
				p += stone[now];
				if (stone[now] > 0)
					cnt--;
				stone[now] = 0;
			}
			else {
				if (stone[now] == 0)
					cnt++;
				stone[now]++;
				p--;
				if (p == 0 && cnt == 1)
					break;
			}
			//printf("Now:%d(%d) cnt:%d\n", now, stone[now], cnt);
			now = (now + 1) % n;
		}
		printf("%d\n", now);
	}
	return 0;
}