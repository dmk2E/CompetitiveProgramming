/*�A���S���Y���ƍH�v�_(�R�o��/CPU: 20 ms  Memory: 3608 KB  Length: 3990 B)
�R�̊e�u���b�N��ߓ_�Ƃ��A���̐ߓ_�Ɉړ�����̂ɂ����鎞�Ԃ��d�݂Ƃ��閳���d�ݕt���O���t�ɂ����āA�_�C�N�X�g���@�����ɂ����T���ōŏ����Ԃ����߂�B
�X�^�[�g�ʒu����������ꍇ�A�S�Ă܂Ƃ߂Ĉ�̐ߓ_�Ƃ݂Ȃ��B����u���b�N�ɓ��B�������A���B�������̑��������Ȃ�A���B���Ԃ��ŒZ�ł��鎞�A����ȍ~���̃}�X�ɓ��B���鎞�Ԃ��ŒZ�ɂȂ�B�]���āA�ߓ_�͍���ver�ƉE��ver�̓��
�p�ӂ��A���ꂼ��̐ߓ_�́A���ꂪ�\���u���b�N����̃}���n�b�^��������3�ȉ��ɂȂ�u���b�N��\���ߓ_�ɂ̂݁A�ړ����Ԃ��d�݂Ƃ���ӂ�L�΂��Ă���ƍl���A���̃O���t�ɂ�����_�C�N�X�g���@�ŉ�����B
�ň��v�Z�ʂ� O((2*h*w+2*h*w*9)log2(2*h*w+2*h*w*9))<10^6 �ƂȂ�A�\�������B

*if���̒��g�͓���q�̕����܂߂�2���ȏ�ɂȂ�Ȃ�A{}�����ނ��ƁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_W 30
#define MAX_H 60
#define MAX_D 9
#define GOAL 0
#define INF -1   //�X�^�[�g�ʒu�Ƒ����u���Ȃ���
#define LEFT true
#define RIGHT false
#define WHITE 1
#define BLACK 0
using namespace std;

typedef struct point {
	int y, x;

	point(int yy = 0, int xx = 0) {
		y = yy;
		x = xx;
	}

	bool operator< (const point& k) const {
		return x == k.x ? y < k.y : x < k.x;
	}
}Point;

typedef struct data {
	Point now;
	int cost;   //���܂łɂ�����������
	bool f;   //now�ɂ��Ă��鑫�������Ȃ�u1�v,�E���Ȃ�u0�v

	data(Point p=point(0,0), int ccost=-1, bool ff=true) {
		now = p;
		cost = ccost;
		f = ff;
	}

	bool operator< (const data& k) const {
		return cost < k.cost;
	}
}Data;

int w, h, mmap[MAX_H][MAX_W], dy[MAX_D] = {0,1,-1,2,-2,0,1,-1,0}, dx[MAX_D] = {1,1,1,1,1,2,2,2,3};//�E���Ői��ver�������ɕێ�
bool colorL[MAX_H][MAX_W], colorR[MAX_H][MAX_W];
stack<Point> start;   //�X�^�[�g�ʒu�̍��W��ێ����Ă����B

int dijk() {
	int i, j;
	Point tmp;
	map<Data, bool> a;
	Data now, temp;
	priority_queue<Data> PQ;
	while (start.size()) {
		tmp = start.top(); start.pop();
		rep(i, MAX_D) {
			if (tmp.y + dy[i] >= 0 && tmp.y + dy[i] < h && tmp.x + dx[i] >= 0 && tmp.x + dx[i] < w && mmap[tmp.y + dy[i]][tmp.x + dx[i]] != INF)
				PQ.push(Data(Point(tmp.y + dy[i], tmp.x + dx[i]), -mmap[tmp.y + dy[i]][tmp.x + dx[i]], RIGHT));   //�����Ŏ��o����������R�X�g�ɂ͕��̐������Ă����B
			if (tmp.y - dy[i] >= 0 && tmp.y - dy[i] < h && tmp.x - dx[i] >= 0 && tmp.x - dx[i] < w && mmap[tmp.y - dy[i]][tmp.x - dx[i]] != INF) 
				PQ.push(Data(Point(tmp.y - dy[i], tmp.x - dx[i]), -mmap[tmp.y - dy[i]][tmp.x - dx[i]], LEFT));
		}
	}
	while (PQ.size()) {
		do {
			now = PQ.top(); PQ.pop();
			if ((now.f == LEFT && colorL[now.now.y][now.now.x] == WHITE) || (now.f == RIGHT && colorR[now.now.y][now.now.x] == WHITE))
				break;
		} while (PQ.size());
		if ((now.f == LEFT && colorL[now.now.y][now.now.x] == WHITE))
			colorL[now.now.y][now.now.x] = BLACK;
		else if (now.f == RIGHT && colorR[now.now.y][now.now.x] == WHITE)
			colorR[now.now.y][now.now.x] = BLACK;
		else
			break;
		//printf("Now:(%d,%d)%d :%c\n", now.now.y, now.now.x,-now.cost, now.f == LEFT ? 'L' : 'R');
		if (mmap[now.now.y][now.now.x] == GOAL)
			return -now.cost;
		if (now.f == LEFT) {
			rep(i, MAX_D)
				if (now.now.y + dy[i] >= 0 && now.now.y + dy[i] < h && now.now.x + dx[i] >= 0 && now.now.x + dx[i] < w && mmap[now.now.y + dy[i]][now.now.x + dx[i]] != INF && colorR[now.now.y + dy[i]][now.now.x + dx[i]] == WHITE) {
					temp = now;
					temp.now.y += dy[i]; temp.now.x += dx[i]; temp.f = RIGHT; temp.cost -= mmap[temp.now.y][temp.now.x];
					//printf("New!(%d,%d)%d :%c\n", temp.now.y, temp.now.x, -temp.cost, temp.f == LEFT ? 'L' : 'R');
					PQ.push(temp);
				}
		}
		else {
			rep(i, MAX_D)
				if (now.now.y - dy[i] >= 0 && now.now.y - dy[i] < h && now.now.x - dx[i] >= 0 && now.now.x - dx[i] < w && mmap[now.now.y - dy[i]][now.now.x - dx[i]] != INF && colorL[now.now.y - dy[i]][now.now.x - dx[i]] == WHITE) {
					temp = now;
					temp.now.y -= dy[i]; temp.now.x -= dx[i]; temp.f = LEFT; temp.cost -= mmap[temp.now.y][temp.now.x];
					//printf("New!(%d,%d)%d :%c\n", temp.now.y, temp.now.x, -temp.cost, temp.f == LEFT ? 'L' : 'R');
					PQ.push(temp);
				}
		}
	}
	return -1;
}

int main() {
	int i, j;
	char c;
	while (1) {
		scanf("%d%d", &w, &h);
		if (!(w || h))
			break;
		getchar();
		rep(i, h) {
			rep(j, w) {
				colorL[i][j] = colorR[i][j] = WHITE;
				if ((int)'0' <= (int)(c = getchar()) && (int)c <= (int)'9')
					mmap[i][j] = (int)c - (int)'0';
				else if (c == 'X')
					mmap[i][j] = INF;
				else if (c == 'T')
					mmap[i][j] = GOAL;
				else {
					mmap[i][j] = INF;
					start.push(Point(i, j));
					colorL[i][j] = colorR[i][j] = BLACK;
				}
				getchar();
			}
		}
		printf("%d\n",dijk());
	}
	return 0;
}