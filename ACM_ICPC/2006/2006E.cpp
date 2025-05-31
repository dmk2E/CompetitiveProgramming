/*�A���S���Y���ƍH�v�_(The Genome Database of All Space Life/CPU: 0 ms  Memory: 3324 KB  Length: 2726 B)
�^����ꂽs��ŁA()�ň͂�ꂽ��������u����������v�Ƃ���B�܂��Amain�֐����Œ��ڂ��Ă��镶����́A()�ň͂��Ă��Ȃ�������Ƃ���(���߂�s)�B
s��擪����K�₵�Ă����A�r����x�Ԗڂ̕��������ꂽ��A���̕������o�͂���B�r����'('���o�ꂵ���ꍇ�A����Ƒ΂ƂȂ�')'�Ƃ̊Ԃɑ��݂��镔��������̒���(�����u3(ABC)D�v�Ȃ�uABCABCABCD�v�ƂȂ邩�璷���́u10�v�ƂȂ�)��
cal�֐��Ōv�Z���A����()�̌W�����l�����������ŁA���̕������������x�Ԗڂ̕��������݂��Ȃ��Ȃ�A')'�̎��̕�������K����ĊJ����B���݂���Ȃ�A���ڂ��镶��������̕���������ɍX�V���A�ȍ~���l�̏���������B�X�V����ہA
x,bbgn�̒l�̍X�V��������ƍs������(x�̒l�͒P����x�𕔕�������̒����Ŋ������]��ƂȂ�)�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_ALFA 26
#define MAX_S 100
#define NIL -1
using namespace std;

typedef struct keisu {   //keta:���� value:�l
	int keta, value;
}Keisu;

int x;
Keisu K[MAX_S];
char s[MAX_S+1],alfa[MAX_ALFA+1]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isAlfa(char c) {   //�����R�[�h�̋K�i�ɂ���ẮA'A'�`'Z'�̕����R�[�h�͘A�����Ȃ����߁A���̊֐���p�ӁB
	int i;
	rep(i, MAX_ALFA)
		if (c == alfa[i])
			return true;
	return false;
}

int cal(int& bgn) {   //()�ň͂܂ꂽ������̓Y����[bgn,end]�Ƃ��A()���̕�����̐���Ԃ��B������x�𒴂���l�̏ꍇ�A�K�����̒��ɑ��݂��邩��A�u-1�v��Ԃ��B�������y�ɂ��邽�߁A�ċA�֐��𗘗p����B
	int sum = 0, seki = 1, temp;
	//printf("[%d,",bgn);
	while (1) {
		if (s[++bgn] == '(') {
			if ((temp = cal(bgn)) == NIL)
				return NIL;
			sum += seki*temp;
			seki = 1;
		}
		else if (s[bgn] == ')')
			break;
		else if ((int)'0' <= (int)s[bgn] && (int)s[bgn] <= (int)'9') {
			seki = K[bgn].value;
			bgn += K[bgn].keta - 1;
		}
		else {
			sum += seki;
			seki = 1;
		}
		if ((long long)x < sum)
			return NIL;
		//printf(" sum:%d ",sum);
	}
	//printf("%d]\n",bgn);
	return sum;
}

int main() {
	int i, j, bbgn, seki,tmp;   //bbgn:s[i]�̌��݂̑S�̂̕������̃C���f�b�N�X seki:���ݒ��ڂ��Ă��镶���񒆂̕���������̌W��
	while (1) {
		scanf("%s%d",s,&x);
		if (s[0] == '0' && x == 0)
			break;
		for (i = 0; s[i] != '\0'; i++) {   //K�̏�����
			if((int)'0' <= (int)s[i] && (int)s[i] <= (int)'9'){
				tmp = i;
				j = 0;
				while ((int)'0' <= (int)s[i] && (int)s[i] <= (int)'9') {
					j *= 10;
					j += (int)s[i++] - (int)'0';
				}
				K[tmp].keta = i - tmp; K[tmp].value = j;
				i--;
			}
		}
		j = 0;
		/*
		for (i = 0;s[i]!='\0'; i++) {   //cal�֐��̃e�X�g
			if (s[i] == '(') {
				j = i;
				printf("%d:%d\n", i, cal(j));
			}
		}
		*/
		for (i = bbgn = 0, seki = 1; s[i] != '\0';) {
			if((int)'0' <= (int)s[i] && (int)s[i] <= (int)'9') {
				seki *= K[i].value;
				i += K[i].keta;
			}
			else if (isAlfa(s[i])) {
				tmp = bbgn + seki - 1;
				//printf("tmp:%d\n",tmp);
				if (x <= tmp) {
					printf("%c\n",s[i]);
					break;
				}
				bbgn = tmp + 1;
				i++;
				seki = 1;
			}
			else if (s[i] == '(') {
				tmp = i;
				j = cal(tmp);
				if (j == NIL) {
					i++;
				}
				else if (x < bbgn+seki * j) {
					i++;
					x = (x - bbgn) % j;
					bbgn = 0;
				}
				else {
					i = tmp + 1;
					bbgn += seki * j;
				}
				seki = 1;
			}
			//printf("i:%d bbgn:%d x:%d seki:%d j:%d\n",i,bbgn,x,seki,j);
		}
		if (s[i] == '\0')
			puts("0");
	}
	return 0;
}