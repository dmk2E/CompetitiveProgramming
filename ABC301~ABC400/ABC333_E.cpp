/*�A���S���Y���ƍH�v�_(Takahashi Quest/CPU: 97 ms  Memory: 16412 KB  Length: 1127 B)
����������Ԃ��Z�������|�[�V�����̏������̍ő�l���������ł��邩��A�|�[�V�������g�p���Ȃ���΂Ȃ�Ȃ��^�C�~���O�ȑO�ł��ł��߂��~�����|�[�V�������擾���Ă����΂悢�B�����×~�@�ɂ��A���S���Y
���́A�v�Z��O(n)�ōςނ��߁A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 200000
#define USE -1
#define GET 1
#define NOTHING 0
using namespace std;

typedef struct p {
	int t, x;
}P;

int n, t, x, state[MAX_N] = { 0 };
P use[MAX_N];
map<int, int> p;//���̎��_�ŕK�v�ȃ|�[�V������(��ށA��)
queue<int> que;

int main() {
	int i, min, cnt;
	scanf("%d",&n);
	rep(i, n) {
		scanf("%d%d", &use[i].t, &use[i].x);
		if(use[i].t==1)
			que.push(i);
	}
	rep(i, n) {
		if (use[n-1-i].t == 2) {
			p[use[n-1-i].x]++;
			state[n-1-i] = USE;
		}
		else if (p[use[n-1-i].x] > 0) {
			p[use[n - 1 - i].x]--;
			state[n - 1 - i] = GET;
		}
		else
			state[n - 1 - i] = NOTHING;
	}
	for (pair<int, int> j : p) {
		if (j.second > 0) {
			puts("-1");
			return 0;
		}
	}
	min = cnt = 0;
	rep(i, n) {
		if (state[i] == GET)
			cnt++;
		else if (state[i] == USE)
			cnt--;
		if (min < cnt)
			min = cnt;
	}
	printf("%d\n",min);
	while (que.size() - 1 > 0) {
		printf("%d ", state[que.front()]); que.pop();
	}
	printf("%d\n", state[que.front()]); que.pop();
	return 0;
}