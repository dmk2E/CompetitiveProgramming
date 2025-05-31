/*�A���S���Y���ƍH�v�_(���U�I���x/CPU:  ms  Memory:  KB  Length:  B)
�u�R�o��v��u����낿��냍�{�b�g�v���l�A�O���t���g������_�C�N�X�g���@�ŉ������Ƃ��ł���B����͓s�s�ł��钸�_���A���B�������̑��x�Ƃǂ̒��_���瓞�B�������̑S�p�^�[�������������₵�A�_�C�N�X�g���@���s����
�悢�B�ň��v�Z�ʂ́AO((n*MAX_V*n+m)*log2(n*MAX_V*n+m))<10^6 �ƂȂ�\�������B�������A�����̍ۂ͈ȉ��̃��[���ɒ��ӁB
<i>�ړI�n���o�鎞�A�܂��o���n�ɒ������O�̑��x�́u1�v�Ɍ�����B<ii>U�^�[���֎~(���O�ɖK�₵���s�s�ɖ߂�̂͋֎~)
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 30
#define MAX_V 30
#define NIL -1
using namespace std;

typedef struct city {
	int id, d, c;

	city(int iid = 0, int dd = 0, int cc = 0) :id(iid),d(dd), c(cc) {}

}City;

typedef struct data {
	int now, from, v;
	double t;

	data(int nnow=0, int ffrom=0, int vv=0, double tt=0.0):now(nnow),from(ffrom),v(vv),t(tt) {}

	bool operator<(const data& k) const {
		return t < k.t;
	}
}Data;

int n, m, s, g;
vector<City> adj[MAX_N];

double dijk(int s,int g) {
	int i, j, k;
	Data now;
	priority_queue<Data> PQ;
	bool color[MAX_N][MAX_V + 1][MAX_N];   //color[i][j][k]:�s�si�ɑ���j+1�œs�sk���炫�����Ƃ�\�����_
	rep(i, n)
		rep(j, MAX_V + 1)
			rep(k, n)
				color[i][j][k] = true;
	for (City c : adj[s])
		PQ.push(Data(c.id, s, 1, -(double)c.d));
	while (PQ.size()) {
		do {
			now = PQ.top(); PQ.pop();
		} while (PQ.size() > 0 && color[now.now][now.v][now.from] == false);
		if (color[now.now][now.v][now.from] == false)
			break;
		color[now.now][now.v][now.from] = false;
		if (now.now == g && now.v == 1)
			return -now.t;
		for (City c : adj[now.now]) {
			if (c.id == now.from)
				continue;
			if (now.v + 1 <= c.c && color[c.id][now.v + 1][now.now])
				PQ.push(Data(c.id, now.now, now.v + 1, now.t - (double)c.d / (now.v + 1)));
			if (now.v <= c.c && color[c.id][now.v][now.now])
				PQ.push(Data(c.id, now.now, now.v, now.t - (double)c.d / now.v));
			if (now.v - 1 > 0 && now.v - 1 <= c.c && color[c.id][now.v - 1][now.now])
				PQ.push(Data(c.id, now.now, now.v - 1, now.t - (double)c.d / (now.v - 1)));
		}
	}
	return NIL;
}

int main() {
	int i, j, k, ii;
	double ans;
	while (1) {
		scanf("%d%d", &n, &m);
		if (!(n || m))
			break;
		scanf("%d%d", &s, &g);
		while (m--) {
			scanf("%d%d%d%d", &i, &j, &k, &ii);
			adj[i - 1].push_back(City(j - 1, k, ii));
			adj[j - 1].push_back(City(i - 1, k, ii));
		}
		if ((ans = dijk(s - 1, g - 1)) == NIL)
			puts("unreachable");
		else
			printf("%.4f\n", ans);
		rep(i, n)
			adj[i].clear();
	}
	return 0;
}