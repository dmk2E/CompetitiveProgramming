/*�A���S���Y���ƍH�v�_(Ohgas' Fortune/CPU: 0 ms  Memory: 3172 KB  Length: 787 B)
���͓ǉ��Ń��[����c�����āA���̃��[���ɏ]���ăV�~�����[�V��������΂����B
�ň��v�Z�ʂ́AO(m*n*year)=10^5 ���\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t) t=a,a=b,b=t
using namespace std;

int m,year,money,flag,n,tesu;
double ritu;

int fukuri(int money) {
	int i;
	rep(i, year) 
		money += (int)(money * ritu) - tesu;
	return money;
}

int tanri(int money) {
	int i, risi=0;
	rep(i, year) {
		risi += (int)(money * ritu);
		money -= tesu;
	}
	return money+risi;
}

int main() {
	int max,temp;
	scanf_s("%d",&m);
	//scanf("%d", &m);   //���ۂɋ��v���̃R���e�X�g�Œ�o����Ƃ��͂�����
	while (m--) {
		scanf_s("%d%d%d",&money,&year,&n);
		//scanf("%d%d%d", &money, &year, &n);
		max = money;
		while (n--) {
			scanf_s("%d%lf%d",&flag,&ritu,&tesu);
			//scanf("%d%lf%d", &flag, &ritu, &tesu);
			temp = flag ? fukuri(money) :tanri(money) ;
			if (temp > max)
				max = temp;
		}
		printf("%d\n",max);
	}
	return 0;
}