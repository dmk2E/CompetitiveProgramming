/*�A���S���Y���ƍH�v�_(Mysterious Gems/CPU: 0 ms  Memory: 3472 KB  Length: 1016 B)
gem�����݂���ʒu�Ɂutrue�v�A�����Ȃ��ʒu�Ɂufalse�v����ꂽmp�𗘗p���āA���͂Ŏw�����ꂽ�ړ��������s���V�~�����[�V�����ŉ�����B�v�Z�ʂ́AO(m*(MAX_WorMAX_H))=30*20=600<10^3�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_H 20
#define MAX_W 20
#define MAX_D 4
using namespace std;

int n, m, dx[MAX_D] = { 0,1,0,-1 }, dy[MAX_D] = { 1,0,-1,0 };
bool mp[MAX_H+1][MAX_W+1];

int main() {
	int i, j, k, y, x;
	char d;
	while (1) {
		scanf("%d",&n);
		if (!n)
			break;
		rep(i, MAX_H + 1)
			rep(j, MAX_W + 1)
				mp[i][j] = false;
		rep(k, n) {
			scanf("%d%d",&j,&i);
			mp[i][j] = true;
		}
		scanf("%d",&m);
		y = x = 10;
		while (m--) {
			getchar();
			scanf("%c %d",&d,&k);
			switch (d) {
				case 'N':
					i = 0;
					break;
				case 'E':
					i = 1;
					break;
				case 'S':
					i = 2;
					break;
				default:
					i = 3;
					break;
			}
			for (j = 0; j < k; j++) {
				y += dy[i]; x += dx[i];
				//printf("(%d,%d)\n",dy[i],dx[i]);
				if (mp[y][x]) {
					n--;
					mp[y][x] = false;
					//printf("Get!");
				}
				//printf("%d %d\n",y,x);
			}
			//puts("");
		}
		if (n == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

