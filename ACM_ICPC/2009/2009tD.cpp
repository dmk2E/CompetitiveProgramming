/*�A���S���Y���ƍH�v�_(Restrictive Filesystem/CPU: 260 ms  Memory: 3888 KB  Length: 1502 B)
�������̏�Ԃ��A(�Z�N�^�ԍ��̐擪:s,�Z�N�^�ԍ��̍Ō��+1:e,�������܂�Ă���t�@�C���̎��ʎql)�̏�ԂŁAs�̏����ƂȂ�悤�ɁA���X�g�\���ŕێ�����B�������邱�ƂŁA[s,e)�̃�������ɂǂ̃t�@�C�����������܂�Ă��邩��ێ��ł��A���̈��
��̃f�[�^�̌���N�ȉ��ɂȂ�B����ĎQ�Ƃ̍ہA���`�I�Ƀ��X�g��H���čs���΂�������A���̍ň��v�Z�ʂ�O(N)�ƂȂ�B��������ۂ́A�t�@�C���̃T�C�Y������������܂Ő擪�̃�������������Ă����B��������`�I�ɒH���Ă����΂悢�B
�������ލۂ́A���e����̕����͈̔͂��t�@�C���̃T�C�Y���傫���ꍇ�A�t�@�C�����������񂾕����Ɠ��e����̂܂܂̕����Ƃœ�ɕ�����K�v������A���̎��̌v�Z�ʂ�O(1)�ƂȂ�B�t�@�C���̃T�C�Y��菬�����ꍇ�A��̕����S�Ă��t�@�C���ɖ���
��΂悢���߁Al�̏��������邾���ŗǂ��A���`�I�Ƀ��X�g��H���ď�������ł����΂悢�B
�S�̂̍ň��v�Z�ʂ�O(N^2)=10^8(�Ȍ��ȏ����Ȃ�Ԃɍ���) �ƂȂ邪�A���߂ɂ���Ă̓��X�g�̃f�[�^�̐���N��菬�����Ȃ�A�ň��v�Z�ʂ�10^8�����ɂȂ邽�߁A�Ԃɍ����Ɨ\���ł����B
*���X�g�\���ɂ����āA��x�ł��v�f��ǉ���������������肵���ꍇ�A�C�e���[�^��begin�֐����ł�����x�擾�������Ȃ���΂Ȃ�Ȃ����Ƃɒ��ӁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_NUM 1000000000
#define NIL -1
using namespace std;

typedef struct data {
	int s, e, l;

	data(int ss=0, int ee=0, int ll=0):s(ss),e(ee),l(ll) {}
}Data;

int n, l, s;
char command;
list<Data> llog;
map<int, int> ssize;

int main() {
	int i;
	list<Data>::iterator it;
	while (1) {
		scanf("%d",&n);
		if (!n)
			break;
		llog.push_back(Data(0, MAX_NUM + 1, NIL));
		//ssize[NIL] = MAX_NUM;
		while (n--) {
			getchar();
			scanf("%c", &command);
			switch (command) {
				case 'W':
					scanf("%d%d", &l, &s);
					//ssize[NIL] -= s;
					ssize[l] = s;
					for (it = llog.begin(); it != llog.end(); it++) {   //�ň��v�Z��O(N)
						if ((*it).l == NIL) {
							if ((*it).s + s < (*it).e) {
								(*it).s += s;
								llog.insert(it, Data((*it).s - s, (*it).s, l));
								break;
							}
							else {
								(*it).l = l;
								s -= (*it).e - (*it).s;
								if (s == 0)
									break;
							}
						}
					}
					break;
				case 'R':
					scanf("%d", &l);
					for (it = llog.begin(); it != llog.end(); it++) {   //�ň��v�Z��O(N)
						if ((*it).s <= l && l < (*it).e)
							break;
					}
					printf("%d\n", (*it).l);
					break;
				default :
					scanf("%d", &l);
					//ssize[NIL] += ssize[l];
					for (it = llog.begin(); it != llog.end() && ssize[l] > 0; it++) {   //�ň��v�Z��O(N)
						if ((*it).l == l) {
							ssize[l] -= (*it).e - (*it).s;
							(*it).l = NIL;
						}
					}
					break;
			}
		}
		llog.clear();
		ssize.clear();
		puts("");
	}
	return 0;
}