/*�A���S���Y���ƍH�v�_(����/CPU: 19 ms  Memory: 3892 KB  Length: 470 B)
�������ɂł���Ȃ�A���ɂ��āA���̎��̌`����v�Z�ʂ��팸������@��������p�^�[�������݂���B
���񋁂߂�sumX��sumY�͘a�ł��邩��A�]�������̂͘a�̍��̂��ꂼ��ɂ��Ăł���A�����ꂼ��̌v�Z�r���ł͎��Ȃ����Ƃɒ��ӁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n, m;

int main() {
	int i, j;
	long long sumX = 0, sumY = 0, tmp;
	scanf("%d%d",&n,&m);
	rep(i, n) {
		scanf("%lld",&tmp);
		sumX = (sumX+i * tmp - (n - i - 1) * tmp) % MOD;
	}
	rep(i, m) {
		scanf("%lld", &tmp);
		sumY = (sumY+i * tmp - (m - i - 1) * tmp) % MOD;
	}
	printf("%lld\n", (sumX*sumY)%MOD);
	return 0;
}
/*�]������邾���Ƃ���ver
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n, m;

int main() {
	int i, j;
	long long sumX = 0, sumY = 0, tmp;
	scanf("%d%d",&n,&m);
	rep(i, n) {
		scanf("%lld",&tmp);
		sumX = (sumX+(MOD+(i * tmp)%MOD - ((n - i - 1) * tmp)%MOD)%MOD) % MOD;
	}
	rep(i, m) {
		scanf("%lld", &tmp);
		sumY = (sumY+(MOD+(i * tmp)%MOD - ((m - i - 1) * tmp)%MOD)%MOD) % MOD;
	}
	printf("%lld\n", sumX*sumY%MOD);
	return 0;
}
*/