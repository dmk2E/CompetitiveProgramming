/*�A���S���Y���ƍH�v�_(Dirichlet's Theorem on Arithmetic Progressions/CPU: 0 ms  Memory: 4084 KB  Length: 604 B)
�G���g�X�e�l�X��⿂�10^6�܂ł̒l�̑f��������s����z��isPrime���쐬����B���̌�A�^�����铙������̒l��������Ă����A�f���ɂȂ����񐔂�ϐ�cnt�ɕێ����Ă����Acnt==n�ƂȂ������̒l���o�͂���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_PRIME 1000000
using namespace std;

int a, d, n;
bool isPrime[MAX_PRIME+1];

void erato() {
	int i, j;
	rep(i, MAX_PRIME + 1)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	rep(i, MAX_PRIME + 1) {
		if (isPrime[i]) {
			j = i*2;
			while (j < MAX_PRIME + 1) {
				isPrime[j] = false;
				j += i;
			}
		}
	}
}

int main() {
	int cnt = 0;
	erato();
	while (1){
		cin >> a >> d >> n;
		if (!(a || d || n))
			break;
		cnt = 0;
		while (cnt<n) {
			if (isPrime[a])
				cnt++;
			a += d;
		}
		printf("%d\n",a-d);
	}
	return 0;
}