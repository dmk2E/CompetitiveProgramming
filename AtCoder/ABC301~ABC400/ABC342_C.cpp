/*�A���S���Y���ƍH�v�_(Many Replacement/CPU: 18 ms  Memory: 4576 KB  Length: 635 B)
'a'~'z'���ꂼ���0~25�̔ԍ������蓖�Ă�B����c�ɑ΂��邱�̔ԍ���num(c)�Ƃ���Balfa[i]:����i�����݂��镶����s��̓Y���� aalfa[i]:�ԍ�i�̕������u������镶���̔ԍ� �Ƃ��A�N�G���ŕ���c�A�𕶎�d�ɒu����
����x��aalfa[i]=num(c)�ƂȂ邷�ׂĂ�aalfa[i]�̒l��num(d)�ɏ���������B�Ō��alfa��aalfa�̏������ɍŏI�I�ȕ�����s���쐬���A�o�͂���B�ň��v�Z�ʂ�O(n+MAX_ALFA*q)<10^7�ƂȂ荂���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_ALFA 26
using namespace std;

int n,q,aalfa[MAX_ALFA];
char c,d;
vector<int> alfa[MAX_ALFA];
string s;

int main() {
	int i,j;
	scanf("%d",&n);
	cin>>s;
	rep(i,MAX_ALFA)
		aalfa[i]=i;
	rep(i,s.length())
		alfa[(int)s[i]-(int)'a'].push_back(i);
	scanf("%d",&q);
	while(q--){
		getchar();
		scanf("%c %c",&c,&d);
		rep(i,MAX_ALFA){
			if(aalfa[i]==(int)c-(int)'a')
				aalfa[i]=(int)d-(int)'a';
		}
	}
	rep(i,MAX_ALFA){
		rep(j,alfa[i].size()){
			s[alfa[i][j]]=(char)((int)'a'+aalfa[i]);
		}
	}
	cout <<s<<endl;
	return 0;
}