/*�A���S���Y���ƍH�v�_(Colorful Leaderboard/CPU:  ms  Memory:  KB  Length:  B)
�F��8��ނƂ͌���Ȃ����Ƃɒ��ӁB
*3200�ȏ��counter[MAX_C]�ɓ����悤�ɏo���ĂȂ������B�P����counter[a/400]�ł͏�肭�����Ȃ����ƂɋC�Â��Ȃ������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_C 8
using namespace std;

int n, a, counter[MAX_C + 1] = { 0 }, zero2Seven = 0;

int main() {
	int i;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a);
		if (counter[a / 400 < MAX_C ? a / 400 : MAX_C] == 0 && a / 400 < MAX_C)
			zero2Seven++;
		counter[a / 400 < MAX_C ? a / 400 : MAX_C]++;
	}
	if (zero2Seven == 0) {
		printf("%d %d\n", 1, counter[MAX_C]);
	}
	else {
		printf("%d %d\n", zero2Seven, zero2Seven + counter[MAX_C]);
	}
	return 0;
}