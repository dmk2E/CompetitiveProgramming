/*�A���S���Y���ƍH�v�_(Widespread/CPU: 19 ms  Memory: 4204 KB  Length: 849 B)
�G�S�����̑�HP��0�ɂ��Ȃ��ƁA�S�Ă̖������������邱�Ƃ͂ł��Ȃ�->1��̔����łł��邾���G�̑�HP����肽��->���̎��ɍł�HP�������G�𒆐S�ɔ���������΂悢�B�܂�A�×~�@�ŉ�����B
�������×~�@���ƃV�~�����[�V�����I��@�ƂȂ�A�v�Z�ʂ��c��ƂȂ��Ă��܂��B�����ŁAT�ɂ͒P���������邱�Ƃ𗘗p�����񕪒T���ŉ����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_H 100000
#define MAX_B 1000000000
using namespace std;

int n, a, b, h[MAX_H];

bool judge(long long t) {
	int i;
	long long cnt = 0;
	rep(i, n) {
		if (h[i] - (long long)b * t > 0) {
			//printf("%lld\n", ((long long)h[i] - (long long)b * t) / (a - b));
			cnt += (h[i] - (long long)b * t) / (a - b);
			if ((h[i] - (long long)b * t) % (a - b) > 0)
				cnt++;
		}
	}
	return cnt <= t;
}

int main() {
	int i, left = 1, right = MAX_B + 1, mid;
	scanf("%d%d%d", &n, &a, &b);
	rep(i, n)
		scanf("%d", &h[i]);
	while (left < right) {
		mid = (left + right) / 2;
		//printf("mid:%d\n", mid);
		if (judge(mid))
			right = mid;
		else
			left = mid + 1;
		//printf("left:%d right:%d\n", left, right);
	}
	printf("%d\n", left);
	return 0;
}