/*�A���S���Y���ƍH�v�_(�y�n�͂�/CPU: 0 ms  Memory: 3632 KB  Length: 1556 B)
bfs�ŗ̈�̓h��Ԃ����s���C���[�W�œy�n�̑傫���𐔂��グ��B�e�}�X��ߓ_�Ƃ���ƁA�e�ߓ_�͕ӂ��ő�4�������O���t�����Ȃ��邽�߁A�ň��v�Z�ʂ́AO((h*w+h*w*4)*2)<10^5 �ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_H 50
#define MAX_W 50
using namespace std;

int w, h;
char mmap[MAX_H][MAX_W + 1];
bool flag[MAX_H][MAX_W];   //��x�K�ꂽ�}�X���x�ƖK��Ȃ��悤�ɂ��邽�߂̃}�[�J�[

void initFlag() {
	int i, j;
	rep(i, h)
		rep(j, w)
			flag[i][j] = true;
}

bool isAdj(int y, int x, int& cnt, char c) {   //�͈͊O�̃}�X�ɗאڂ��Ă���ꍇ�A���̃}�X�͊g��אڂ��Ă���Ƃ݂Ȃ��������s���Ă��邽�߁A�͈͊O�̃}�X�����Ɉ͂��Ă���ꍇ���g��אڂ��Ă���Ƃ݂Ȃ��Ă��܂��B
	if (mmap[y][x] == c)
		return true;
	else if (mmap[y][x] != '.')
		return false;
	flag[y][x] = false;
	if ((y + 1 >= h || flag[y + 1][x] == false || isAdj(y + 1, x, cnt, c)) & (y - 1 < 0 || flag[y - 1][x] == false || isAdj(y - 1, x, cnt, c)) & (x + 1 >= w || flag[y][x + 1] == false || isAdj(y, x + 1, cnt, c)) & (x - 1 < 0 || flag[y][x - 1] == false || isAdj(y, x - 1, cnt, c))) {//�Z���]���ɂȂ�Ȃ��悤��'&'���g�p
		cnt++;
		return true;
	}
	cnt = 0;
	return false;
}

int main() {
	int i, j, cntW, cntB, tmp;
	while (1) {
		scanf("%d%d", &w, &h);
		if (!(w || h))
			break;
		cntW = cntB = 0;
		rep(i, h) {
			getchar();
			rep(j, w) {
				scanf("%c", &mmap[i][j]);
				if (mmap[i][j] == 'W')
					cntW++;
				else if (mmap[i][j] == 'B')
					cntB++;
			}
		}
		if (cntW > 0) {
			initFlag();
			cntW = 0;
			rep(i, h)
				rep(j, w)
					if (flag[i][j] && mmap[i][j] == '.') {
						tmp = 0;
						isAdj(i, j, tmp, 'W');
						cntW += tmp;
						//printf("(%d,%d):%d\n", i, j, cntW);
					}
		}
		if (cntB > 0) {
			initFlag();
			cntB = 0;
			rep(i, h)
				rep(j, w)
					if (flag[i][j] && mmap[i][j] == '.') {
						tmp = 0;
						isAdj(i, j, tmp, 'B');
						cntB += tmp;
						//printf("(%d,%d):%d\n", i, j, cntB);
					}
		}
		printf("%d %d\n", cntB, cntW);
	}
	return 0;
}