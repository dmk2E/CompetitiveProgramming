/*�A���S���Y���ƍH�v�_(Simple Knapsack/CPU: 2 ms  Memory: 3884 KB  Length: 1861 B)
w0,w0+1,w0+2,w0+3���ꂼ��a,b,c,d�I�Ԏ��Aa+b+c+d=n�ł���A�I�ѕ��̑S�p�^�[����k=a*b*c*d�ƂȂ�Bk�̍ő�l��a=b=c=d=n/4�ł��邩��A�ő�l��k=(n/4)^4<10^6 �ƂȂ�\�������B�}��������ł���ɍ������ł�
��B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)n;i++)   //unsigned int�̕ϐ���p�����v�Z���ʂ����̐��ɂȂ��Ă��܂��A���̒l��n���Ă��܂��ƃo�O���N�����Ă��܂��B
#define MAX_N 100
#define MAX_W 3
using namespace std;

typedef long long ll;

int n, w;
vector<ll> v[MAX_W+1];

int main() {
	int i, j, k, ii;
	ll min, vv, ww, maxV;
	bool flag[MAX_W+1];
	scanf("%d%d", &n, &w);
	scanf("%lld%lld", &min, &vv);
	v[0].push_back(-vv);
	while (--n) {
		scanf("%lld%lld", &ww, &vv);
		v[ww - min].push_back(-vv);
	}
	rep(i, MAX_W + 1) {
		sort(v[i].begin(), v[i].end());
		flag[i] = false;
	}
	rep(i, MAX_W+1) {
		rep(j, v[i].size()-1) 
			v[i][j + 1] += v[i][j];
	}
	ww = vv = maxV = 0;
	rep(i, v[0].size()+1) {
		if (i > 0 && ww + min*i <= w) {
			ww += min*i;
			vv += v[0][i-1];
			flag[0] = true;
		}
		//printf("ww:%lld vv:%lld\n",ww,-vv);
		rep(j, v[1].size()+1) {
			if (j > 0 && ww + (min + 1)*j <= w) {
				ww += (min + 1)*j;
				vv += v[1][j-1];
				flag[1] = true;
			}
			//printf("i:%d j:%d ww:%lld vv:%lld\n",i,j, ww, -vv);
			rep(k, v[2].size()+1) {
				if (k > 0 && ww + (min + 2)*k <= w) {
					ww += (min + 2)*k;
					vv += v[2][k-1];
					flag[2] = true;
				}
				//printf("ww:%lld vv:%lld\n", ww, -vv);
				rep(ii, v[3].size()+1) {
					if (ii > 0 && ww + (min + 3)*ii <= w) {
						ww += (min + 3)*ii;
						vv += v[3][ii-1];
						flag[3] = true;
					}
					//printf("ww:%lld vv:%lld\n", ww, -vv);
					if (maxV < -vv)
						maxV = -vv;
					if (flag[3]) {
						ww -= (min + 3) * ii;
						vv -= v[3][ii-1];
						flag[3] = false;
					}
				}
				if (flag[2]) {
					ww -= (min + 2) * k;
					vv -= v[2][k-1];
					flag[2] = false;
				}
			}
			if (flag[1]) {
				ww -= (min + 1) * j;
				vv -= v[1][j-1];
				flag[1] = false;
			}
		}
		if (flag[0]) {
			ww -= min * i;
			vv -= v[0][i-1];
			flag[0] = false;
		}
	}
	printf("%lld\n",maxV);
	return 0;
}