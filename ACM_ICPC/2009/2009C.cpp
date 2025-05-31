/*�A���S���Y���ƍH�v�_(���ʎZ/CPU: 880 ms  Memory: 3448 KB  Length: 3406 B)
�P���ɑS�T������ꍇ�A�ő�10��ނ̕����ɑ΂��ĈقȂ鐔�������蓖�Ă邱�ƂɂȂ邩��A10!<10^7 �ƂȂ邪�A���蓖�Ă���ɍő�8*12�̕�����K�₵�A���������邽�߁A�ň��v�Z�ʂ�10^8�𒴂��Ă��܂��\��������B���̏ꍇ�A��̃t�@�C��
�ɂ��镡���̃f�[�^����������K�v�����邱�Ƃ��l������ƁA��̃t�@�C���ɂ�����͂ɑ΂���o�͂��o���܂łɁA1���ȏォ�����Ă��܂��\��������B
�����ŁA�}���T�����s���B�^����ꂽ�e������S1,S2,S3,,,Sn-1 �̉��ʂ̌��̕����ɂ��ꂼ�ꐔ�������蓖�āA���́u���̌��ւ̌J��オ��𖳎������a�v��Sn�̑Ή����錅�̕����Ɋ��蓖�Ă������ƈ�v���邩�A�܂��͈�v����悤�Ɋ��蓖�Ă邱��
���ł��邩�𔻒肵�A�o���Ȃ���΁A�e������S1,S2,S3,,,Sn-1�@�̐����̊��蓖�Ă���蒼���悤�ɂ���B�܂�A�uS1+S2+S3+...+Sn-1�v�̘a�̊e�����ASn�̊e���̒l�ƈ�v����悤�Ɋ��蓖�Ă邱�Ƃ��\�����A���̌����画�肵�Ă����B��������
���ƂŁA�r���̌��ŏ�肭���蓖�Ă邱�Ƃ��ł��Ȃ���΁A���̎��_�ł��̒T���̎}������s���邽�߁A�\�������ɓ��삷��B���̂悤�ȓ��I�ȓ�����s���̂ɁA�ċA�֐��͕֗��B

*��蕶�����Ⴂ���Ă��܂������߁A"2AB5"�̂悤�Ȑ��l�����炩���ߌ��܂��Ă��錅�����݂��镶���񂪗^������ꍇ�ɂ��Ή������R�[�h�ƂȂ��Ă���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 12
#define MAX_NUM 10
#define HEAD 1
#define EXIST 0
#define NIL -1
using namespace std;

int n,maxL;
string str[MAX_N];
map<char, int> v,nnum;   //nnum:�A���t�@�x�b�g�ɑ΂��āA���蓖�Ă�ꂽ������Ԃ��B

int dfs(int y,int x,int c,bool num[]) {   //y�s�ڂ̕�����ɂ��āA���[����x������,���̌��̍��v�lc,�ǂ̐������g�������ێ�����num
	int cnt = 0, i;
	if (y == n - 1) {
		if (x == maxL - 1) {
			if ((int)'0' <= (int)str[y][str[y].length() - 1 - x] && (int)str[y][str[y].length() - 1 - x] <= (int)'9') {
				return (int)str[y][str[y].length() - 1 - x] - (int)'0' == c ? 1 : 0;
			}
			else if (nnum[str[y][str[y].length() - 1 - x]] != NIL) {
				return nnum[str[y][str[y].length() - 1 - x]] == c ? 1 : 0;
			}
			else {
				if (c < 10&&num[c]) {
					if (c== 0)
						return v[str[y][str[y].length() - 1 - x]] == HEAD ? 0 : 1;
					else
						return 1;
				}
				else
					return 0;
			}
		}
		else {
			if ((int)'0' <= (int)str[y][str[y].length() - 1 - x] && (int)str[y][str[y].length() - 1 - x] <= (int)'9') {
				return (int)str[y][str[y].length() - 1 - x] - (int)'0' == c % 10 ? dfs(0, x + 1, c / 10, num) : 0;
			}
			else if (nnum[str[y][str[y].length() - 1 - x]] != NIL) {
				return nnum[str[y][str[y].length() - 1 - x]] == c % 10 ? dfs(0, x + 1, c / 10, num) : 0;
			}
			else {
				if (num[c%10]) {
					if (c % 10 == 0) {
						if (v[str[y][str[y].length() - 1 - x]] == HEAD)
							return 0;
						num[c % 10] = false;
						nnum[str[y][str[y].length() - 1 - x]] = c % 10;
						i = dfs(0, x + 1, c / 10, num);
						nnum[str[y][str[y].length() - 1 - x]] = NIL;
						num[c % 10] = true;
					}
					else {
						num[c % 10] = false;
						nnum[str[y][str[y].length() - 1 - x]] = c % 10;
						i = dfs(0, x + 1, c / 10, num);
						nnum[str[y][str[y].length() - 1 - x]] = NIL;
						num[c % 10] = true;
					}
					return i;
				}
				else
					return 0;
			}
		}
	}
	if ((int)str[y].length() - 1 - x < 0)
		return dfs(y + 1, x, c, num);
	if ((int)'0' <= (int)str[y][str[y].length() - 1 - x] && (int)str[y][str[y].length() - 1 - x] <= (int)'9') {
		cnt += dfs(y + 1, x, c + (int)str[y][str[y].length() - 1 - x] - (int)'0', num);
	}
	else if (nnum[str[y][str[y].length() - 1 - x]] != NIL) {
		cnt += dfs(y + 1, x, c + nnum[str[y][str[y].length() - 1 - x]], num);
	}
	else {
		rep(i, 10) {
			if (num[i]) {
				if (i == 0) {
					if (v[str[y][str[y].length() - 1 - x]] == HEAD)
						continue;
					num[i] = false;
					nnum[str[y][str[y].length() - 1 - x]] = i;
					cnt += dfs(y + 1, x, c + i, num);
					nnum[str[y][str[y].length() - 1 - x]] = NIL;
					num[i] = true;
				}
				else {
					num[i] = false;
					nnum[str[y][str[y].length() - 1 - x]] = i;
					cnt += dfs(y + 1, x, c + i, num);
					nnum[str[y][str[y].length() - 1 - x]] = NIL;
					num[i] = true;
				}
			}
		}
	}
	return cnt;
}

int main() {
	int i, j;
	bool num[MAX_NUM];   //0�`9�̂ǂ̐������g�p�ς݂�
	rep(i, MAX_NUM)
		num[i] = true;
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		maxL = 0;
		rep(i, n) {
			cin >> str[i];
			if (maxL < str[i].length())
				maxL = str[i].length();
			rep(j, str[i].length()) {
				if ((int)'0' <= (int)str[i][j] && (int)str[i][j] <= (int)'9')
					continue;
				if (j == 0 && str[i].length() > 1)
					v[str[i][j]] = HEAD;
				if (v[str[i][j]] == NIL)
					v[str[i][j]] = EXIST;
			}
		}
		i = 0;
		for (pair<char, int> c : v) {
			nnum[c.first] = NIL;
		}
		printf("%d\n", (size_t)maxL == str[n - 1].length() ? dfs(0, 0, 0, num) : 0);
		v.clear();
		nnum.clear();
	}
	return 0;
}

/*

void show() {   //�����Ɋ��蓖�Ă������m���ߗp
	for (pair<char, int> p : nnum) {
		printf("%c %d\n", p.first, p.second);
	}
	puts("");
}

//�S�T���ŉ������Ƃ������

int isEqual() {
	return 1;
}

int dfs(int now,bool num[]) {
	if (alfa[now] == '\0') {
		int ii;

		for (ii = 0; alfa[ii] != '\0'; ii++) {
			printf("%d ", nnum[alfa[ii]]);
		}
		puts("");
		return isEqual();
	}
	int i, cnt = 0;
	rep(i, 10) {
		if (num[i]) {
			if (i == 0) {
				if (v[alfa[now]] == EXIST) {
					nnum[alfa[now]] = i;
					num[i] = false;
					cnt += dfs(now + 1, num);
					num[i] = true;
					nnum[alfa[now]] = NIL;
				}
			}
			else {
				nnum[alfa[now]] = i;
				num[i] = false;
				cnt += dfs(now + 1, num);
				num[i] = true;
				nnum[alfa[now]] = NIL;
			}
		}
	}
	return cnt;
}
*/