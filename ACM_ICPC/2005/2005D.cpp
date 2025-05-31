/*アルゴリズムと工夫点(/CPU:  ms  Memory:  KB  Length:  B)

*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t){t=a,a=b,b=c}
#define MAX_N 8
#define MAX_M 30
#define MAX_MIN 3001
using namespace std;

typedef enum color {
	NIL=-3,
	BLACK,
	WHITE
}Color;

int n, m, p, a, b, t[MAX_N], row[MAX_N];
bool flag[MAX_N];
list<pair<int, int> > adj[MAX_M];   //(都市番号,距離)で保持
Color color[MAX_M];

void init() {
	int i;
	rep(i, n)
		flag[i] = true;
}

void initColor() {
	int i;
	rep(i, m) {
		color[i] = WHITE;
	}
}

void showRow() {
	int i;
	rep(i, n)
		printf("%d",row[i]);
	puts("");
}

double dijk() {
	list<pair<int, int> >::iterator it;
	pair<double, pair<int, int> > now;
	priority_queue<pair<double, pair<int, int> > > PQ;   //(総距離,(都市番号,使ったチケットの枚数))で保持
	PQ.push(make_pair(0.0,make_pair(a-1,0)));
	showRow();
	initColor();
	while (!PQ.empty()) {
		do {
			now = PQ.top(); PQ.pop();
		} while (!PQ.empty() && color[now.second.first] == BLACK);
		if (now.second.first == b - 1&&now.first>-2.4) {
			//showRow();
			//printf("now:(%.4f,%d) ticket:%d\n", now.first, now.second.first, now.second.second);
			return -now.first;
		}
		if (now.second.second == n)
			continue;
		color[now.second.first] = BLACK;
		for (it = adj[now.second.first].begin(); it != adj[now.second.first].end(); it++) {
			if (color[it->first] == WHITE) {
				PQ.push(make_pair(now.first - (double)it->second / t[row[now.second.second]], make_pair(it->first,now.second.second+1)));
				//printf("next:(%.4f,%d) ticket:%d\n", now.first - (double)it->second / t[row[now.second.second]], it->first, now.second.second + 1);
			}
		}
	}
	return NIL;
}

void showList() {
	int i;
	list<pair<int, int> >::iterator it;
	rep(i, m) {
		printf("%d:",i);
		for (it = adj[i].begin(); it != adj[i].end(); it++) 
			printf("(%d,%d)->",it->first,it->second);
		puts("");
	}
}

double searchMin(int now) {
	if (now == n) 
		return dijk();
	int i;
	double min = MAX_MIN, temp;
	rep(i, n) {
		if (flag[i]) {
			flag[i] = false;
			row[now] = i;
			if ((temp = searchMin(now + 1)) >= 0 &&temp < min)
				min = temp;
			flag[i] = true;
		}
	}
	return min;
}

int main() {
	int i,j,k;
	double temp;
	while (1) {
		scanf_s("%d%d%d%d%d",&n,&m,&p,&a,&b);
		//scanf("%d%d%d%d%d", &n, &m, &p, &a, &b);
		if (!(n || m || p || a || b))
			break;
		rep(i, n) {
			scanf_s("%d", &t[i]);
			//scanf("%d", &t[i]);
		}
		while (p--) {
			scanf_s("%d%d%d",&i,&j,&k);
			//scanf("%d%d%d", &i, &j, &k);
			adj[i - 1].push_back(make_pair(j - 1, k));
			adj[j - 1].push_back(make_pair(i - 1, k));
		}
		init();
		//showList();
		if ((temp = searchMin(0)) == MAX_MIN)
			puts("Impossible");
		else
			printf("%.3f\n",temp);
		rep(i, m)
			adj[i].clear();
	}
	return 0;
}