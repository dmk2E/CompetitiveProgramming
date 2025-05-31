/*�A���S���Y���ƍH�v�_(���P�l�̓��{��/CPU: 0 ms  Memory: 3492 KB  Length: 2543 B)
�܂�1��A���������`�I�ɑ������āA���̒P�ʂŋ�؂�B���񂻂̋�؂�́A�z��mmola�ŕ\���B�z��mmola�ł́A���̐擪�����ƑΉ�����Y�����̈ʒu�A���̔��̒P�ꐔ�����A����ȊO�̓Y�����ł́u-1�v�����
�ĕێ��B���̌�A'i'��'u'�A'a'��'o'�ɂ��āA��蕶��1.,2.�̏����ɂ̂ݓ��Ă͂܂�A�����������ꉹ�Ƀt���O��t���Ă���(�z��ans�őΉ�)�B�Ō�ɁAans�ƕ�����𑖍����āA
�u�ꉹ�������������͍̂ŏ��̕ꉹ�ł���ꍇ�A�܂��͒��߂̕ꉹ������������Ȃ������ꍇ�v�̏����𖞂����Ȃ����A�u�����������t���O�v�����Ă���1�����̃t���O���Ȃ����A�t���O�����Ă���1������()�ł���
���āA�S�̂̕�������o�͂���΂悢�B
�ň��v�Z�ʂ�O(|s|)<10^3 �ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_S 14
#define MAX_STR 100
#define MAX_M 5
#define MAX_B 5
#define NIL -1
using namespace std;

int mmola[MAX_STR];
string str;
bool ans[MAX_STR];
char musei[MAX_M + 1] = "ksthp",boin[MAX_B + 1] = "aiueo";

bool isMusei(char c) {
	int i;
	rep(i, MAX_M)
		if (musei[i] == c)
			break;
	return i < MAX_M;
}

bool isBoin(char c) {
	int i;
	rep(i, MAX_B)
		if (boin[i] == c)
			break;
	return i < MAX_B;
}

void mola(const char *s) {   //���P�ʂɋ�؂�mmola�̍쐬
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		mmola[i] = NIL;
		ans[i] = false;
	}
	for (i = 0; s[i] != '\0';) {
		if (isBoin(s[i])) {
			mmola[i] = 1;   //�����܂��͕ꉹ
			i++;
		}
		else {
			if (isBoin(s[i + 1])||(s[i] == 'n' && s[i + 1] == '\'')) {   //�q��+�ꉹ �u�����v
				mmola[i] = 2;
				i += 2;
			}
			else if (s[i] == s[i + 1] || s[i] == 'n') {   //���� �u�����v
				mmola[i] = 1;
				i++;
			}
			else {   //�u�q���v+�uy�v+�u�ꉹ�v
				mmola[i] = 3;
				i += 3;
			}
		}
	}
	for (i = 0; false&&str[i] != '\0'; i++)
		printf("%d ", mmola[i]);
}

int main() {
	int i, j, last;
	bool flagA, flagO;   //���O�̔��ɂ����āA�����q���Ƌ��ɕꉹ'a'or'o'�����ꂽ���������B
	while (1) {
		getline(cin, str);
		if (str[0] == '#')
			break;
		mola(str.c_str());
		for (i = 0, last = NIL, flagA = flagO = false; i < str.length(); i += mmola[i]) {   //1��̃��[�v��1�̔��𑖍�����B
			rep(j, mmola[i]) {
				if (str[i + j] == 'i' || str[i + j] == 'u') {
					if ((mmola[i] == 2 && isMusei(str[i + j - 1])) || (mmola[i] == 3 && isMusei(str[i + j - 2]))) {
						if (str[i + j + 1] == '\0' || isMusei(str[i + j + 1])) {
							ans[i + j] = true;
						}
					}
				}
				else if (str[i + j] == 'a') {
					flagO = false;
					if ((mmola[i] == 2 && isMusei(str[i + j - 1])) || (mmola[i] == 3 && isMusei(str[i + j - 2]))) {
						if (flagA)
							ans[last] = true;
						flagA = true;
						last = i + j;
						break;
					}
					else
						flagA = false;
				}
				else if (str[i + j] == 'o') {
					flagA = false;
					if ((mmola[i] == 2 && isMusei(str[i + j - 1])) || (mmola[i] == 3 && isMusei(str[i + j - 2]))) {
						if (flagO)
							ans[last] = true;
						flagO = true;
						last = i + j;
						break;
					}
					else
						flagO = false;
				}
			}
			if (j == mmola[i])
				flagA = flagO = false;
		}
		for (i = 0, flagA = true; i < str.length(); i++) {   //�u�ꉹ�������������͍̂ŏ��̕ꉹ�ł���ꍇ�A�܂��͒��߂̕ꉹ������������Ȃ������ꍇ�v�̏�������
			if (isBoin(str[i])) {
				if (ans[i]) {
					if (flagA == false) {
						ans[i] = false;
						flagA = true;
					}
					else
						flagA = false;
				}
				else
					flagA = true;
			}
		}
		rep(i, str.length()) {
			if (ans[i])
				printf("(%c)", str[i]);
			else
				printf("%c", str[i]);
		}
		puts("");
	}
	return 0;
}