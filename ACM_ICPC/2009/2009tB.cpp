/*�A���S���Y���ƍH�v�_(Matsuzaki Number/CPU: 860 ms  Memory: 5400 KB  Length: 1202 B)
�G���g�X�e�l�X��⿂̃A���S���Y���ŁA���炩���ߎg���\��������10^6�ȉ��̑f����S�񋓂��Ă����A���������m(n,p)���v�Z����Bp�̍ő�l��100�ł��邩��An���傫���f��������������500�قǎ��o���A���̒���2����
�a��S�񋓂��āAp�Ԗڂ̒l��m(n,p)�Ƃ����B�u500�v�Ƃ����l�͖ڈ��ł���B�f���̑S�񋓂͍ŏ���1�񂾂��s���΂悢���߁A���̏������������ň��v�Z�ʂ́AO(log2(MAX_PRIME)+RANGE^2*log2(RANGE^2)+p)=O(RANGE^2)�ƂȂ�B����
��RANGE=500�Ƃ������A�v�Z�ʓI�ɂ�RANGE=10^3�Ƃ��Ă��AO(RANGE^2)=10^6 �ƂȂ邽�߁A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_PRIME 1000000
#define RANGE 500
using namespace std;

int n, p;
vector<int> prime;

void createPrime() {   //�񋓂���f���̌���10^5�����ƂȂ�B
	int i, j;
	bool isPrime[MAX_PRIME + 1];
	rep(i, MAX_PRIME + 1)
		isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for (i = 2; i < MAX_PRIME + 1; i++) {
		if (isPrime[i]) {
			for (j = i + i; j < MAX_PRIME + 1; j += i)
				isPrime[j] = false;
		}
	}
	rep(i, MAX_PRIME + 1)
		if (isPrime[i])
			prime.push_back(i);
}

int searchPrime(int nn) {   //�����lnn���傫���l�̒��̍ŏ��l���i�[���Ă���prime��̓Y������񕪒T��
	int left = 0, mid, right = prime.size();
	while (left < right) {
		mid = (left + right) / 2;
		if (prime[mid] > nn)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int m(int n,int p) {   //p�̒l���ő�100������AsearchPrime(n)�`searchPrime(n)+500�܂ł�2�̑f���̘a��S�񋓂���p�Ԗڂ�Ԃ��悤�ɂ����error�͂Ȃ��Ɖ��肷��B
	int i, j, max;
	priority_queue<int> PQ;
	n = searchPrime(n);
	max = n + RANGE > prime.size() ? prime.size() : n + RANGE;
	for (i = n; i < max; i++)
		for (j = i + 1; j < max; j++)
			PQ.push(-(prime[i] + prime[j]));
	for (i = n; i < max; i++)
		PQ.push(-prime[i] * 2);
	rep(i, p - 1)
		PQ.pop();
	return -PQ.top();
}

int main() {
	int i;
	createPrime();
	while (1) {
		scanf("%d%d", &n, &p);
		if (n == -1 && p == -1)
			break;
		printf("%d\n", m(n, p));
	}
	return 0;
}