/*�A���S���Y���ƍH�v�_(Amida, the City of Miracle/CPU: 0 ms  Memory: 3780 KB  Length: 561 B)
amida[i][j]:����i��j�Ԗڂ̐����A���Ԗڂ̐��ƌq�����Ă��邩���i�[����B
��L�Œ�`����amida�𗘗p���āA���݂̂��݂�������̍���now���A���̍ő�̍�������0�ɂȂ�܂ŁA���ꂼ��̍����ŉ���������Όq�����Ă���c���Ɉڂ�Ƃ���������J��Ԃ��V�~�����[�V�����ŉ����B
�v�Z�ʂ�O(max(���݂������̍���))=10^3 �ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 100
#define MAX_H 1000
using namespace std;

int n, m, a, amida[MAX_H + 1][MAX_N + 1];

int main() {
	int i, j, k, now=0;
	while (1) {
		scanf("%d%d%d",&n,&m,&a);
		if (!(n || m || a))
			break;
		rep(i, MAX_H + 1)
			rep(j, n + 1)
				amida[i][j] = 0;
		while (m--) {
			scanf("%d%d%d",&i,&j,&k);
			amida[i][j] = k;
			amida[i][k] = j;
			if (now < i)
				now = i;
		}
		while (now > 0) {
			if (amida[now][a] > 0)
				a = amida[now][a];
			now--;
		}
		printf("%d\n",a);
	}
	return 0;
}