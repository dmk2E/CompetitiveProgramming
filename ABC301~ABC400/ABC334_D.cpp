/*�A���S���Y���ƍH�v�_(Reindeer and Sleigh/CPU: 103 ms  Memory: 7008 KB  Length: 590 B)
������\���̑䐔���ő剻������B�����\������I�ԍہA�����\��1��ł��A�ł��邾���K�v�ȃg�i�J�C�̐��͏����������悢�B�]���āA�K�v�ȃg�i�J�C�̐������������Ɉ����\����I��ł����΂悢�B
�񕪒T���ƗݐϘa��p���邱�ƂŁA�v�Z�ʂ́AO(q*lon2(n))�ƂȂ�A�\�������ɂȂ�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 200000
using namespace std;

typedef long long ll;

int n,q;
ll r[MAX_N],x,sum[MAX_N+1];

int main() {
	int i, left, right, mid;
	scanf("%d%d",&n,&q);
	rep(i, n)
		scanf("%lld",&r[i]);
	sort(r,r+n);
	sum[0] = 0;
	rep(i, n)
		sum[i + 1] = r[i] + sum[i];
	while (q--) {
		scanf("%lld",&x);
		left = 0;
		right = n + 1;
		while (left < right) {
			mid = (left + right) / 2;
			if (sum[mid] > x)
				right = mid;
			else
				left = mid + 1;
		}
		printf("%d\n", left - 1);
	}
	return 0;
}