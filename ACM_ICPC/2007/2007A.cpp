/*�A���S���Y���ƍH�v�_(ICPC ���_�W�v�\�t�g�E�F�A/CPU: 0 ms  Memory: 3452 KB  Length: 420 B)
���`�I�Ɋe�_�����Z���Ă�����Ƃ̂��łɍő�_���ƍŏ��_�������߁A�����𖞂������ϒl�����߂�悤�ɂ���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define  MAX_S 1000
using namespace std;

int n, s;

int main() {
	int i, sum, max, min;
	while (1) {
		scanf("%d",&n);
		if (!n)
			break;
		sum = 0; max = -1; min = MAX_S + 1;
		rep(i, n) {
			scanf("%d",&s);
			sum += s;
			if (max < s)
				max = s;
			if (min > s)
				min = s;
		}
		sum -= max + min;
		sum /= (n - 2);
		printf("%d\n", sum);
	}
	return 0;
}