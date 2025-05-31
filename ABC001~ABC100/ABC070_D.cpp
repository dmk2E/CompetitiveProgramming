/*�A���S���Y���ƍH�v�_(Transit Tree Path /CPU: 74 ms  Memory: 12544 KB  Length: 1006 B)
���_k���n�_�Ƃ���1��̃_�C�N�X�g���@���s���A���_k����e���_i�ւ̍ŒZ�������L�^���Ă������ƂŁA���_i���璸�_K�܂ł̍ŒZ����D1,���_K���璸�_i�܂ł̍ŒZ����D2�����߂邱�Ƃ��ł���B���Ƃ߂鋗���́uD1+D2�v�ƂȂ邩��A
�ň��v�Z�ʂ́AO(N*log2(N)+Q)<10^7 �ƂȂ�A�����B
*/
#include <iostream>
#include <vector>
#include <queue>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 100000
#define MAX (1e15)
using namespace std;

typedef  pair<int,int> p;
typedef  pair<long long,int> d;

int n,q;
long long v2K[MAX_N];
vector<p > adj[MAX_N];

void dijk(int s){
	d now;
	priority_queue<d > PQ;
	PQ.push(d(0,s));
	while(PQ.size()){
		do{
			now=PQ.top();PQ.pop();
		}while(PQ.size()&&v2K[now.second]<MAX);
		if(v2K[now.second]<MAX)
			break;
		v2K[now.second]=-now.first;
		for(p x:adj[now.second]){
			if(v2K[x.first]==MAX)
				PQ.push(d(now.first-x.second,x.first));
		}
	}
	return ;
}

int main() {
	int i,j,k,l;
	p p1=make_pair(2,3);
	scanf("%d",&n);
	rep(i,n-1){
		scanf("%d%d%d",&j,&k,&l);
		j--;k--;
		adj[j].push_back(p(k,l));
		adj[k].push_back(p(j,l));
	}
	scanf("%d%d",&q,&k);
	rep(i,n)
		v2K[i]=MAX;
	k--;
	dijk(k);
	while(q--){
		scanf("%d%d",&i,&j);
		i--;j--;
		printf("%lld\n",v2K[i]+v2K[j]);
	}
	return 0;
}