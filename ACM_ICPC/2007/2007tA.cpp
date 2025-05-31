/*�A���S���Y���ƍH�v�_(�F�����V�K�j/CPU: 10 ms  Memory: 3292 KB  Length: 806 B)
�������Ax,y,z>=0 ���� x+y+z=m ���� x+y^2+z^3=e �ƂȂ邩��Ax���������āAm=e+y+z-y^2-z^3 �ƂȂ�B����m�̍ŏ��l�����߂�΂悢�B
e<=10^6���A0<=y<=10^3,0<=z<=10^2 �ƂȂ�Az�̒l���Œ肵�����Ay�ɑ΂���m�͒P����������(��y-y^2��y�̑����ɑ΂��ĒP������)�B�܂��Ax>=0���Ax=e-y^2-z^3>=0 ���� e+y+z-y^2-z^3>=y+z(x=m-y-z>=0���m>=y+z) �𖞂����K�v������A
z���Œ肵�Ă��鎞�Am��x�̒l��y�̑����ɑ΂��ĒP���Ɍ�������B�]���āA�S�Ă̏����𖞂���m�̍ŏ��l�́A�񕪒T���ŉ������Ƃ��ł���By��z�ǂ�����Œ肵�Ă��悢���A�Œ肷��l�͐��`�T���ɂȂ邽�߁Ay���l�悪����z���Œ肵������
�v�Z�ʂ͏��Ȃ��B�]���āA�ň��v�Z�ʂ́AO(z*log2(y))<10~4�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_Y 1000
#define MAX_Z 100
#define ERROR -1
#define MAX_MIN 1001100
using namespace std;

int e;

int calM(int y,int z) {
	int tmp;
	if (e - y * y - z * z * z < 0 || (tmp = e + y + z - y * y - z * z * z) < y + z)
		return ERROR;
	return tmp;
}

int main() {
	int left, right, mid, z, min;
	while (1) {
		scanf("%d",&e);
		if (!e)
			break;
		min = MAX_MIN;
		rep(z, MAX_Z+1) {
			left = 0; right = MAX_Y + 1;
			while (left < right) {
				mid = (left + right) / 2;
				if (calM(mid, z) < 0)
					right = mid;
				else
					left = mid + 1;
			}
			if (left - 1 >= 0 && (mid = calM(left - 1, z)) >= 0 && mid < min) {   //mid�͈ꎟ�I�ɒl��ޔ����邽�߂̕ϐ��Ƃ��Ďg�����B
				min = mid;
				//printf("y:%d z:%d min:%d\n", left - 1, z, min);
			}
		}
		printf("%d\n", min);
	}
	return 0;
}