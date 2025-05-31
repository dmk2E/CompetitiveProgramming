/*�A���S���Y���ƍH�v�_(Swapping Puzzle/CPU: 33 ms  Memory: 6172 KB  Length: 1741 B)
�e��Ԃɑ΂��A�e�s�e��ɂ��đ�����s���A���ɐ�������Ă��Ȃ���ԂȂ�΁A�L���[�Ɋi�[����A���D��T���ŉ������B�����������Ԃ̐��́Ah!*w!�ł���A�ő�14400�Ƃ����܂ő����Ȃ����߁A�S�p�^�[���𐶐����I���āA��v���Ȃ���΁A�u-1�v���o��
������΂悢�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_H 5
#define MAX_W 5
using namespace std;

int h, w;

typedef struct data {
	int cnt, str[MAX_H * MAX_W];
	bool operator< (const data& d) const {
		int i;
		rep(i, h * w) {
			if (str[i] != d.str[i])
				return str[i] < d.str[i];
		}
		return false;
	}
}Data;

int b[MAX_H * MAX_W];
queue<Data> que;
map<Data, bool> v;

Data exchangeG(Data now,int r) {
	int j,temp;
	rep(j, w) {
		temp = now.str[w*r+j];
		now.str[w * r + j] = now.str[w * (r + 1) + j];
		now.str[w * (r + 1) + j] = temp;
	}
	return now;
}

Data exchangeL(Data now, int r) {
	int i, temp;
	rep(i, h) {
		temp = now.str[w * i + r];
		now.str[w * i + r] = now.str[w * i  + r + 1];
		now.str[w * i + r + 1] = temp;
	}
	return now;
}

bool judge(Data z) {
	int i;
	rep(i, h * w)
		if (z.str[i] != b[i])
			return false;
	return true;
}

int bfs(Data now) {
	int i, j;
	Data temp;
	que.push(now);
	v[now] = true;
	while (!que.empty()) {
		now = que.front(); que.pop();
		if (judge(now))
			return now.cnt;
		now.cnt++;
		rep(i, h-1) {
			if (v[temp = exchangeG(now, i)] == false) {
				v[temp] = true;
				que.push(temp);
			}
		}
		rep(i, w-1) {
			if (v[temp = exchangeL(now, i)] == false) {
				v[temp] = true;
				que.push(temp);
			}
		}
	}
	printf("%d\n",v.size());
	return -1;
}

void show(Data z) {
	int i, j;
	rep(i, h) {
		rep(j, w)
			printf("%2d ",z.str[i*w+j]);
		puts("");
	}
}

int main() {
	int i, j, tmp;
	Data now;
	scanf("%d%d", &h, &w);
	rep(i, h)
		rep(j, w) {
		scanf("%d", &now.str[i * w + j]);
	}
	rep(i, h)
		rep(j, w) {
		scanf("%d", &b[i * w + j]);
	}
	now.cnt = 0;
	printf("%d\n", bfs(now));
	return 0;
}