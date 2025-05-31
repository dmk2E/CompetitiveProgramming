/*�A���S���Y���ƍH�v�_(���������v�_/CPU: 0 ms  Memory: 3456 KB  Length: 793 B)
���Y�ƉԎq�����J�[�h�̖��������̓_�����ɕێ�����z��taro��hanako��p�ӂ���B���̍쐬��O(n+m)�ŉ\�B�J�[�h�����ւ��Ă����v�_�������Ƃ������Ƃ́A�����O�̑��Y�ƉԎq�����J�[�h�̍��v�_�����ꂼ��sumT,sumH�Ƃ��A��������
�J�[�h�̐������ꂼ��i,j�Ƃ���ƁAsumT-i+j=sumH+i-j ��2*j=sumH-sumT+2*i �ƂȂ邩��Ai����܂�΁Aj����ӂɒ�܂邽�߁A�����j�����݂��邩�Ai�ɂ��Ē��ׂ�΂悢�B
�ň��v�Z�ʂ́AO(n+m+n)=O(n+m)<10^3 �ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_P 100
using namespace std;

int n, m, taro[MAX_P + 1], hanako[MAX_P + 1];

int main() {
	int sumT, sumH, i, minT, minH;
	while (1) {
		scanf("%d%d",&n,&m);
		if (!(n || m))
			break;
		rep(i, MAX_P + 1)
			taro[i] = hanako[i] = 0;
		sumT = sumH = 0;
		while (n--) {
			scanf("%d", &i);
			taro[i]++;
			sumT += i;
		}
		while (m--) {
			scanf("%d", &i);
			hanako[i]++;
			sumH += i;
		}
		minT = minH = MAX_P + 1;
		rep(i, MAX_P + 1)
			if (taro[i] > 0 && (n = sumH - sumT + 2 * i) % 2 == 0 && 0 <= n / 2 && n / 2 <= MAX_P && hanako[n / 2] > 0 && i + n / 2 < minT + minH) {
				minT = i;
				minH = n / 2;
			}
		if (minT == MAX_P + 1)
			printf("%d\n", -1);
		else
			printf("%d %d\n", minT, minH);
	}
	return 0;
}