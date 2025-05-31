/*�A���S���Y���ƍH�v�_(Dragon Fantasy/CPU: 100 ms  Memory: 3344 KB  Length: 1279 B)
�E�҂̈ʒu�ƃN���X�^���̈ʒu�𒸓_�Ƃ݂Ȃ����������S�O���t���쐬���A�[���D��T�����s�����B�E�҂̏��߂̈ʒu�̒��_�ԍ���0�Ƃ��A�N���X�^���̊e�ʒu����͂��ꂽ���ɒ��_1,2,...n�Ƃ����Bn=20������}������s�����B
�}��������́u���݈ʒu�����邱�Ƃ��ł��Ȃ��N���X�^����1�ł�����Ȃ�A�T����ł��؂�v�Ƃ�������(�撸�_a,b,c�����鎞�A�O�p�`�̐����������Aab<ac+cb���������邱�Ƃ��猻�݂̒��_a�Ƃ��āAa->b�������Ȃ�a->c->b
�Ƃ������[�g���s�\�ƂȂ邩��)�B

�E���[�N���b�h������2�_�Ԃ̒��������̂��ƂŁA�}���n�b�^�������͊e���W�̍��̐�Βl�̑��a��\���B
�E�v�Z�ʂ��K��ƂȂ�T�����̉�@
10!�ȉ�->�S�T���@20!->�}����T���@50!->�ʏ�̒T���ł͉����Ȃ�(DP�ŉ������Ƃ�����)
�S�T���������������@�̈�Ɂu�}����v������B����͒T���Ώۂ�؍\�����Ƃ݂Ȃ��A�r���̐[���ŒT����ł��~�߂������t���邱�Ƃɂ��A��荂���������@�ŁA�؍\���̐[�����󂢂����ɒT����ł��؂��悤�Ȏ}����
�������]�܂����B
�E���������_�^�̒l�̓������Z�́A�����̒l�̕ێ��̕��@�̊֌W�Ŗ{���̒l�Ɣ����ȍ������܂�Ă��܂��A���m�ɍs�����Ƃ��ł��Ȃ��B���̂��ߓ������Ɣ��肷����@�̈�Ƃ��āA�u���̒l�����ɏ������l�ȉ��Ȃ�Γ����Ƃ���v
�Ƃ������@������A����͂����p���Ė�����ᏋC�̉~����ɃN���X�^�������邩���肵���B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MAX_N 20
#define INF 8000001
#define EPS (1e-10)
using namespace std;

typedef enum color {
	BLACK=-2,
	WHITE
}Color;

typedef pair<int, int> p;

int n, dx, dy;
double adj[MAX_N + 1][MAX_N + 1], tlmt[MAX_N + 1];   //tlmt[i]�͒��_i�͎���tlmt[i]�܂łɓ��B���Ȃ��ƁAᏋC�Ŏ��Ȃ��Ȃ��Ă��܂����Ƃ������Ă���B
Color color[MAX_N + 1];
p idx[MAX_N + 1];

bool dfs(double t,int now,int cnt) {
	int i;
	if (cnt == n + 1)
		return true;
	rep(i, n + 1) {
		if (color[i] == WHITE&&tlmt[i]<=t+adj[now][i]+EPS)
			return false;
	}
	rep(i, n + 1) {
		if (color[i] == WHITE) {
			color[i] = BLACK;
			if(dfs(t+adj[now][i],i,cnt+1))
				return true;
			color[i] = WHITE;
		}
	}
	return false;
}

double dist(int x,int y) {
	return sqrt(x*x+y*y);
}

int main() {
	int i, j;
	while (1) {
		cin >> n >> idx[0].first >> idx[0].second >> dx >> dy;
		if (!(n || idx[0].first || idx[0].second || dx || dy))
			break;
		rep(i, n)
			cin >> idx[i+1].first >> idx[i+1].second;
		rep(i, n+1) {
			adj[i][i] = INF;
			color[i] = WHITE;
			tlmt[i] = dist(idx[i].first - dx,idx[i].second - dy);
			for (j = i + 1; j < n+1; j++) 
				adj[i][j] = adj[j][i] = dist(idx[i].first - idx[j].first,idx[i].second-idx[j].second);
		}
		color[0] = BLACK;
		if (dfs(0.0,0,1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}