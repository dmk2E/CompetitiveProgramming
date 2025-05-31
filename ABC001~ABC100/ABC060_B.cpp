/*�A���S���Y���ƍH�v�_(Choose Integers/CPU: 1 ms  Memory: 3900 KB  Length: 390 B)
a*k=b*q+c ���Aa*k-b*q=c�Ƃ����񌳈ꎟ�s��������̉������݂��邩�𔻒肷��΂悢�Ba��b���݂��ɑf�Ȃ�m���ɉ������B�݂��ɑf�łȂ��ꍇ�A
gcd(a,b)*(aa*k-bb*q)=c�Ƃ����`�ɕό`�ł��邩��Ac��gcd(a,b)�̔{���Ȃ�������B���R�́Aaa��bb�݂͌��ɑf�ł��邽�߁Aaa*k-bb*q=1�̉��͕K�����݂��邩��Aaa*k-bb*q=c/gcd(a,b) �̉����K����͑��݂���
����B�ň��v�Z�ʂ�O(log2(max(a,b)))�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

int a, b, c;

int gcd(int a,int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int tmp;
	scanf("%d%d%d",&a,&b,&c);
	tmp = gcd(gcd(a, b), c);
	a /= tmp; b /= tmp; c /= tmp;
	if ((tmp = gcd(a, b)) == 1 || c % tmp == 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}