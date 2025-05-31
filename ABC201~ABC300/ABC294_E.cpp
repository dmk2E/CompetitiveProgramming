/*�A���S���Y���ƍH�v�_(2xN Grid/CPU: 48 ms  Memory: 8592 KB  Length: 1843 B)
��N1��vi���Œ肵�A����vi�����݂���͈�[s1,e1)�ɂ������N2��vj���ɂ��āAvi=vj�ƂȂ�vj�͈̔�[s2,e2)����Ax1j=x2j�ƂȂ�������߂�B���̍ۂ̒T���ɗݐϘa�Ɠ񕪒T���𗘗p����B
�ň��v�Z�ʂ�O(N1+N2+N1*log2(max(N1,N2)))=O(N2+N1*log2(max(N1,N2)))<10^7 �ƂȂ�\���ɍ����B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_N1 100000
#define MAX_N2 100000
using namespace std;

typedef pair<long long, long long> p;

long long l;
int n1, n2;
p nn1[MAX_N1], nn2[MAX_N2];
long long sum1[MAX_N1 + 1], sum2[MAX_N2 + 1];

int searchBegin(long long begin) {
	long long left = 1, mid, right = n2;
	while (left < right) {
		mid = (left + right) / 2;
		if (sum2[mid] == begin)
			return mid - 1;
		else if (sum2[mid] < begin)
			left = mid + 1;
		else
			right = mid;
	}
	return left - 1;
}

int searchEnd(long long end) {
	long long left = 1, mid, right = n2;
	while (left < right) {
		mid = (left + right) / 2;
		if (sum2[mid] == end)
			return mid - 1;
		if (sum2[mid] < end)
			left = mid + 1;
		else
			right = mid;
	}
	return left - 1;
}

int main() {
	int i, begin, end;
	long long s1, e1, s2, e2, cnt = 0;//��N1�͈̔�[s1,e1),��N2�͈̔�[s2,e2)
	scanf("%lld%d%d", &l, &n1, &n2);
	sum1[0] = sum2[0] = 0;
	rep(i, n1) {
		scanf("%lld%lld", &nn1[i].first, &nn1[i].second);
		sum1[i + 1] = sum1[i] + nn1[i].second;
	}
	rep(i, n2) {
		scanf("%lld%lld", &nn2[i].first, &nn2[i].second);
		sum2[i + 1] = sum2[i] + nn2[i].second;
	}
	rep(i, n1) {   //������N1[i]�͈̔͂ɂ����Ē��ڂ��ׂ�������N2��̗v�f�͈̔�[begin,end]�Ƃ���B
		//printf("i:%d\n", i);
		begin = searchBegin(s1 = sum1[i]);
		end = searchEnd(e1 = sum1[i + 1] - 1);
		e1++;
		//printf("begin:%d end:%d\n", begin, end);
		//printf("s1:%lld e1:%lld\n", s1, e1);
		for (; begin <= end; begin++) {
			if (nn2[begin].first == nn1[i].first) {
				s2 = sum2[begin];
				e2 = s2 + nn2[begin].second;
				//printf("s2:%lld e2:%lld\n", s2, e2);
				if (s1 <= s2 && s2 < e1) {
					if (s2 < e1)
						cnt += (e1 < e2 ? e1 : e2) - s2;
				}
				else if (s2 <= s1 && s1 < e2)
					cnt += (e1 < e2 ? e1 : e2) - s1;
			}
			//printf("%lld\n", cnt);
		}
	}
	printf("%lld\n", cnt);
	return 0;
}