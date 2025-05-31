/*�A���S���Y���ƍH�v�_(Polyomino Mining/CPU:  ms  Memory:  KB  Length:  B)
N^2-1�񐔂����N�G������v(i,j)�̗ݐϘa�̕\���쐬���A����������c�̖����ʂ�1�ȏ�ƂȂ��Ă�����W��\�����A���̈��̍��W�ɂ��Ė����ʂ��N�G�����Ammap�ɋL�^���Ă����B
���̌�A�����ʂ�1�ȏ゠����W���n�_�Ƃ���bfs���s���A�����ʂ��N�G�����A�T������B���̎��A�����ʂ��������W���珇��bfs���s���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 20
#define MAX_M 20
#define MAX_D 4
#define NIL -1
#define EPS (1e-10)
using namespace std;

typedef struct index {
	int y, x;
	double p;

	index(int yy = 0, int xx = 0, double pp = 0.0) :y(yy), x(xx), p(pp) {}

	bool operator< (const index& k) const {
		return p == k.p ? (y == k.y ? x < k.x : y < k.y) : p < k.p;
	}
}Index;

typedef pair<int, int> p;

int n, m, mmap[MAX_N][MAX_N], vSum = 0, start;
double eps;
bool oil[MAX_M][MAX_N][MAX_N] = { 0 };
map<Index, bool> ans;

void rrandom() {
	int i, j;
	vector<Index> v;
	srand(time(NULL));
	rep(i, n)
		rep(j, n) {
		if (mmap[i][j] == NIL)
			v.push_back(Index(i, j));
	}
	while (1) {
		j = rand() % v.size();
		printf("q 1 %d %d", v[j].y, v[j].x);
		cout << endl << flush;
		scanf("%d", &mmap[v[j].y][v[j].x]);
		if (mmap[v[j].y][v[j].x] > 0) {
			ans[Index(v[j].y, v[j].x)] = true;
			vSum -= mmap[v[j].y][v[j].x];
		}
		if (vSum == 0)
			return;
		v.erase(v.begin() + j);
	}
}

int double2Int(double v) {
	int i, vv = (int)v, minI = -1;
	for (i = 0; i < 2; i++) {
		if (fabs(vv + i - v) < fabs(vv + minI - v))
			minI = i;
	}
	return vv + minI;
}

void ruiseki() {
	int i, j, k, l, dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
	double ssum[MAX_N + 1][MAX_N + 1] = { 0 };
	priority_queue<Index> PQ;
	Index temp;
	//printf("vSum:%d\n", vSum);
	//�ݐϘa�쐬 N^2-1��N�G�����s���B
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == n && j == n) {
				ssum[i][j] = (double)vSum;
			}
			else {
				printf("q %d", i * j);
				rep(k, i) {
					rep(l, j) {
						printf(" %d %d", start + k, start + l);
					}
				}
				cout << endl << flush;
				scanf("%lf", &ssum[i][j]);
				//ssum[i][j] = (double)double2Int(ssum[i][j]);
				if (i == 1 && j == 1) {
					mmap[start][start] = double2Int(ssum[i][j]);
				}
			}
		}
	}
	rep(i, n)
		rep(j, n) {
			PQ.push(Index(i + start, j + start, ssum[i + 1][j + 1] - ssum[i + 1][j] - ssum[i][j + 1] + ssum[i][j]));
			//printf("(%d,%d):%f-%f-%f+%f\n", i, j, ssum[i + 1][j + 1] , ssum[i + 1][j] , ssum[i][j + 1] , ssum[i][j]);
		}
	while (PQ.size() > 0) {
		temp = PQ.top();
		if (temp.p <= 0)
			break;
		PQ.pop();
		if (mmap[temp.y][temp.x] == NIL) {
			printf("q 1 %d %d", temp.y, temp.x);
			cout << endl << flush;
			scanf("%d", &mmap[temp.y][temp.x]);
		}
		if (mmap[temp.y][temp.x] > 0) {
			vSum -= mmap[temp.y][temp.x];
			ans[Index(temp.y, temp.x, temp.p)] = true;
		}
		//printf("vSum1:%d\n", vSum);
		if (vSum <= 0)
			break;
	}
	if (vSum <= 0)
		return;
	//���D��T���J�n(v(i,j)�̒l���傫�����̂�D�悷��)
	while (PQ.size())
		PQ.pop();
	rep(i,n)
		rep(j, n)
			if (mmap[i][j] > 0)
				PQ.push(Index(i, j, (double)mmap[i][j]));
	while (PQ.size()) {
		temp = PQ.top(); PQ.pop();
		rep(i, MAX_D) {
			if (temp.y + dy[i] >= 0 && temp.y + dy[i] < n && temp.x + dx[i] >= 0 && temp.x + dx[i] < n && mmap[temp.y + dy[i]][temp.x + dx[i]] == NIL) {
				printf("q 1 %d %d", temp.y + dy[i], temp.x + dx[i]);
				cout << endl << flush;
				scanf("%d", &mmap[temp.y + dy[i]][temp.x + dx[i]]);
				if (mmap[temp.y + dy[i]][temp.x + dx[i]] > 0) {
					vSum -= mmap[temp.y + dy[i]][temp.x + dx[i]];
					ans[Index(temp.y + dy[i], temp.x + dx[i], (double)mmap[temp.y + dy[i]][temp.x + dx[i]])] = true;
					PQ.push(Index(temp.y + dy[i], temp.x + dx[i], (double)mmap[temp.y + dy[i]][temp.x + dx[i]]));
				}
			}
			if (vSum <= 0)
				return;
		}
	}
	//�����_���ɁA�������ĂȂ��c��̖��c��������B
	vector<Index> v;
	srand(time(NULL));
	rep(i, n)
		rep(j, n) {
			if (mmap[i][j] == NIL)
				v.push_back(Index(i, j));
		}
	while (1) {
		j = rand() % v.size();
		printf("q 1 %d %d", v[j].y, v[j].x);
		cout << endl << flush;
		scanf("%d", &mmap[v[j].y][v[j].x]);
		if (mmap[v[j].y][v[j].x] > 0) {
			ans[Index(v[j].y, v[j].x)] = true;
			vSum -= mmap[v[j].y][v[j].x];
		}
		//printf("vSum2:%d\n", vSum);
		if (vSum <= 0)
			return;
		v.erase(v.begin() + j);
	}
	return ;
}

int main() {
	int i, j, k, l;
	//���͏���
	scanf("%d%d%lf", &n, &m, &eps);
	start = 0;
	rep(i, n)
		rep(j, n)
			mmap[i][j] = NIL;
	rep(i, m) {
		scanf("%d",&j);
		vSum += j;
		while (j--) {
			scanf("%d%d", &k, &l);
			oil[i][k][l] = true;
		}
	}
	while (1) {
		//���W�T��
		//rrandom();
		ruiseki();
		//�o�͏���
		printf("a %d", (int)ans.size());
		for (pair<Index,bool> temp : ans) {
			printf(" %d %d", temp.first.y, temp.first.x);
		}
		cout << endl << flush;
		scanf("%d", &k);
		if (k == 1)
			break;
	}
	return 0;
}