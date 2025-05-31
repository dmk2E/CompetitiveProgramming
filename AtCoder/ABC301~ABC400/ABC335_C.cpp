/*�A���S���Y���ƍH�v�_(Loong Tracking/CPU: 238 ms  Memory: 11688 KB  Length: 1185 B)
�����̕����R�[�h�̘A�����𗘗p���ĕ����𐔒l�ɕϊ�������@�́A���̒l��0�`9��1���̎������ł��Ȃ��B
�ň��v�Z�ʂ�O(n+q)�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 1000000
using namespace std;

typedef struct data {
	int x, y;

	data(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
}Data;

int n, q;
Data parts[MAX_N];

int search(int head,int tail,int num) {
	if (head + num - 1 <= n - 1)
		return head + num - 1;
	return num - (n - head) - 1;
}

int main() {
	int i, head, tail, j;
	string c;
	scanf("%d%d",&n,&q);
	rep(i, n)
		parts[i] = Data(i + 1, 0);
	head = 0; tail = n - 1;
	while (q--) {
		scanf("%d",&i);
		if (i == 1) {
			cin >> c;
			switch (c[0]) {
				case 'R':
					parts[tail] = Data(parts[head].x + 1, parts[head].y);
					break;
				case 'L':
					parts[tail] = Data(parts[head].x - 1, parts[head].y);
					break;
				case 'U':
					parts[tail] = Data(parts[head].x, parts[head].y + 1);
					break;
				default:
					parts[tail] = Data(parts[head].x, parts[head].y - 1);
					break;
			}
			head = head - 1 < 0 ? n - 1 : head - 1;
			tail = tail - 1 < 0 ? n - 1 : tail - 1;
		}
		else {
			cin >> j;
			i = search(head, tail, j);
			printf("%d %d\n", parts[i].x, parts[i].y);
		}
	}
	return 0;
}