/*�A���S���Y���ƍH�v�_(Break Number/CPU: 1 ms  Memory: 3888 KB  Length: 453 B)
���߂��X�́AX=2^x<=n �𖞂���x�̒l�̒��ōő�ƂȂ�x�̒l��p����2^x�ƕ\�������̂ƂȂ�B���������āA�J��Ԃ����@��power�֐���p�����A�w��x�̒l�񕪒T���ŉ�����B
�ň��v�Z�ʂ́AO(log2(log2(n))*log2(log2(n)))<10^2 �ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

int n;

int power(int x,int a){
	if(a==0)
		return 1;
	int temp=power(x*x,a/2);
	if(a%2==1)
		temp*=x;
	return temp;
}

int main() {
	int left,right,mid;
	scanf("%d",&n);
	left=1;right=10;
	while(left<right){
		mid=(left+right)/2;
		if(power(2,mid)<=n)
			left=mid+1;
		else
			right=mid;
	}
	printf("%d\n",power(2,left-1));
	return 0;
}