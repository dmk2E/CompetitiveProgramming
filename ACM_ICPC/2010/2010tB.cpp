/*�A���S���Y���ƍH�v�_(Moonlight Farm/CPU: 0 ms  Memory: 3392 KB  Length: 794 B)
�e�앨�ɂ��āA�^����ꂽ�����̒ʂ�Ɏ�������p���v�Z���A�앨�̖��Ol��p��g�Ƃ����f�[�^���앨���ɕێ�����B���̌�A�����Ƀ\�[�g���ďo�͂���΂悢�B���ӓ_�Ƃ��āA���������_���^�̓������Z���������A�����EPS
��p�������@�ōs�����B�ň��v�Z�ʂ�O(n+n*log2(n))=O(n*log2(n))<10^3 ���\�������B

*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 50
#define MAX_S 20
#define EPS (1e-10)
using namespace std;

typedef struct crop {
	string name;
	double p;

	crop(string nname=string("0"), double pp=0.0) :name(nname), p(pp) {}

	bool operator<(const crop& k) const {
		return p < k.p || (fabs(p - k.p) < EPS && name > k.name);
	}
}Crop;

int n, p, a, b, c, d, e, f, s, m;
char l[MAX_S + 1];
Crop crop[MAX_N];

int main() {
	int i;
	while (1) {
		scanf("%d", &n);
		if (!n)
			break;
		rep(i, n) {
			scanf("%s%d%d%d%d%d%d%d%d%d", l, &p, &a, &b, &c, &d, &e, &f, &s, &m);
			crop[i] = Crop(string(l), (double)(f * m * s - p) / (a + b + c + (d + e) * m));
		}
		sort(crop, crop + n);
		rep(i, n)
			cout << crop[n - 1 - i].name << endl;
		puts("#");
	}
	return 0;
}