/*�A���S���Y���ƍH�v�_(�@���ɓ��𖞑������߂ށH ���������グ�ށc/CPU: 0 ms  Memory: 3440 KB  Length: 2922 B)
�������͂ł́A'('��')'�ŋ��܂ꂽ���������̒P�ʂƂ��A����(������)�̉������߂�ċA�֐�solve�����悤�ɂ���Bsolve�֐��ł͒��ڂ��Ă��镶������ŁA(������)�𔭌������ꍇ�Asolve�֐����ċA�Ăяo�����A(������)����̉�
�ƌ��Ȃ��ď������s���Ă����Bsolve�֐��͕�����S�ɑ΂��āA�ň��v�Z��O(|S|) �ƂȂ�B����ł́Ap,q,r�̑S�p�^�[����27�ʂ�ƂȂ邩��A�S�̂̍ň��v�Z�ʂ́AO(27*|MAX_S|)<10^4 �ƂȂ�\�������B
*����֐��ɓn������1�ŗp�����ϐ����A���̈����̏��ň���1�̑������u���Ă��܂��Ə�肭�s���Ȃ��������邽�߁A��΂ɂ��Ȃ����ƁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX 3
#define MAX_S 80
#define NIL -1
using namespace std;

int hitei[MAX] = { 2,1,0 }, seki[][MAX] = { {0,0,0},{0,1,1},{0,1,2} }, wa[][MAX] = { {0,1,2},{1,1,2},{2,2,2} };
char s[MAX_S + 1];

int toNum(char c,int p,int q,int r) {   //'0','1','2','P','Q','R'���ꂼ��1������Ή����鐮���l�ɕϊ�����֐��B�ʏ��switch���ł�break�����K�v�ɂȂ�B
	if ((int)'0' <= (int)c && (int)c <= (int)'2')
		return c - (int)'0';
	switch (c) {
		case 'P':
			return p;
		case 'Q':
			return q;
		default:
			return r;
	}
}

int endSearch(int now) {   //s[now]=='('�ƂȂ�now��Ԃ��A����'('�ƑΉ�����')'�̓Y������Ԃ��B
	int tmp = 1;
	while (tmp > 0) {
		if (s[++now] == '(')
			tmp++;
		else if (s[now] == ')')
			tmp--;
	}
	return now;
}

int solve(int ss, int e, int p, int q, int r) {   //s[ss]=='(',s[e]==')'�ƂȂ銇�ʓ����̎��̌v�Z���ʂ�Ԃ��֐��B
	int now, tmp, left = NIL, temp, cal = NIL;
	//printf("[%d,%d]\n", ss, e);
	for (now = ss + 1; now < e; now++) {
		if (s[now] == '-') {   //--...--() �͂����ŏ�������B-�̉e�����󂯂�̂���̒萔��ϐ������ł͂Ȃ��A�_�����ł���ꍇ�������ŏ�������B
			tmp = 1;
			while (s[++now] == '-')
				tmp = (tmp + 1) % 2;
			temp = now;
			if (tmp) {
				if (s[now] == '(')
					tmp = hitei[solve(now, temp = endSearch(now), p, q, r)];
				else
					tmp = hitei[toNum(s[now], p, q, r)];
			}
			else {
				if (s[now] == '(')
					tmp = solve(now, temp = endSearch(now), p, q, r);
				else
					tmp = toNum(s[now], p, q, r);
			}
			now = temp;
		}
		else if (s[now] == '(') {   //�u-�v���Ȃ��_�����̏���
			temp = now;
			now = endSearch(now);
			tmp = solve(temp, now, p, q, r);
		}
		else if (s[now] == '+') {   //()�����̌v�Z��+�Ȃ̂�*�Ȃ̂���ێ�
			cal = 0;
			continue;
		}
		else if (s[now] == '*') {
			cal = 1;
			continue;
		}
		else
			tmp = toNum(s[now], p, q, r);   //1�̒萔�A�ϐ��������ꍇ�̏���
		//printf("now:%d %d(%d,%d,%d)\n", now, tmp, p, q, r);
		if (left == NIL)   //�퉉�Z�q�̍�����ێ�
			left = tmp;
		else {
			if (cal == 0)
				return wa[left][tmp];
			else
				return seki[left][tmp];
		}
	}
	return left;   //�P�����Z�������ꍇ
}

bool judge(int p,int q,int r) {
	int now, tmp, left = NIL, temp, cal;
	for (now = 0; s[now] != '\0'; now++) {
		if (s[now] == '-') {
			tmp = 1;
			while (s[++now] == '-')
				tmp = (tmp + 1) % 2;
			temp = now;
			if (tmp) {
				if (s[now] == '(')
					tmp = hitei[solve(now, temp = endSearch(now), p, q, r)];
				else
					tmp = hitei[toNum(s[now], p, q, r)];
			}
			else {
				if (s[now] == '(')
					tmp = solve(now, temp = endSearch(now), p, q, r);
				else
					tmp = toNum(s[now], p, q, r);
			}
			now = temp;
		}
		else if (s[now] == '(') {
			temp = now;
			now = endSearch(now);
			tmp = solve(temp, now, p, q, r);
		}
		else if (s[now] == '+') {
			cal = 0;
			continue;
		}
		else if (s[now] == '*') {
			cal = 1;
			continue;
		}
		else
			tmp = toNum(s[now], p, q, r);
		//printf("now:%d %d(%d,%d,%d)\n", now, tmp, p, q, r);
		if (left == NIL)
			left = tmp;
		else {
			if (cal == 0)
				return wa[left][tmp] == 2;
			else
				return seki[left][tmp] == 2;
		}
	}
	return left == 2;
}

int main() {
	int i, j, k, cnt;
	while (1) {
		scanf("%s", s);
		if (s[0] == '.')
			break;
		cnt = 0;
		rep(i,MAX)
			rep(j,MAX)
				rep(k, MAX)
					if (judge(i, j, k)){
						cnt++;
						//printf("%d %d %d\n", i, j, k);
					}
		printf("%d\n", cnt);
	}
	return 0;
}