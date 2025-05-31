/*�A���S���Y���ƍH�v�_(���炮��/CPU: 0 ms  Memory: 3220 KB  Length: 4049 B)
�S�Ẵs�[�X�ɂ��ĊȈՐf�f�𖞂������ǂ������肷��B���̎��A�S�s�[�X����60*10=600�����ł��邠�邩��A�ň��v�Z�ʂ�600^2<10^6�ƂȂ�\�������B�]���ĊȈՐf�f�����邽�߂̃f�[�^���ȉ��̎菇�ō쐬���Ă����B
�@�������������قȂ�2�̃s�[�X�����肤��ꍇ���l�����邽�߁A�W�����͂��ꂽ��Ԃ�ێ�����char�^�z��temp���A���ꂼ��̃s�[�X�Ɉ�ӂɒ�܂�ԍ���t����int�^�z��mmap�ɕϊ�����B���̎��A'.'��NIL�Ƃ����B�ԍ��̕t
�����͗̈�̓h��Ԃ��Ɠ���������dfs�Ŏ��������B
�������ŁAmmap[i][j]�Ƀu���b�N�����݂���ꍇ�A���̃u���b�N���[�ƉE�[���ꂼ���x���W��j,j+1�ƂȂ邩��d�S��x���W��(j+j+1)/2=(2*j+1)/2�ƂȂ�B�]���ăs�[�X�̏d�S�́A�s�[�X���\������S�Ẵu���b�N�̏d�S�𑫂����킹��
�A�S�u���b�N���ł���4�����������̂ƂȂ�B
�����ŁA
p[x]:��ӂɒ�܂鎯�ʔԍ�x�����s�[�X��(xL,xR,xG)��ێ�����f�[�^�\���B
adj[x]:���ʔԍ���x�ł���s�[�X�����ځA�܂��͊ԐړI�Ɏx���Ă���s�[�X�̎��ʔԍ���ێ�����B
�Abfs���x�[�X�ɂ��Ċe�s�[�X��xL,xR,xG�����߂�Ɠ����ɁA�u���ʁv�ɐڂ��Ă���ʂ̃s�[�X��T�����Aadj�ɒǉ��B�z��p�͊�������B
�Bdfs�����ɂ��āAadj������������B
�Cp��adj�����Ɉ��̃s�[�X�ɑ΂��ĊȈՐf�f���s���Ĕ��肷��B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_W 10
#define MAX_H 60
#define MAX_P 600
#define NIL -1
#define NNIL (int)'#'
#define EPS (1e-10)
using namespace std;

typedef struct piece {
	int xL, xR;
	double xG;

	piece(int xxL=0,int xxR=0,double xxG=0):xL(xxL),xR(xxR),xG(xxG){}
}Piece;

int w, h, mmap[MAX_H][MAX_W], pp;
char temp[MAX_H][MAX_W + 1];
Piece p[MAX_P];

void coloring(int y, int x, char c) {   //dfs�Ŕԍ���U���Ă����B
	temp[y][x] = (char)NNIL;
	mmap[y][x] = pp;
	if (y + 1 < h && temp[y + 1][x] == c) {
		coloring(y + 1, x, c);
	}
	if (y - 1 >= 0 && temp[y - 1][x] == c) {
		coloring(y - 1, x, c);
	}
	if (x + 1 < w && temp[y][x + 1] == c) {
		coloring(y, x + 1, c);
	}
	if (x - 1 >= 0 && temp[y][x - 1] == c) {
		coloring(y, x - 1, c);
	}
}

void makeMap() {   //�@�̏���
	int i, j;
	rep(i, h) {
		rep(j, w) {
			if (temp[i][j] == (char)NNIL)
				continue;
			if (temp[i][j] == '.') {
				temp[i][j] = (char)NNIL;
				mmap[i][j] = NIL;
			}
			else {
				coloring(i, j, temp[i][j]);
				pp++;
			}
		}
	}
}

bool bfs(int y,int x,bool flag[MAX_H][MAX_W],vector<int> adj[MAX_P]) {
	int f = mmap[y][x], xMin = p[f].xL = MAX_W + 2, xMax = p[f].xR = -1, sum = 0;
	pair<int, int> now;
	bool ff=true,fff=false;
	queue<pair<int, int> > que;
	flag[y][x] = true;
	que.push(make_pair(y, x));
	while (que.size()) {
		now = que.front(); que.pop();
		sum += now.second * 2 + 1;
		if (now.first + 1 == h) {   //���ʂ��n�ʂɐڂ��Ă��鎞�̏���
			if (p[f].xL > now.second)
				p[f].xL = now.second;
			if (p[f].xR < now.second + 1)
				p[f].xR = now.second + 1;
			fff = true;
		}
		if (now.first + 1 < h && mmap[now.first + 1][now.second] != NIL && mmap[now.first + 1][now.second] != f) {//���ʂɕʂ̃s�[�X���ڂ��Ă��鎞�̏���
			if (p[f].xL > now.second)
				p[f].xL = now.second;
			if (p[f].xR < now.second + 1)
				p[f].xR = now.second + 1;
			if (ff) {
				adj[mmap[now.first + 1][now.second]].push_back(f);
				ff = false;
			}
		}
		if (now.first + 1 < h && mmap[now.first + 1][now.second] == f && flag[now.first + 1][now.second] == false) {
			flag[now.first + 1][now.second] = true;
			que.push(make_pair(now.first + 1, now.second));
		}
		if (now.first - 1 >= 0 && mmap[now.first - 1][now.second] == f && flag[now.first - 1][now.second] == false) {
			flag[now.first - 1][now.second] = true;
			que.push(make_pair(now.first - 1, now.second));
		}
		if (now.second + 1 < w && mmap[now.first][now.second + 1] == f && flag[now.first][now.second + 1] == false) {
			flag[now.first][now.second + 1] = true;
			que.push(make_pair(now.first, now.second + 1));
		}
		if (now.second - 1 >= 0 && mmap[now.first][now.second - 1] == f && flag[now.first][now.second - 1] == false) {
			flag[now.first][now.second - 1] = true;
			que.push(make_pair(now.first, now.second - 1));
		}
	}
	p[f].xG = (double)sum / 8;
	return true;
}

void showMap() {
	int i, j;
	rep(i, h) {
		rep(j, w)
			printf("%3d", mmap[i][j]);
		puts("");
	}
}

void makeAdj(vector<int>& now, int nnow, vector<int> adj[MAX_P], bool flag[MAX_P]) {
	int i;
	for (int x : adj[nnow]) {
		if (flag[x] == false) {
			flag[x] = true;
			now.push_back(x);
			makeAdj(now, x, adj, flag);
		}
	}
}

bool judge() {
	int i, j;
	double temp;
	bool flag[MAX_H][MAX_W] = { 0 };
	vector<int> adj[MAX_P];
	//showMap();
	rep(i, h) {   //�A�̏���
		rep(j, w) {
			if (flag[i][j] == false) {
				if (mmap[i][j] == NIL)
					flag[i][j] = true;
				else {
					if (bfs(i, j, flag, adj) == false)
						return false;
				}
			}
		}
	}
	rep(i, pp) {   //�B�̏���
		bool fflag[MAX_P] = { 0 };
		fflag[i] = true;
		vector<int> v;
		for (int x : adj[i]) {
			fflag[x] = true;
			makeAdj(v, x, adj, fflag);
		}
		for (int x : v)
			adj[i].push_back(x);
	}
	/*
	rep(i, pp) {	//��������肭�����Ă��邩�̃f�o�b�N�o��
		printf("%d(%d,%d,%f):", i, p[i].xL, p[i].xR, p[i].xG);
		for (int x : adj[i])
			printf("->%d", x);
		puts("");
	}
	*/
	rep(i, pp) {   //�C�̏���
		temp = p[i].xG;
		for (int x : adj[i]) {
			temp += p[x].xG;
		}
		temp /= (adj[i].size() + 1);
		if (fabs(p[i].xL - temp) < EPS || fabs(p[i].xR - temp) < EPS || p[i].xL > temp || temp > p[i].xR)
			return false;
	}
	return true;
}

int main() {
	int i, j;
	while (1) {
		scanf("%d%d", &w, &h);
		if (!(w || h))
			break;
		pp = 0;
		rep(i, h)
			scanf("%s", temp[i]);
		makeMap();

		if (judge())
			puts("STABLE");
		else
			puts("UNSTABLE");
	}
	return 0;
}