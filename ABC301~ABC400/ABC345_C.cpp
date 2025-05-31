/*�A���S���Y���ƍH�v�_(One Time Swap/CPU: 14 ms  Memory: 5324 KB  Length: 482 B)
�p�����������o�ꂵ�Ȃ�->�p���������ꂼ��ɂ��ĕK�v�ȏ���ێ����āA���𓱂��o���B�Ƃ�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_ALFA 26
using namespace std;

int cntAlfa[MAX_ALFA]={0};
string s;

int main() {
	int i,j;
	long long ans;
	cin>>s;
	rep(i,s.length())
		cntAlfa[(int)s[i]-(int)'a']++;
	ans=0;
	rep(i,MAX_ALFA){
		if(cntAlfa[i]>1)
			break;
	}
	if(i<MAX_ALFA)
		ans++;
	rep(i,MAX_ALFA){
		for(j=i+1;j<MAX_ALFA;j++)
			ans+=(long long)cntAlfa[i]*cntAlfa[j];
	}
	printf("%lld\n",ans);
	return 0;
}