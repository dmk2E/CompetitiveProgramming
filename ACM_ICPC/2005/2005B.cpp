/*�A���S���Y���ƍH�v�_(Polygonal Line Search/CPU: 0 ms  Memory: 3112 KB  Length: 1488 B)
���s�ړ����Ă���v���邱�Ƃ��ȒP�Ɍ��؂ł���悤�ɁA�܂�����x�N�g���ŕێ�����B�܂��0��v1�ɕێ����A�܂��1�`n��v2�ɕێ����Av2��0,90,180,270�x��]���������̂�v1���r����B���̎��A���_���t���Ɏw�肳��Ă�����̂𓯂��ƌ��Ȃ�
���߂̏������Y�ꂸ�ɂ��B�v�Z�ʂ�O(n*m)=5*10^2 �ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t){t=a,a=b,b=c}
#define MAX_M 10
using namespace std;

typedef struct v {
	int y, x;
}Vector;

int n,m;
Vector v1[MAX_M-1], v2[MAX_M - 1];

void rotate90() {
	int i;
	Vector temp;
	rep(i, m - 1) {
		temp = v2[i];
		v2[i].y = temp.x;
		v2[i].x = -temp.y;
	}
}

bool judge() {
	int i,j;
	rep(i, 4) {
		rep(j, m - 1)
			if (v1[j].y != v2[j].y || v1[j].x != v2[j].x)
				break;
		if (j == m - 1)
			break;
		rotate90();
	}
	if (i < 4) 
		return true;
	rep(i, 4) {   //�t���ɒ��_���w�肳��Ă���ꍇ�A�x�N�g���̌������t�ɂȂ邱�Ƃɒ��ӁB
		rep(j,m-1)
			if (v1[j].y != -v2[m-2-j].y || v1[j].x != -v2[m-2-j].x)
				break;
		if (j == m-1)
			break;
		rotate90();
	}
	if (i < 4) 
		return true;
	return false;
}

int main() {
	int i, j, py, px, ny, nx,m1;
	Vector temp;
	while (1) {
		//scanf_s("%d",&n);
		scanf("%d", &n);
		if (n == 0)
			break;
		//scanf_s("%d", &m);
		scanf("%d", &m);
		//scanf_s("%d%d", &px, &py);
		scanf("%d%d", &px, &py);
		m1 = m;
		rep(j, m - 1) {
			//scanf_s("%d%d", &nx, &ny);
			scanf("%d%d", &nx, &ny);
			temp.y = ny - py;
			temp.x = nx - px;
			v1[j] = temp;
			px = nx;
			py = ny;
		}
		rep(i,n) {
			//scanf_s("%d", &m);
			scanf("%d", &m);
			//scanf_s("%d%d", &px, &py);
			scanf("%d%d",&px,&py);
			rep(j,m-1) {
				//scanf_s("%d%d",&nx,&ny);
				scanf("%d%d", &nx, &ny);
				temp.y = ny - py;
				temp.x = nx - px;
				v2[j] = temp;
				px = nx;
				py = ny;
			}
			if (m==m1&&judge()) 
				printf("%d\n", i + 1);
		}
		puts("+++++");
	}
	return 0;
}