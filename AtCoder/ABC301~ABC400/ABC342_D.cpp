/*�A���S���Y���ƍH�v�_(Square Pair/CPU: 172 ms  Memory: 4664 KB  Length: 504 B)
�eAi���A�f�������������Ƃ��ɓ��ɂȂ��Ă���v�f�𖳎������ꍇ�Ɏc��l�ŃO���[�v�������A�Ō��2�̑I�ѕ��𐔂��グ��΂悢�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_A 200000
using namespace std;

int n,cnt[MAX_A+1]={0};

int main() {
	int i,j,k,max;
	long long ans=0;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&j);
		if(j==0)
			ans++;
		else{
			for(k=2,max=sqrt(j);k<=max;k++){
				while(j%(k*k)==0)
					j/=(k*k);
			}
			cnt[j]++;
		}
	}
	ans=ans*(ans-1)/2+ans*(n-ans);
	rep(i,MAX_A+1)
		ans+=(long long)cnt[i]*(cnt[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}