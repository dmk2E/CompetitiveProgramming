/*�A���S���Y���ƍH�v�_(Card Eater/CPU: 24 ms  Memory: 8376 KB  Length: 571 B)
1�����ȏ゠��J�[�h�̓��A�������J�[�h�́A���̓��������̃J�[�h3����I�ё�����ΕK��1���ɂȂ邽�߁A���̖���-1�̐������S�̂̐���������B�������ł͕K��2���ɂȂ邩��A���̐���sum�ɋL�^���Ă����Bsum�̒l�͕K������
�ł���A���������̃J�[�h��2����������B����i��2���A����j��2����4����1�Z�b�g�Ƃ��A���̃Z�b�g���ŃJ�[�h��H�ׂĂ����ƁA�K������i��j��2��ނ�1�����c��B�]���āAsum��4�̔{���Ȃ�A(sum/4)*2�A�����łȂ���΁A
�]����2���̕����Ȃ����ē��l�Ɍv�Z����΂悢�B�̂�O(n)�ŏ\�������ɓ��삷��B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

typedef pair<int, int> p;

int n;
map<int,int> d;

int main() {
	int i,tmp,sum=0;
	cin >> n;
	rep(i, n) {
		//scanf_s("%d",&tmp);
		scanf("%d", &tmp);
		d[tmp]++;
	}
	for (p temp : d) {
		//printf("(%d,%d)\n",temp.first,temp.second);
		if (temp.second > 1) {
			if (temp.second % 2 == 0) {
				n -= temp.second;
				sum += 2;
			}
			else 
				n -= temp.second - 1;
		}
		//printf("n:%d sum:%d\n",n,sum);
	}
	n += (sum / 4)*2;   //�����^�̏��͏����_�ȉ��͐؂�̂Ă��邱�Ƃ𗘗p�����B
	printf("%d\n",n);
	return 0;
}