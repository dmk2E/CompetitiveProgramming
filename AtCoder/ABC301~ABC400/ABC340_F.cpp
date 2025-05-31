/*�A���S���Y���ƍH�v�_(F - S = 1/CPU: 1 ms  Memory: 3956 KB  Length: 763 B)
2�_(0,0),(X,Y)��ʂ钼��l��,y=(Y/X)x�ł��邩��AYx-Xy=0 �ƕ\����B����2�_���ӂƂ���O�p�`���l����ƁA����h�Ƃ��ď������A(1/2)*h*��(X^2+Y^2)=1 h=2/��(X^2+Y^2)-�@�ƂȂ�B�_(A,B)�ƒ���l�̋�����h�Ɠ������A�_�ƒ����̋����̌������A
h=|YA-XB|/��(X^2+Y^2) �ƂȂ�B������@�ɑ�����Đ�������ƁA|YA-XB|=2�𖞂����΂悭�A�g�����[�N���b�h�̌ݏ��@�ŉ�����B�ň��v�Z�ʂ�O(log2(min(A,B)))�ƂȂ�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

typedef long long ll;

ll x, y;

ll gcd(ll a, ll b) {
	return b==0?a:gcd(b, a % b);
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b > 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

int main() {
	ll a, b;
	bool flagX = false, flagY = false;
	scanf("%lld%lld", &x, &y);
	if (x < 0) {
		flagX = true;
		x = -x;
	}
	if (y < 0) {
		flagY = true;
		y = -y;
	}
	if (gcd(y,x)<=2){
		extgcd(y, x, a, b);
		if (flagX==false)
			b = -b;
		if (flagY)
			a = -a;
		a *= 2 / gcd(x, y);
		b *= 2 / gcd(x, y);
		printf("%lld %lld\n", a, b);
	}
	else
		puts("-1");
	return 0;
}