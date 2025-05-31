/*�A���S���Y���ƍH�v�_(Grid Coloring/CPU: 2 ms  Memory: 3936 KB  Length: 679 B)
���[���痆����ɐF��K�v�ȕ������h���Ă��������B�ň��v�Z�ʂ�O(h*w)<10^6 ���\�������B
��ABC069�S��!
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_H 100
#define MAX_W 100
#define MAX_D 4
#define NIL 0
using namespace std;

int h,w,n,a[MAX_H*MAX_W],c[MAX_H][MAX_W]={0},dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int main() {
	int i,y,x,now,j,cnt;
	scanf("%d%d%d",&h,&w,&n);
	cnt=now=y=x=0;
	rep(i,n){
		scanf("%d",&j);
		while(j--){
			c[y][x]=i+1;
			cnt++;
			while(cnt<h*w&&(y+dy[now]<0||y+dy[now]>=h||x+dx[now]<0||x+dx[now]>=w||c[y+dy[now]][x+dx[now]]!=NIL)){
				now=(now+1)%MAX_D;
			}
			y+=dy[now];
			x+=dx[now];
		}
	}
	rep(i,h){
		rep(j,w-1){
			printf("%d ",c[i][j]);
		}
		printf("%d\n",c[i][j]);
	}
	return 0;
}