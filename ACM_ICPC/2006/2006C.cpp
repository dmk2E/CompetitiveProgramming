/*アルゴリズムと工夫点(Hexerpents of Hexwamp/CPU:  ms  Memory:  KB  Length:  B)

*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 8
#define MAX_D 6
using namespace std;

typedef pair<int, int> p;

typedef struct snake {
	int cnt;
	p body[MAX_N];
}Snake;

int n, k, x, y;
map<p, bool> obj;
p dyx[MAX_D] = { {0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1} };

bool judge(Snake now,p z) {
	int i;
	rep(i, n)
		if (now.body[i].first == z.first && now.body[i].second == z.second)
			return false;
	return true;
}

bool makeChoice(Snake temp,int now,p a[]) {   //移動できるか判定する。
	int i, max = -1;
	p tmp;
	map<p, int> count;
	rep(i, MAX_D) {
		tmp = temp.body[now];
		tmp.first += dyx[i].first;
		tmp.second += dyx[i].second;
		count[tmp]++;
		if (max < count[tmp])
			max = count[tmp];
	}
	if (now - 1 >= 0) {
		rep(i, MAX_D) {
			tmp = temp.body[now-1];
			tmp.first += dyx[i].first;
			tmp.second += dyx[i].second;
			count[tmp]++;
			if (max < count[tmp])
				max = count[tmp];
		}
	}
	if (now + 1 < n) {
		rep(i, MAX_D) {
			tmp = temp.body[now];
			tmp.first += dyx[i].first;
			tmp.second += dyx[i].second;
			count[tmp]++;
			if (max < count[tmp])
				max = count[tmp];
		}
	}
	i = 0;
	for (pair<p,int> z : count) {
		if (z.second == max && obj[z.first] == false && judge(temp,z.first))
			a[i++] = z.first;
	}
	a[i].first = a[i].second = -1;
	return i > 0;
}

int bfs(Snake now) {

}

int main() {
	int i, j;
	p tmp;
	Snake temp;
	while (1) {
		cin >> n;
		if (!n)
			break;
		obj.clear();
		rep(i, n) 
			cin >> temp.body[i].second >> temp.body[i].first;
		cin >> k;
		while (k--) {
			cin >> tmp.second >> tmp.first;
			obj[tmp] = true;
		}
		cin >> x >> y;
		printf("%d\n", bfs(temp));
	}
	return 0;
}