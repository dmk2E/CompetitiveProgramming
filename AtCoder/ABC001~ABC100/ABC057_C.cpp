/*�A���S���Y���ƍH�v�_(Digits in Multiplication/CPU:  ms  Memory:  KB  Length:  B)

*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

int f(long long a, long long b) {//�v�Z�ʂ�O(log10(max(a,b)))�ŁA�ő��10��B�񕪒T���ō��������ł��邪�A�ő�10��Ȃ̂ŏ������Ԃɂ͂��܂�e�����Ȃ��B
	int cnt=0;
	while (a > 0 || b > 0) {
		a /= 10;
		b /= 10;
		cnt++;
	}
	return cnt;
}

long long n;

int main() {//�S�̂̌v�Z�ʂ�O(��n*10)��10^6 �ƂȂ�\�������B
	int i, max, min, tmp;
	scanf("%lld",&n);
	for (i = 1, max = (int)sqrt(n),min=11; i <= max; i++) {   //��̖񐔂̑Ώ̐����A��n�܂Ő��`�T������΂悢�B
		if (n % (long long)i == 0) {
			if ((tmp = f(i, n / (long long)i)) < min)
				min = tmp;
			//printf("%d %lld��%d\n", i, n / i, tmp);
		}
	}
	printf("%d\n",min);
	return 0;
}