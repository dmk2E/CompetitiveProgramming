/*�A���S���Y���ƍH�v�_(�X�N�E�F�A�E���[�g/CPU: 1760 ms  Memory: 21388 KB  Length: 659 B)
�����`�̏c�̒����̃p�^�[�����́An+(n-1)+(n-2)+...+1=(n^2+n)/2 ���̒��������l�� (m^2+m)/2 �ƂȂ�B�c�̒������Œ肵�āA���̒������Œ肷�闬�����̌J��Ԃ��\���ŏ������Ƃ���ƁAO(n^2*m^2)>10^12>10^8 �ƂȂ�Ԃɍ���Ȃ��B
�������A�c�Ɖ����ꂼ��̒����̑S�p�^�[�����̗񋓂͂��ꂼ��O(n^2),O(m^2)��10^6 �ƂȂ�\�������B�]���āA�܂��c�̒�����S�񋓂��A(����,���̌�)�Ńn�b�V���@�ŕێ��B���̌�A���̒����̑S�񋓂��s���A�񋓂����������ꂼ��Ɠ�����
���̏c�̕ӂ̐��𑫂��Ă������ƂŁA���߂鐔���o����B�ň��v�Z�ʂ́AO(n^2+m^2)��10^6<10^7 �ƂȂ�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N 1500
#define MAX_M 1500
using namespace std;

int n, m, sumN[MAX_N + 1], sumM[MAX_M + 1];   //�^������h,w�̒l�͗ݐϘa�ŕێ����A�����̃p�^�[�����񋓂��ȗ����B

int main() {
	int i, j, cnt;
	map<int, int> v;
	while (1) {
		scanf("%d%d", &n, &m);
		if (!(n || m))
			break;
		sumN[0] = 0;
		rep(i, n) {
			scanf("%d", &j);
			sumN[i + 1] = sumN[i] + j;
		}
		sumM[0] = 0;
		rep(i, m) {
			scanf("%d", &j);
			sumM[i + 1] = sumM[i] + j;
		}
		rep(i, n)
			for (j = i + 1; j <= n; j++)
				v[sumN[j] - sumN[i]]++;
		cnt = 0;
		rep(i, m)
			for (j = i + 1; j <= m; j++)
				cnt += v[sumM[j] - sumM[i]];
		printf("%d\n", cnt);
		v.clear();
	}
	return 0;
}