/*�A���S���Y���ƍH�v�_(Minimize Abs 2/CPU: 67 ms  Memory: 3812 KB  Length: 1040 B)
��Βl�̒l�ɂȂ��Ă��邩��Ax,y�̎�肤��l��0�`��D�ƂȂ�B�]���āA��D�𒴂��鐮���lmax_x���܂��񕪒T���ŋ��߂�B�v�Z�ʂ�O(log2(D))�B
���̌�A0�`max_x�͈̔͂�x�̒l���Œ肵�A|x^2+y^2-D|�̒l�����͈̔͂ōŏ��ƂȂ�悤��y�̒ly_max��񕪒T���ŋ��߂�Bx�̒l���Œ肵�����Ay=y_max�̎��A�܂���y=y_max-1�̎���|x^2+y^2-D|�̒l�͍ŏ��ƂȂ�B����𗘗p����
�A���߂�ŏ��l�����肷��B�v�Z�ʂ�O(��Dlog2(��D))��10^7�ƂȂ�A�����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_MIN 10000000
#define MAX_D 2000000000000
using namespace std;

long long d;

int main() {
	int min, i, left, right, mid, j;
	long long tmp, ans = MAX_D + 1, temp;
	cin >> d;
	left = 0;
	right = MAX_MIN;
	while (left < right) {
		mid = (left + right) / 2;
		if ((long long)mid * mid < (long long)d)
			left = mid + 1;
		else
			right = mid;
	}
	min = left;
	rep(i, min + 1) {
		tmp = (long long)i * i - d;
		left = 0; right = min + 1;
		while (left < right) {
			mid = (left + right) / 2;
			if (tmp + (long long)mid * mid < 0)
				left = mid + 1;
			else
				right = mid;
		}
		temp = tmp + (long long)left * left;
		left--;
		if (temp > abs(tmp + (long long)left * left))
			temp = abs(tmp + (long long)left * left);
		if (ans > temp)
			ans = temp;
	}
	printf("%lld\n", ans);
	return 0;
}