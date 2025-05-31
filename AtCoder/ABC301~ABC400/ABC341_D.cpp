/*�A���S���Y���ƍH�v�_(Only one of two/CPU: 1 ms  Memory: 3888 KB  Length: 1064 B)
n<m�ł��鎞�Am*y<n*x<n*(x+1)<...<m*(y+1)�Ƃ����֌W�����K����������ӏ��������I�Ɍ����B1���炠��lX�܂ł̐����l�ŁAN��M�̓����傤�ǈ���݂̂Ŋ���؂�鐔z�� z=[X/N]+[X/M]-2*[X/lcm(N,M)] �ƕ\�����Ƃ��ł���B
X=m*y�̎��AX�ɑ΂���z�����傤��k�ȏ�ƂȂ�悤��y�̒l��񕪒T���ŋ��߂�Bz=k�ƂȂ�Am*y%n>0�ł���΁Am*y�������ƂȂ�B�����łȂ���΁Am*(y-1)<n*x<m*y�𖞂����͈͓��ɁAz=k�ƂȂ�x�̒l�͑��݂���B���͈͓̔��ŁA
z=k�ƂȂ�x�̒l��񕪒T������Ή�����B�]���čň��v�Z�ʂ�O(log2(K))�ƂȂ�\�������B
��������a,b�̍ŏ����{��lcm,�ő����gcm�Ƃ���ƁAa*b=lcm*gcm�𖞂������Ƃ��o���Ă������ƁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

long long n, m, k;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	long long left, mid, right, temp, lcm;
	scanf("%lld%lld%lld", &n, &m, &k);
	left = 1;
	right = 2 * k;
	lcm = n*m/gcd(n, m);
	if (n > m)
		swap(n, m);
	while (left < right) {
		mid = (left + right) / 2;
		if ((temp = m * mid / n + mid - 2 * (m * mid / lcm)) < k)
			left = mid + 1;
		else
			right = mid;
	}
	if ((m * left) % n > 0 && (temp = m * left / n + left - 2 * (m * left / lcm)) == k) {
		printf("%lld\n", m * left);
	}
	else {
		//printf("temp:%lld\n",temp);
		right = m * left / n + 1;
		left = m * (left - 1) / n;
		while (left < right) {
			//printf("left:%lld right:%lld\n", left, right);
			mid = (left + right) / 2;
			if ((temp = n * mid / m + mid - 2 * (n * mid / lcm)) < k)
				left = mid + 1;
			else
				right = mid;
		}
		printf("%lld\n", n * left);
	}
	//printf("temp:%lld\n", temp);
	return 0;
}