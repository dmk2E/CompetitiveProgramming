/*�A���S���Y���ƍH�v�_(String Bags/CPU: 4 ms  Memory: 3996 KB  Length: 425 B)
dp[i][j]:��[0,i)�܂ł̕�����A��p���āA������t��[0,j)�̕������������������̍ŏ��R�X�g�Ƃ������I�v��@�ŉ�����B�ň��v�Z�ʂ�O(n*a*|s|*|t|)<10^7�ƂȂ�A�����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 100
#define MAX_T 100
#define NIL 101
using namespace std;

int n,dp[MAX_N+1][MAX_T+1];
string t,s;

void showDP(){
	int i,j;
	rep(i,n+1){
		rep(j,t.length()+1)
			printf("%3d ",dp[i][j]);
		puts("");
	}
}

int main() {
	int i,j,k;
	cin>>t;
	scanf("%d",&n);
	rep(i,n){
		rep(j,t.length()+1){
			dp[i][j]=NIL;
		}
	}
	dp[0][0]=0;
	rep(i,n){
		scanf("%d",&j);
		rep(k,t.length()+1)
			dp[i+1][k]=dp[i][k];
		while(j--){
			cin>>s;
			rep(k,t.length()+1){
				//printf("%d %d\n",k+(int)s.length(),(int)t.length());
				//cout<<t.substr(0,k)+s<<endl;
				//cout <<t.substr(0,k+s.length())<<endl;
				//puts("");
				if(dp[i][k]!=NIL&&k+s.length()<=t.length()&&(t.substr(0,k)+s)==t.substr(0,k+s.length())&&dp[i][k]+1<dp[i+1][k+s.length()])
					dp[i+1][k+s.length()]=dp[i][k]+1;
			}
		}
	}
	//showDP();
	printf("%d\n",dp[n][t.length()]==NIL?-1:dp[n][t.length()]);
	return 0;
}