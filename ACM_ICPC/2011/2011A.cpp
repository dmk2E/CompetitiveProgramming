/*�A���S���Y���ƍH�v�_(�`�F�r�V�F�t�̒藝/CPU: 0 ms  Memory: 3956 KB  Length: 817 B)
�ŏ��ɃG���g�X�e�l�X��⿂ŕK�v�ȑf����S�񋓂��A�z��prime�����ɕێ����Ă����B���̑O�����̍ň��v�Z�ʂ�O(MAX_N*log2(log2(MAX_N)))<10^7 �ƂȂ�A�����B
�e����n�ɑ΂��āAn�ȉ��ōŏ��̑f�����i�[����Ă���prime��̓Y����s,2*n���傫���f���ōŏ��̑f�����i�[����Ă���prime��̓Y����e�̂��ꂼ���񕪒T���ŋ��߁A�ue-s�v���o�͂���΂悢�B
��̃f�[�^�Z�b�g�ɑ΂��邱�̏����̍ň��v�Z�ʂ́AO(log2(n))<10^2 �ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 123456
using namespace std;

int n;
bool isPrime[2*MAX_N+1];
vector<int> prime;

void init(){
	int i,j;
	rep(i,2*MAX_N+1)
		isPrime[i]=true;
	isPrime[0]=isPrime[1]=false;
	for(i=2;i<2*MAX_N+1;i++){
		if(isPrime[i]){
			prime.push_back(i);
			j=2*i;
			while(j<2*MAX_N+1){
				isPrime[j]=false;
				j+=i;
			}
		}
	}
}

int main() {
	int left,right,mid,s;
	init();
	while(1){
		scanf("%d",&n);
		if(!n)
			break;
		left=0;right=prime.size();
		while(left<right){
			mid=(left+right)/2;
			if(prime[mid]<=n)
				left=mid+1;
			else
				right=mid;
		}
		s=left;
		left=0;right=prime.size();
		while(left<right){
			mid=(left+right)/2;
			if(prime[mid]<=2*n)
				left=mid+1;
			else
				right=mid;
		}
		printf("%d\n",left-s);
	}
	return 0;
}