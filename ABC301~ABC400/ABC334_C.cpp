/*�A���S���Y���ƍH�v�_(Socks 2/CPU: 13 ms  Memory: 4660 KB  Length: 508 B)
�×~�@�̐������̊m�F��A�v�Z�ʍ팸�̍H�v�͎��ۂɎ�𓮂����A�l�X�ȃp�^�[���ɂ��Ď������s�����Ƃ��d�v�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 200000
using namespace std;

int n, k,a[MAX_N];

int main() {
	int i, sum = 0, min;
	scanf("%d%d",&n,&k);
	scanf("%d",&a[0]);
	rep(i, k-1) {
		scanf("%d", &a[i + 1]);
		if((i+1)%2==1)
			sum += a[i + 1]-a[i];
	}
	min = sum;
	if (k % 2 == 1){
		for (i = k-3; i >= 0; i -= 2) {
			sum -= a[i + 1] - a[i];
			sum += a[i + 2] - a[i + 1];
			if (min > sum)
				min = sum;
		}
	}
	printf("%d\n", min);
	return 0;
}