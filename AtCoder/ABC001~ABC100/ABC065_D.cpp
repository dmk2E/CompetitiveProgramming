/*�A���S���Y���ƍH�v�_(Built?/CPU: 123 ms  Memory: 14168 KB  Length: 1700 B)
�ŏ��S��؂����߂�΂悢�̂����A�ӂ̐����������čň��v�Z�ʂ��傫�����Ď��s�������ԂɊԂɍ���Ȃ��B�����ŕӂ̐������炷�H�v������K�v���������B�ӂ����点�Ό�͒P���ȃv�����̃A���S���Y���ŉ�����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 100000
using namespace std;

typedef struct cityX {
	int id, x;

	cityX(int iid = 0, int xx = 0) :id(iid), x(xx) {}

	bool operator< (const cityX& k) const {
		return x < k.x;
	}
}CityX;

typedef struct cityY {
	int id, y;

	cityY(int iid = 0, int yy = 0) :id(iid), y(yy) {}

	bool operator< (const cityY& k) const {
		return y < k.y;
	}
}CityY;

typedef struct pair<int, int> p;

int n, x, y;
vector<p > adj[MAX_N];

long long prim() {
	int cnt = 0;
	p now;
	long long sum = 0;
	bool color[MAX_N] = { 0 };
	priority_queue<p > PQ;//(����,�s�s�ԍ�)
	PQ.push(make_pair(0, 0));
	while (PQ.size()) {
		do {
			now = PQ.top(); PQ.pop();
		} while (color[now.second] && PQ.size());
		if (color[now.second])
			break;
		cnt++;
		color[now.second] = true;
		sum += -now.first;
		if (cnt == n)
			return sum;
		for (p x : adj[now.second])
			if (color[x.first] == false)
				PQ.push(make_pair(-x.second, x.first));
	}
	return -1;
}

int main() {
	int i;
	vector<CityX> PQX;
	vector<CityY> PQY;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d%d",&x,&y);
		PQX.push_back(CityX(i, x));
		PQY.push_back(CityY(i, y));
	}
	sort(PQX.begin(), PQX.end());
	sort(PQY.begin(), PQY.end());
	rep(i, n - 1) {
		adj[PQX[i].id].push_back(make_pair(PQX[i + 1].id, PQX[i + 1].x - PQX[i].x));
		adj[PQX[i + 1].id].push_back(make_pair(PQX[i].id, PQX[i + 1].x - PQX[i].x));
		adj[PQY[i].id].push_back(make_pair(PQY[i + 1].id, PQY[i + 1].y - PQY[i].y));
		adj[PQY[i + 1].id].push_back(make_pair(PQY[i].id, PQY[i + 1].y - PQY[i].y));
	}
	printf("%lld\n", prim());
	return 0;
}