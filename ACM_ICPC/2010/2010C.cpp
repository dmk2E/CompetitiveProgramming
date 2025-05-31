/*�A���S���Y���ƍH�v�_(�|���b�N�\�z/CPU: 250 ms  Memory: 13304 KB  Length: 1345 B)
solved[i]:����i�𐳎l�ʑ̐��̘a�Ƃ��ĕ\�����߂ɕK�v�Ȑ��l�ʑ̐��̌��̍ŏ��l solvedOdd[i]:����i����̐��l�ʑ̐��̘a�Ƃ��ĕ\�����߂ɕK�v�Ȋ�̐��l�ʑ̐��̌��̍ŏ��l �Ƃ��A���炩���ߔz��solved��
�z��solveOdd���쐬���Ă����A���͒lx�ɑ΂��āAsolved[x]��solvedOdd[x]�̒l���o�͂���B
solved�̍쐬���@:1�`1000000(=MAX_N)�܂ł̐����lx�𒸓_�Ƃ��A���ꂼ��̒��_x���� y=x+polk[i] �𖞂��������ly�̒��_�֕ӂ�L�΂����L���d�ݖ����O���t�ɂ����ĕ��D��T��(bfs)���s���A�ŏ��������߁A�쐬����B
solveOdd�̍쐬���@:polk[i]����ł�����̂̂ݎg���ȊO�A�z��solved�̍쐬���@�Ɠ����B
solved,solvedOdd���ꂼ��̍쐬���@�̍ň��v�Z�ʂ́AO(MAX_N*(�z��polk�̗v�f��))��10^6*10^2=10^8 �ƂȂ邪�A�|���b�N�\�z�ł͍ŏ����͍ő�ł�5�ƂȂ邽�߁A���ۂ̌v�Z�ʂ͂����Ə������Ȃ�ƍl������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 1000000
#define MAX_P 200
#define NIL 0
using namespace std;

int n, solved[MAX_N + 1] = { 0 }, solvedOdd[MAX_N + 1] = { 0 }, polk[MAX_P], p = 0;//polk[i]=(i+1)*(i+2)*(i+3)/6

void bfs() {
	int i, cnt = p, now;
	queue<int> que;
	rep(i, p) {
		que.push(polk[i]);
		solved[polk[i]] = 1;
	}
	while (que.size()) {
		now = que.front(); que.pop();
		rep(i, p) {
			if (now + polk[i] > MAX_N)
				break;
			if (solved[now + polk[i]] == NIL) {
				cnt++;
				que.push(now + polk[i]);
				solved[now + polk[i]] = solved[now] + 1;
			}
		}
		if (cnt == MAX_N)
			break;
	}
}

void bfsOdd() {
	int i, cnt = 0, now;
	queue<int> que;
	rep(i, p) {
		if (polk[i] % 2 == 1) {
			cnt++;
			que.push(polk[i]);
			solvedOdd[polk[i]] = 1;
		}
	}
	while (que.size()) {
		now = que.front(); que.pop();
		rep(i, p) {
			if (polk[i] % 2 == 1) {
				if (now + polk[i] > MAX_N)
					break;
				if (solvedOdd[now + polk[i]] == NIL) {
					cnt++;
					que.push(now + polk[i]);
					solvedOdd[now + polk[i]] = solvedOdd[now] + 1;
				}
			}
		}
		if (cnt == MAX_N)
			break;
	}
}

int main() {
	int i, j;
	i = 1;
	while ((j = i * (i + 1) * (i + 2) / 6) <= MAX_N) {
		polk[p++] = j;
		i++;
	}
	bfs();
	bfsOdd();
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		printf("%d %d\n", solved[n], solvedOdd[n]);
	}
	return 0;
}