/*�A���S���Y���ƍH�v�_(M<=ab/CPU: 5 ms  Memory: 3900 KB  Length: 403 B)
a���Œ肵�čl�����Ƃ��Ab=(M/a�̐؂�グ)�ƂȂ�b�̒l����ӂɒ�܂�B�����ŁA�ua<=b�v�Ƃ����召�֌W��t�����Ă���ʐ�������Ȃ��Ƃ����A�������ł��Ȃ��݂̎�@��p����ƁA
a<=b=(M/a�̐؂�グ)<M/a+1 �ƂȂ莮�ό`���s���āAa^2-a-M<0 ����āAa����M �ƂȂ�B���������āA���̂悤��a�̒l���ׂĂɑ΂���������߂�΂悢�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

long long n,m;

int main() {
	int a,max;
	long long b,min;
	scanf("%lld%lld",&n,&m);
	max=(int)sqrt(m)+1;
	for(a=1,min=LLONG_MAX;a<=max;a++){
		if(a>n)
			break;
		if(m%a==0)
			b=m/a;
		else
			b=m/a+1;
		if(b<=n&&a*b<min)
			min=a*b;
	}
	printf("%lld\n",min==LLONG_MAX?-1:min);
	return 0;
}