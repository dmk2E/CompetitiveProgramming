/*�A���S���Y���ƍH�v�_(���j�y�j�f����/CPU: 30 ms  Memory: 3732 KB  Length: 960 B)
��Ɍ��j�y�j�f����񋓂��Ă����A���̌�^�����錎�j�y�j���̖񐔂�S�񋓂��A���̖񐔂����j�y�j�f���ł�����̂������ŕێ����ďo�͂���B
����x�ɂ��āAx=a*b(a<=b)�𖞂���2�̐����̑g(a,b)���l�������A0<=a<=��x,��x<=b<=x �𖞂����B�]���āAx�̖񐔂�S�񋓂���̂́A0<=a<=��x �͈̔͂̐�����x������A����؂ꂽ�ꍇ��(a,b)=(a,x/a)�Ƃ��ċL�^����΂悢�B
�]���āA�񐔂̑S�񋓂�O(��x) �𖞂����B
300000�܂ł̐����ŁA���j�y�j�f���ł��邩�𔻒肷��z��MDP�́A���������������ɍ쐬���Ă����B�܂��A7*n+1,7*n+6�����������Ɍ��Ă����A���̖񐔂�S�񋓂��āA���̖񐔂Ɍ��j�y�j�f�����܂܂�Ă��Ȃ����Łutrue�v���ufalse�v������
���Ă����B���̔z��쐬�̍ň��v�Z�ʂ́AO(n��n)=10^(7.5)<10^8�B��x�쐬������A����ȍ~�z��쐬�̌v�Z�ʂ͔������Ȃ����߁A�X�̓��͒l�̔���̍ň��v�Z�ʂ́AO(��n)��10^(2.5)�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 300000
using namespace std;

int n;
set<int> ans;
bool MDP[MAX_N + 1];

bool isMDP(int x) {
	int i, max = sqrt(x);
	for (i = 2; i <= max; i++) {
		if (x % i == 0 && (MDP[i] || MDP[x / i]))
			return false;
	}
	return true;
}

void initMDP() {
	int i, j;
	MDP[6] = true;
	for (i = 1; 7 * i + 1 <= MAX_N; i++) {
		if (isMDP(7 * i + 1))
			MDP[7 * i + 1]=true;
		if (isMDP(7 * i + 6))
			MDP[7 * i + 6]=true;
	}
}

int main() {
	int i, max;
	set<int>::iterator it;
	initMDP();
	while (1) {
		scanf("%d",&n);
		if (n == 1)
			break;
		printf("%d:",n);
		if (MDP[n])
			printf(" %d\n", n);
		else {
			max = sqrt(n);
			for (i = 2; i <= max; i++)
				if (n % i == 0) {
					if (MDP[i])
						ans.insert(i);
					if (MDP[n / i])
						ans.insert(n / i);
				}
			for (it = ans.begin(); it != ans.end(); it++) {
				printf(" %d", *it);
			}
			puts("");
		}
		ans.clear();
	}
	return 0;
}