/*�A���S���Y���ƍH�v�_(X-Ray Screening System/CPU: 0 ms  Memory: 3208 KB  Length: 3241 B)
�ގ������������͓���̕����Ƃ݂Ȃ��A���̕����͒����`�ŕ\�����B�]���āA�d�ˍ��킳�ꂽ�����̒����`�̈ʒu�֌W�ɖ������Ȃ����A�����Ē����`�ȊO�̌`�ł͂Ȃ����𔻒肷��΂悢�B
�ʒu�֌W�́A���̕��������̕������O�ɂ��邱�Ƃ��A�u26*(���ɑΉ�����z��alfa��̓Y����)+(���ɑΉ�����z��alfa��̓Y����)�v�̐����ŕ\���B�����̂��߁A���̂��Ƃ��u��>���v�Ƃ���B
�V�����ʒu�֌W�u��>���v�����܂��x�ɁA���ɑ��݂���ʒu�֌W�u��>���v������΁A�u��>���v���V������������B�V�����ʒu�֌W�𐶐�����x�ɁA�u��>���v�Ɓu��>���v�������ɑ��݂��Ȃ����𔻒肷��B
���̓����ɑ��݂��Ȃ����̔����Union-find�؂�p�������A�ꎟ���z��ōςނ��߁A�R�[�h���͂���ɒZ���ł���ƍl������B
�ň��v�Z�ʂ́AO(h*w(h*w+676))=O(h^2*w^2)<10^7 ���A�����ɓ��삷��B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX 675+1
#define MAX_H 50
#define MAX_W 50
#define MAX_ALFA 26
#define NIL -1
using namespace std;

typedef struct union_find {
	int par[MAX], rank[MAX];

	union_find() {
		int i, j;
		rep(i, MAX) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x)
			return x;
		return par[x] = find(par[x]);
	}

	void unit(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y])
			par[x] = y;
		else {
			par[y] = x;
			if(rank[x]==rank[y])
				rank[x]++;
		}
	}

	bool isSame(int x,int y) {
		return find(x) == find(y);
	}

}UF;

typedef struct pairing {
	int minX, minY, maxX, maxY;
}P;

int n, h, w;
char d[MAX_H][MAX_W+1],alfa[MAX_ALFA+1]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vector<int> v;

int toNum(char z) {
	int i;
	rep(i, MAX_ALFA)
		if ((int)z == (int)alfa[i])
			return i;
	return NIL;
}

P calHW(char c,int y,int x,P max,bool flag[][MAX_W]) {   //�A���t�@�x�b�gc�̒����`�̍���̓_�ƉE���̓_�����ꂼ�ꋁ�߂�B
	int i, j;
	for(i=y;i<h;i++)
		for(j=0;j<w;j++)
			if (d[i][j] == c) {
				if (max.maxY < i)
					max.maxY = i;
				if (max.maxX < j)
					max.maxX = j;
				if (max.minY > i)
					max.minY = i;
				if (max.minX > j)
					max.minX = j;
				flag[i][j] = true;
			}
	return max;
}

bool isSafe(char c,UF& u,int sy,int sx,int ey,int ex) {
	int a = toNum(c), b, j;
	bool check[MAX_ALFA] = {0};
	//printf("%c:\n",c);
	for(;sy<=ey;sy++)
		for (j=sx; j <= ex; j++) {
			//printf("%c(%d,%d)\n", d[sy][j],sy,j);
			if (d[sy][j] == '.')
				return false;
			if (d[sy][j] != c&&check[(b = toNum(d[sy][j]))]==false) {
				check[b] = true;
				u.unit(MAX_ALFA * b + a, 0);
				v.push_back(MAX_ALFA * b + a);
				//printf("%c>%c b:%d a:%d\n", alfa[b], alfa[a],b,a);
				for (int i : v) {
					if (i / MAX_ALFA == a&&!u.isSame(MAX_ALFA * b + i % MAX_ALFA, 0)) {
						u.unit(MAX_ALFA*b+i%MAX_ALFA,0);
						if (u.isSame(MAX_ALFA * b + i % MAX_ALFA, MAX_ALFA * (i % MAX_ALFA) + b))
							return false;
						v.push_back(MAX_ALFA * b + i % MAX_ALFA);
					}
				}
				if (u.isSame(MAX_ALFA * b + a, MAX_ALFA * a + b))
					return false;
			}
		}
	return true;
}

void showD() {
	int i;
	rep(i, h)
		printf("%s\n", d[i]);
}

void showF(bool flag[][MAX_W]) {
	int i, j;
	rep(i, h) {
		rep(j, w)
			printf("%d", flag[i][j] ? 1 : 0);
		puts("");
	}
}

bool judge() {
	int i,j;
	bool flag[MAX_H][MAX_W] = { 0 };   //��x���ׂ������`���X���[���邽�߂́Ad�ƑΉ������z��B
	UF u;
	P tmp;
	rep(i, h) {
		rep(j, w) {
			if (d[i][j] != '.'&&flag[i][j]==false) {
				//printf("c:%c\n",d[i][j]);
				tmp.minY = i;
				tmp.minX = j;
				tmp.maxX = tmp.maxY = -1;
				//printf("minY:%d minX:%d maxY:%d maxX:%d\n", tmp.minY, tmp.minX, tmp.maxY, tmp.maxX);
				tmp = calHW(d[i][j], i, j, tmp,flag);
				//printf("minY:%d minX:%d maxY:%d maxX:%d\n",tmp.minY,tmp.minX,tmp.maxY,tmp.maxX);
				//showF(flag);
				if (!isSafe(d[i][j],u,tmp.minY,tmp.minX,tmp.maxY,tmp.maxX))
					return false;
			}
		}
	}
	return true;
}

int main() {
	int i;
	scanf("%d",&n);
	while (n--) {
		scanf("%d%d",&h,&w);
		rep(i, h)
			scanf("%s",d[i]);
		//printf("%d %d\n",h,w);
		//showD();
		if (judge())
			cout << "SAFE" << endl;
		else
			cout << "SUSPICIOUS" << endl;
		/*
		for (int j : v) {
			printf("%c>%c\n",alfa[j/MAX_ALFA],alfa[j%MAX_ALFA]);
		}
		*/
		v.clear();
	}
	return 0;
}