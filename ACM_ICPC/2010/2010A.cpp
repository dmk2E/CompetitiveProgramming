/*�A���S���Y���ƍH�v�_(�p�p�攌�C�����Y�݂�/CPU: 0 ms  Memory: 3480 KB  Length: 803 B)
�ŏ��ɐ����`���u�������W��(0,0)�Ƃ��A����ȍ~�u����鐳���`�̍��W�����߂Ă����B���̎��A�����`���u���ꂽx���W�̍ŏ��l�ƍő�l�̍����狁�߂镝�����߂邱�Ƃ��ł���B�����ɂ��Ă����l�ł���B
�ň��v�Z�ʂ�O(n)�ƂȂ�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 200
using namespace std;

typedef struct square {
	int y, x;

	square(int yy=0,int xx=0):y(yy),x(xx){}
}Square;

int n, nn, d, dx[] = { -1,0,1,0 }, dy[] = { 0,-1,0,1 };
Square sq[MAX_N];   //sq[i]:�ԍ�i�̐����`���u����Ă�����W���i�[���Ă����B

int main() {
	int i, minX, maxX, minY, maxY;
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		sq[0] = Square(0, 0);
		minX = minY = maxX = maxY = 0;
		rep(i, n - 1) {
			scanf("%d%d", &nn, &d);
			sq[i + 1] = Square(sq[nn].y + dy[d], sq[nn].x + dx[d]);
			if (minX > sq[i + 1].x)
				minX = sq[i + 1].x;
			if (maxX < sq[i + 1].x)
				maxX = sq[i + 1].x;
			if (minY > sq[i + 1].y)
				minY = sq[i + 1].y;
			if (maxY < sq[i + 1].y)
				maxY = sq[i + 1].y;
		}
		printf("%d %d\n", maxX - minX + 1, maxY - minY + 1);
	}
	return 0;
}