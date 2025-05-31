/*アルゴリズムと工夫点(時は金なり/CPU:  ms Memory:  KB  Length:  B)

*/
#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_CNT 20000
#define MAX_TWO 60
#define MOD ((int)(1e9)+7)
using namespace std;

//typedef pair<int,bool> pp;//0で歩道,1で車道

typedef struct route{
	int nxt,wt,f;

	route(int nnxt=0,int wwt=0,int ff=0):nxt(nnxt),wt(wwt),f(ff){}
}Route;

long long two[MAX_TWO+1];

typedef struct data{
	int nxt,cnt,last;
	long long wt;
	bool isRide;

	data(int nnxt=0,long long wwt=0,int ccnt=0,bool iisRide=false,int llast=-1):nxt(nnxt),wt(wwt),cnt(ccnt),isRide(iisRide),last(llast){}

	bool operator>(const data& k)const{//ここが問題
		// int i;
		// long long sum=1,sumK=1;
		// rep(i,cnt)sum*=2;sum--;
		// rep(i,k.cnt)sumK*=2;sumK--;
		// return wt+sum>k.wt+sumK||(wt+sum==k.wt+sumK&&wt==k.wt?cnt>k.cnt:wt>k.wt);
		if(wt>k.wt){
			if(cnt>=k.cnt)
				return true;
			if(k.cnt-cnt>=MAX_TWO)
				return false;
			return wt-k.wt>two[k.cnt-cnt];
		}else{
			if(cnt<=k.cnt)
				return false;
			if(cnt-k.cnt>=MAX_TWO)
				return true;
			return two[cnt-k.cnt]>k.wt-wt;
		}
		return false;
	}
}Data;

int n,p,q,mod[MAX_CNT+2];

int dijk(const vector<vector<Route> >& adj){
	Data now;
	//bool color[MAX_CNT][MAX_CNT+1][2]={0};
	vector<vector<vector<bool> > > color(n,vector<vector<bool> >(MAX_CNT,vector<bool>(2)));
	priority_queue<Data,vector<Data>,greater<Data> > PQ;
	PQ.push(Data());
	while(PQ.size()){
		do{
			now=PQ.top();PQ.pop();
		}while(PQ.size()&&color[now.nxt][now.cnt][now.isRide?1:0]);
		//printf("Now:%d %lld %d %d\n",now.nxt,now.wt,now.cnt,now.isRide?1:0);
		if(color[now.nxt][now.cnt][now.isRide?1:0])
			break;
		color[now.nxt][now.cnt][now.isRide?1:0]=true;
		if(now.nxt==n-1){
			return (int)(((now.wt%MOD)+mod[now.cnt]-1)%MOD);
		}
		for(Route x:adj[now.nxt]){
			if(x.nxt==now.last)
				continue;
			if(x.f){//車道
				if(now.isRide==false){
					if(color[x.nxt][now.cnt+1][1]==false){
						PQ.push(Data(x.nxt,now.wt+x.wt,now.cnt+1,true,now.nxt));
						//printf("New:%d %lld %d %d\n",x.nxt,now.wt+x.wt,now.cnt+1,1);
					}
				}else{
					if(color[x.nxt][now.cnt][1]==false){
						PQ.push(Data(x.nxt,now.wt+x.wt,now.cnt,true,now.nxt));
						//printf("New:%d %lld %d %d\n",x.nxt,now.wt+x.wt,now.cnt,1);
					}
				}
			}else{//歩道
				if(color[x.nxt][now.cnt][0]==false){
					PQ.push(Data(x.nxt,now.wt+x.wt,now.cnt,false,now.nxt));
				}
			}
		}
	}
	return -1;
}

int main(){
	int i,j,k;
	mod[0]=1;
	two[0]=1;
	for(i=1;i<MAX_CNT+2;i++)
		mod[i]=(int)(((2*(long long)mod[i-1]))%MOD);
	for(i=1;i<MAX_TWO+1;i++){
		two[i]=two[i-1]*2;
		//cout<<two[i]<<endl;
	}
	while(1){
		scanf("%d%d%d",&n,&p,&q);
		if(!(n||p||q))
			break;
		vector<vector<Route> > adj(n,vector<Route>(0));
		while(p--){
			scanf("%d%d%d",&i,&j,&k);
			i--;j--;
			adj[i].push_back(Route(j,k,0));
			adj[j].push_back(Route(i,k,0));
		}
		while(q--){
			scanf("%d%d%d",&i,&j,&k);
			i--;j--;
			adj[i].push_back(Route(j,k,1));
			adj[j].push_back(Route(i,k,1));
		}
		printf("%d\n",dijk(adj));
	}
	return 0;
}