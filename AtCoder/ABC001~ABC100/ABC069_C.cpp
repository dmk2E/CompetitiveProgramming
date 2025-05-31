/*�A���S���Y���ƍH�v�_(4-adjacent/CPU: 12 ms  Memory: 3928 KB  Length: 1130 B)
���鐮����f�������������Ƃ��A2^x�̍��ɂ����āAx=0�̐�Odd,x=1�̐�Two,x>=2�̐�Four�Ƃ��āA���ꂼ��̒l��O(N)�ŋ��߂�B1<=i<=N-1 �ɂ����āAa(i)��a(i+1)�̐ς�4�̔{���ɂȂ邽�߂ɂ́A(Odd,Four),(Two,Two),(Two,Four),
(Four,Four)�̑g�ݍ��킹�ƂȂ�悤�ɔz��a����ёւ���K�v������B���������āAOdd,Two,Four���ꂼ��̐������炩���ߐ����Ēu���A�z��a�̐擪��������𖞂����悤�ɐ�����u���Ă����Ba(i)��u���Ƃ��Aa(i-1)�̒l�ɂ���Ēu��
�����̗D��x����ӂɒ�܂邱�Ƃɒ���(�×~�@)�B���̃V�~�����[�V������O(N)�ōs����B���������āA�S�̂̍ň��v�Z�ʂ� O(N)=10^5 �ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

typedef enum state{
	ALL=0,
	EVEN,
	FOUR,
	IMPOSSIBLE
}State;

int n,cntOdd,cnt2,cnt4;

int main() {
	int i,j;
	State now=ALL;
	scanf("%d",&n);
	cntOdd=cnt2=cnt4=0;
	rep(i,n){
		scanf("%d",&j);
		if(j%4==0)
			cnt4++;
		else{
			if(j%2==0)
				cnt2++;
			else
				cntOdd++;
		}
	}
	while(n--){
		//printf("now:%d\n",now);
		//printf("odd:%d even:%d four:%d\n",cntOdd,cnt2,cnt4);
		if(now==IMPOSSIBLE)
			break;
		switch(now){
			case ALL:
				if(cntOdd){
					cntOdd--;
					now=FOUR;
				}else if(cnt2){
					cnt2--;
					now=EVEN;
				}else{
					cnt4--;
					now=ALL;
				}
				//printf("%d\n",ALL);
				break;
			case EVEN:
				if(cnt2){
					cnt2--;
					now=EVEN;
				}else if(cnt4){
					cnt4--;
					now=ALL;
				}else
					now=IMPOSSIBLE;
				//printf("%d\n",EVEN);
				break;
			default:
				if(cnt4){
					cnt4--;
					now=ALL;
				}else
					now=IMPOSSIBLE;
				//printf("%d\n",FOUR);
				break;
		}
	}
	printf("%s\n",now==IMPOSSIBLE?"No":"Yes");
	return 0;
}