/*�A���S���Y���ƍH�v�_(Sum of Consecutive Integers/CPU: 0 ms  Memory: 3308 KB  Length: 588 B)
���̐���a�`b(0<a<b)�̑��aS�����߂������p���āA�a��n�ƂȂ�悤�ȘA������2�ȏ�̐��̐����̑g�ݍ��킹��S�T�����ĉ������߂�B�܂���[��a�̒l�͈̔͂�1�`n-1 ��n-1�ʂ�ł���Aa�̒l���Œ肷���b�̒l�ɑ΂���S��
�l�͒P������������Aa�ɑ΂���S=n�ƂȂ�b�̒l�� a<b<n �͈̔͂œ񕪒T�����邱�Ƃɂ�苁�߂邱�Ƃ��ł���B�]���čň��v�Z�ʂ�O(n*log2(n))��10^4�ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

int n;

int sumA2B(int a,int b) {//a�`b�܂ł̑��a��Ԃ��B
	return b * (b + 1) / 2 - a * (a - 1) / 2;
}

int main() {
	int i, left, right, mid, cnt;
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		cnt = 0;
		rep(i, n - 1) {
			left = i + 2;
			right = n;
			while (left < right) {
				mid = (left + right) / 2;
				if (sumA2B(i + 1, mid) == n)
					break;
				else if (sumA2B(i + 1, mid) < n)
					left = mid + 1;
				else
					right = mid;
			}
			if (left < right)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}