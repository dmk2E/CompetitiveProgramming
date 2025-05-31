/*�A���S���Y���ƍH�v�_(Cleaning Robot/CPU: 520 ms  Memory: 3416 KB  Length: 4618 B)
�ŏ��͎n�_�Ƃ̋������ŏ��ƂȂ�_���珇�ɕ��D��T�����Ă����΂悢�ƍl�������A���̏��Ԃł͕K�����������S�ď����I���܂ł̑��������ŏ��ƂȂ�Ƃ͌���Ȃ��B���Ƃ����ĒP����dfs��bfs�ɂ��S�T�����ƁA���������
��Ԃ̐��������Ȃ�A�v�Z�ʂ̌��ς��肪����&������������Ȃ���������A�X�^�b�N�I�[�o�[�t���[�ɂȂ�\��������B
�]���āA�^����ꂽ�}�b�v�ɂ�����A����ƊJ�n�ʒu�𒸓_�Ƃ���d�ݕt���������S�O���t���쐬���A���̃O���t���dfs���s���A�ŒZ���������߂邱�ƂƂ���B���_�Ԃ̏d�݁A�܂�ŒZ�����̓}�b�v���bfs���s���ċ��߂�B
��Ƃ��āA���_1,���_2,���_3��2�_�����ԕӂ̑��������߂�B�܂����_1���Œ肵������2�ڂ̓_�̑I�ѕ����l����ƁA���_2,3��2�ʂ�ł���B���ɒ��_2���Œ肵�ē��l�ɍl���邪�A���̎��d���̕����������߁A���_1��2�ڂ�
���_�ɑI�Ԍ��̒�����폜����B���������1�ʂ肵���Ȃ��A�ӂ̑�����3�ƂȂ�B����𗘗p���āAbfs���s���x�A�����bfs�ŗp����}�b�v�ォ�獡���bfs�̎n�_���폜����悤�ɂ��邱�ƂŁA�d���Ȃ��A�אڍs��adj�̊e�l
�����߂邱�Ƃ��ł���B
�����Ŏn�_�𒸓_�ԍ�0�Ƃ��A����̒��_�ԍ���1���珇�Ԃɒ�߂Ă������ƂƂ����B���̎��A�}�b�v��̍��W���L�[�Ƃ��A���_�ԍ���ێ�����map�ŏ��������B
bfs�ɂ��אڍs��adj�̒l����ɂ́A�ň��v�Z��O(h*w)*O(h*w*4)<10^6�ƂȂ�A������O���t��ł�dfs�ɂ��ŒZ�����̑S�T���̍ň��v�Z�ʂ́A�O���t�̒��_�̐���2�{���x������AO(h*w*2)<10^3�ƂȂ�A�S�̂Ƃ��ď\��������
�Ȃ�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t){t=a,a=b,b=c}
#define MAX_H 20
#define MAX_W 20
#define MAX_A 400
#define NIL -1
using namespace std;

typedef pair<int, int> p;

typedef enum color {
	BLACK = -2,
	WHITE
}Color;

int w, h, adj[MAX_A][MAX_A];
char board[MAX_H][MAX_W], tmp[MAX_H][MAX_W];   //bfs���Ɏg���}�b�v����tmp,�����bfs���Ɏg���}�b�v����board�ɕێ����Ă����B
map<p, int> t;   //(���W,���_�ԍ�)

void copy(char a[][MAX_W], char b[][MAX_W]) {
	int i, j;
	rep(i, h)
		rep(j, w)
		a[i][j] = b[i][j];
}

void showBoard(char a[][MAX_W]) {
	int i, j;
	rep(i, h) {
		rep(j, w)
			printf("%c", a[i][j]);
		puts("");
	}
}

bool bfs(pair<pair<int, int>, int> start, int cnt) {
	pair<p, int> now;   //((���݂�y���W,���݂�x���W),���݂̑�����)�Ƃ��ĕێ��B
	p temp;
	queue<pair<p, int> > q;
	q.push(start);
	board[start.first.first][start.first.second] = '.';   //�Ăяo������bfs�̎n�_�ƂȂ������_�͏d�����Ȃ������߁A����Ăяo�����ł͂Ȃ����̂Ƃ��Ĉ����΂悢�B
	copy(tmp, board);
	tmp[start.first.first][start.first.second] = 'x';
	//showBoard(tmp);
	//puts("");
	while (!q.empty()) {
		now = q.front(); q.pop();
		if (now.first.first + 1 < h && tmp[now.first.first + 1][now.first.second] != 'x') {
			if (tmp[now.first.first + 1][now.first.second] == '*') {
				adj[t[start.first]][t[temp = make_pair(now.first.first + 1, now.first.second)]] = now.second + 1;
				adj[t[temp]][t[start.first]] = now.second + 1;
				cnt--;
			}
			tmp[now.first.first + 1][now.first.second] = 'x';
			q.push(make_pair(make_pair(now.first.first + 1, now.first.second), now.second + 1));
		}
		if (now.first.first - 1 >= 0 && tmp[now.first.first - 1][now.first.second] != 'x') {
			if (tmp[now.first.first - 1][now.first.second] == '*') {
				adj[t[start.first]][t[temp = make_pair(now.first.first - 1, now.first.second)]] = now.second + 1;
				adj[t[temp]][t[start.first]] = now.second + 1;
				cnt--;
			}
			tmp[now.first.first - 1][now.first.second] = 'x';
			q.push(make_pair(make_pair(now.first.first - 1, now.first.second), now.second + 1));
		}
		if (now.first.second + 1 < w && tmp[now.first.first][now.first.second + 1] != 'x') {
			if (tmp[now.first.first][now.first.second + 1] == '*') {
				adj[t[start.first]][t[temp = make_pair(now.first.first, now.first.second + 1)]] = now.second + 1;
				adj[t[temp]][t[start.first]] = now.second + 1;
				cnt--;
			}
			tmp[now.first.first][now.first.second + 1] = 'x';
			q.push(make_pair(make_pair(now.first.first, now.first.second + 1), now.second + 1));
		}
		if (now.first.second - 1 >= 0 && tmp[now.first.first][now.first.second - 1] != 'x') {
			if (tmp[now.first.first][now.first.second - 1] == '*') {
				adj[t[start.first]][t[temp = make_pair(now.first.first, now.first.second - 1)]] = now.second + 1;
				adj[t[temp]][t[start.first]] = now.second + 1;
				cnt--;
			}
			tmp[now.first.first][now.first.second - 1] = 'x';
			q.push(make_pair(make_pair(now.first.first, now.first.second - 1), now.second + 1));
		}
		if (cnt == 0)
			return true;
	}
	return false;
}

void showAdj(int max) {
	int i, j;
	rep(i, max) {
		rep(j, max)
			printf("%3d ", adj[i][j]);
		puts("");
	}
}

int dfs(int max) {
	int i, j = 0, cnt = 0, min = MAX_H * MAX_W + 1;
	p now;
	Color color[MAX_A];
	stack<p> s;   //(�ԍ��A����)�ŕێ��B
	rep(i, max)
		color[i] = WHITE;
	s.push(make_pair(0, 0));
	color[0] = BLACK;
	while (!s.empty()) {
		now = s.top();
		for (i = j; i < max; i++)
			if (color[i] == WHITE) {
				color[i] = BLACK;
				s.push(make_pair(i, now.second + adj[now.first][i]));
				//printf("%d %d\n", i, now.second + adj[now.first][i]);
				j = 0;
				break;
			}
		if (i == max) {
			if (s.size() == max && now.second < min) {
				min = now.second;
				//printf("min:%d\n", min);
			}
			j = now.first + 1;
			color[now.first] = WHITE;
			s.pop();
		}
	}
	return min;
}

int main() {
	int i, j, cnt, temp, sy, sx;
	bool flag;
	pair<pair<int, int>, int> z;
	map<pair<int, int>, int>::iterator it;
	while (1) {
		scanf("%d%d", &w, &h);
		if (!(h || w))
			break;
		cnt = 0;
		rep(i, h) {
			getchar();
			rep(j, w) {
				board[i][j] = getchar();
				if (board[i][j] == '*') {
					t[make_pair(i, j)] = cnt + 1;
					cnt++;
				}
				else if (board[i][j] == 'o') {
					t[make_pair(i, j)] = 0;
					sy = i; sx = j;
				}
			}
		}
		temp = cnt;   //����̐���ێ��B
//�J�n�ʒu���n�_�Ƃ���bfs������ɍs���Aadj[0][j]��adj[i][0]�̒l�𖄂߂�B
		flag = true;
		z.first.first = sy; z.first.second = sx; z.second = 0;
		if (!bfs(z, cnt))
			flag = false;
		else
			cnt--;
//���Ԃɉ���̍��W���n�_�Ƃ���bfs���s���A�c��̗אڍs��adj�̒l�𖄂߂�B
		for (it = t.begin(); flag && cnt > 0 && it != t.end(); it++) {
			if (sy == it->first.first && sx == it->first.second)
				continue;
			z.first = it->first;z.second = 0;
			if (!bfs(z, cnt))
				break;
			cnt--;
		}
		if (cnt == 0) {
			//showAdj(temp + 1);
			printf("%d\n", dfs(temp + 1));
		}
		else
			puts("-1");
		t.clear();
	}
	return 0;
}