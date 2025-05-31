/*�A���S���Y���ƍH�v�_(Writing a Numeral/CPU: 72 ms  Memory: 8584 KB  Length: 591 B)
Q�̐������ÓI�m�ۂ����z��ƁAs��\���z���̓Y�����͈̔�[top,tail)�ŁAS��\�����A�e������s������S���\���l��MOD�Ŋ������]��sum���X�V���Ă����΂悢�B���̎��A�O�����Ƃ��āAmodTen[x]=(10^x)%MOD �ƂȂ�modTen��p�ӂ���
�����B�������邱�ƂŁA�u2�����Z�ł���a�E���E�ς̒l��MOD�Ŋ������]��v�́A�u2�̍��̒l���ꂼ����uMOD�Ŋ������]��v�Ƃ��Čv�Z�������ʁv�Ɠ��������Ƃ𗘗p���ĉ������Ƃ��ł���B
�ň��v�Z�ʂ� O(Q) �ƂȂ�A�\�������B
*/
#include <iostream>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_Q 600000
#define MOD 998244353
using namespace std;

int q,modTen[MAX_Q+1],s[MAX_Q+1],top=0,tail=0;

int main() {
	int i;
	long long sum=1;
	rep(i,MAX_Q+1){
		modTen[i]=(int)(sum%=MOD);
		sum*=10;
	}
	scanf("%d",&q);
	sum=1;
	s[tail++]=1;
	while(q--){
		scanf("%d",&i);
		if(i==1){
			scanf("%d",&i);
			s[tail++]=i;
			sum=(sum*10+i)%MOD;
		}else if(i==2){
			sum=(MOD+sum-((long long)s[top]*modTen[tail-top-1])%MOD)%MOD;//�������̍��́A�����s��2�̒l���ꂼ�ꂪMOD�Ŋ��������̂łȂ���΂Ȃ�Ȃ��B
			top++;
		}else{
			printf("%lld\n",sum);
		}
	}
	return 0;
}