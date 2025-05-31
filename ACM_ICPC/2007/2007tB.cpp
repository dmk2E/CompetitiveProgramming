/*�A���S���Y���ƍH�v�_(���/CPU: 30 ms  Memory: 3896 KB  Length: 735 B)
������d�ƒ�����a�͋��� 00:00:00 ����̌o�ߕb���ɕϊ����Ĉ����B���� [d,a) �̊Ԃɗ�Ԃ�1��K�v�ɂȂ邩��A00:00:00����23:59:59 �̊ԂŕK�v�ȗ�Ԃ̐��̍ő�l�����߂�΂悢�B
�ꎟ���z��train��p���āAimos�@�ɂ��S���ԑтɒu�����Ԃ̐������߂邱�Ƃ��ł��邩��A�ň��v�Z�ʂ� O(n+MAX_TIME)<10^5 �ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_TIME 86400   //24*60*60
using namespace std;

int n, train[MAX_TIME];   //train[i]:i<=t<i+1 �𖞂���t�b�ԂɎg���Ă����Ԃ̐���\���B

int toSecond(string s) {
	int h=(s[0]-(int)'0')*10+s[1]-(int)'0', m= (s[3] - (int)'0') * 10 + s[4] - (int)'0', ss= (s[6] - (int)'0') * 10 + s[7] - (int)'0';
	return h * 60 * 60 + m * 60 + ss;
}

int main() {
	int i, j;
	string str;
	while (1) {
		scanf("%d",&n);
		if (!n)
			break;
		rep(i, MAX_TIME)
			train[i] = 0;
		while (n--) {
			cin >> str;
			i = toSecond(str);
			cin >> str;
			j = toSecond(str);
			train[i]++;
			train[j]--;
		}
		j = 0;
		rep(i, MAX_TIME - 1) {
			train[i + 1] += train[i];
			if (train[i + 1] > train[j])
				j = i + 1;
		}
		printf("%d\n", train[j]);
	}
	return 0;
}