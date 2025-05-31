/*�A���S���Y���ƍH�v�_(����낿��냍�{�b�g/CPU: 0 ms  Memory: 3684 KB  Length: 1886 B)
���̃}�X�ɓ��B�������Ɍ����Ă�������͓�����k��4�p�^�[�����݂��邩��A�S�Ẵ}�X�ɂ��āA4���������_���쐬���A�����𖞂����悤�Ƀ_�C�N�X�g���@���s���΂悢�B
�ň��v�Z�ʂ́AO((h*w+h*w*4)*log2(h*w+h*w*4))<10^5 �ƂȂ�\�������B
*�u�R�o��v�Ɣ�ׂ��炱�����̕������G�H�_�C�N�X�g���@�����ɁA�F��ȍH�v�ō������ł���ǖ₾�����Ǝv���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_D 4
#define MAX_H 30
#define MAX_W 30
using namespace std;

typedef struct data {
	int y, x, cost, now;
	
	data(int yy=0, int xx=0, int ccost=0, int nnow=0) {
		y = yy;x = xx;cost = ccost;now = nnow;
	}

	bool operator<(const data& k) const {
		return cost < k.cost;
	}
}Data;

int dx[MAX_D] = { 1,0,-1,0 }, dy[MAX_D] = { 0,1,0,-1}, h, w, mmap[MAX_H][MAX_W], cost[MAX_D];   //�ړ���dy,dx�ɂ����ēY�����́A����:0 �쁫:1 ����:2 �k��:3 cost�ɂ����ēY�����́A0:���i 1:�E�� 2:���] 3:���� ���Ӗ�����B

int dijk() {
	int i;
	Data now,temp;
	priority_queue<Data> PQ;
	bool mapF[MAX_D][MAX_H][MAX_W] = {0};   //�K��ς�:true ���K��:false �Ƃ��Ċe�ߓ_��ێ�
	PQ.push(Data(0, 0, 0, 0));
	while (PQ.size()) {
		do {
			now = PQ.top(); PQ.pop();
		} while (PQ.size() && mapF[now.now][now.y][now.x]);
		//printf("Now:(%d,%d) cost:%d now:%d\n", now.y, now.x, -now.cost, now.now);
		if (now.y == h - 1 && now.x == w - 1)
			return -now.cost;
		if (mapF[now.now][now.y][now.x])
			break;
		else
			mapF[now.now][now.y][now.x] = true;
		rep(i, MAX_D) {//(now+i)%MAX_D:���� cost[i]:������R�X�g
			if (now.y + dy[(now.now + i) % MAX_D] >= 0 && now.y + dy[(now.now + i) % MAX_D] < h && now.x + dx[(now.now + i) % MAX_D] >= 0 && now.x + dx[(now.now + i) % MAX_D] < w&&mapF[(now.now + i) % MAX_D][now.y + dy[(now.now + i) % MAX_D]][now.x + dx[(now.now + i) % MAX_D]]==false) {
				if (mmap[now.y][now.x] == i)
					PQ.push(temp=Data(now.y + dy[(now.now + i) % MAX_D], now.x + dx[(now.now + i) % MAX_D], now.cost, (now.now + i) % MAX_D));
				else
					PQ.push(temp=Data(now.y + dy[(now.now + i) % MAX_D], now.x + dx[(now.now + i) % MAX_D], now.cost - cost[i], (now.now + i) % MAX_D));
				//printf("New:(%d,%d) cost:%d now:%d\n", temp.y, temp.x, -temp.cost, temp.now);
			}
		}
	}
	return -1;
}

int main() {
	int i, j;
	while (1) {
		scanf("%d%d", &w, &h);
		if (!(w || h))
			break;
		rep(i, h)
			rep(j, w)
				scanf("%d", &mmap[i][j]);
		scanf("%d%d%d%d", &cost[0], &cost[1], &cost[2], &cost[3]);
		printf("%d\n", dijk());
	}
	return 0;
}