/*�A���S���Y���ƍH�v�_(T-shirts/CPU: 1 ms  Memory: 3880 KB  Length: 810 B)
���������S����T�V���c�̐��ɑ΂��āA�����𖞂����s�����ł��邩��O(n)�ŕ�����B�]���āA�������S����T�V���c�̐���2���T�����A�ŏ���T�V���c�w���������߂��B�v�Z�ʂ�O(n*log2(n))<10^4 �ŏ\�������B
���񕪒T�����Ȃ��Ă��An�̍ő�l1000���A�w�����鐔��0�̏ꍇ���珇�ɒ��ׂĂ����AO(n^2)�ŋ��߂Ă��Ԃɍ����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 1000
using namespace std;

int n, m, s[MAX_N];

bool judge(int logo) {
	int i, mn = m, ln = logo;
	rep(i, n) {
		switch (s[i]) {
		case 0:
			mn = m;
			ln = logo;
			break;
		case 1:
			if (mn > 0)
				mn--;
			else if (ln > 0)
				ln--;
			else
				return false;
			break;
		default:
			if (ln > 0)
				ln--;
			else
				return false;
			break;
		}
		//printf("%d %d\n",mn,ln);
	}
	return true;
}

int main() {
	int left, right, mid, i;
	scanf("%d%d", &n, &m);
	rep(i, n)
		scanf("%1d", &s[i]);
	left = 0; right = n + 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (judge(mid))
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
	return 0;
}