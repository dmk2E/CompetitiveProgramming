/*�A���S���Y���ƍH�v�_(Chocolate Bar/CPU: 1 ms  Memory: 3952 KB  Length: 2755 B)
��ӂ�h�܂���w�ł��钷���`�̐���3�̎��A���߂�ŏ��l�́Ah%3=0�܂���w%3=0�Łu0�v(��h�܂���w��3�̔{���Ȃ��Y��ɎO�����ł���)�B�����łȂ����min(h,w)�ƂȂ�(3�̒����`��h�܂���w�łȂ����̕ӂ��l����ƁA
n+n+(n+1)=3n+1,n+n+(n-1)=3n-1�ƂȂ�A�S�̂̒����`�̈�ӂ�3�̔{���łȂ��Ȃ�K�����̂悤�ɕ����ł��邩��)�B
��ӂ�h�܂���w�ł��钷���`�̐���1�̎��A����ɋl�߂�h'*w'�̒����`�����݂���Ƃ��A����2�̒����`�̍����́Ah'*(w-'w),(h-h')*w �܂��� (h-h')*w',h*(w-w') �ƂȂ�(1<=h'<=h-1,1<=w'<=w-1)�B
h'*(w-'w),(h-h')*w �̏ꍇ���l����ƁA�܂�s1=h'*w',s2=h'*(w-'w),s3=(h-h')*w �Ƃ���ƁA3�̒����`�̖ʐς��قړ����ɂȂ�悤�ɍl�����w'=[w/2]�Ƃ���΂悢���Ƃ�������B������h'�̒l��T�����Ă����B
h'�̒l����������ɂ�āAs3�͒P���������As2,s1�͒P����������B���̂��߁Ah'�̒l����������ɂ�āAs1<=s2<=s3 -�@-> s1<=s3<=s2 -�A-> s3<=s1<=s2 �Ƃ������ɑ召�֌W���ω�����B���ꂼ��̑召�֌W�ɂ�����
Smax-Smin�̍ŏ��l���o���A�ł��������l�����߂�ŏ��l�ƂȂ�B��萳�m�ɂ� min(�u�@�̕ω����N���钼�O��s3-s1,�u�@�̕ω����N�����������s2-s1�v,�u�A�̕ω����N�����������s2-s3�v)�ƂȂ�B
(h-h')*w',h*(w-w') �̏ꍇ�����l�ɍl����΂悢�B�召�֌W�����܂�O���h',w'�̒l�͓񕪒T���ɂ�苁�߂邱�Ƃ��ł���B�ň��v�Z�ʂ� O(log2(h)+log2(w))<10^2�ƂȂ�A�\�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_H 100000
#define MAX_W 100000
using namespace std;

int h, w;

void searchMin1(long long& min) {   //h'*(w-'w),(h-h')*w �̏ꍇ
	int left, right, mid;
	long long s1, s2, s3;
	left = 1; right = h;
	while (left < right) {
		mid = (left + right) / 2;
		s2 = (long long)mid * (w - w / 2); s3 = (long long)(h - mid) * w;
		//printf("s2:%lld s3:%lld\n", s2, s3);
		if (s2 <= s3)
			left = mid + 1;
		else
			right = mid;
	}
	left--;
	s1 = (long long)left * (w / 2); s3 = (long long)(h - left) * w;
	if (min > s3 - s1)
		min = s3 - s1;
	//printf("min:%lld\n", s3 - s1);
	left++;
	if (left == h)
		return;
	s1 = (long long)left * (w / 2); s2 = (long long)left * (w - w / 2); s3 = (long long)(h - left) * w;
	if (s1 <= s3 && s3 <= s2) {
		right = h;
		if (min > s2 - s1)
			min = s2 - s1;
		//printf("min:%lld\n", s2 - s1);
		while (left < right) {
			mid = (left + right) / 2;
			s1 = (long long)mid * (w / 2); s3 = (long long)(h - mid) * w;
			if (s1 <= s3)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == h)
			return;
	}
	s2 = (long long)left * (w - w / 2); s3 = (long long)(h - left) * w;
	if (min > s2 - s3)
		min = s2 - s3;
	//printf("min:%lld\n", s2 - s3);
}

void searchMin2(long long& min) {   //(h-h')*w',h*(w-w') �̏ꍇ
	int left, right, mid;
	long long s1, s2, s3;
	left = 1; right = w;
	while (left < right) {
		mid = (left + right) / 2;
		s2 = (long long)mid * (h - h / 2); s3 = (long long)(w - mid) * h;
		//printf("s2:%lld s3:%lld\n", s2, s3);
		if (s2 <= s3)
			left = mid + 1;
		else
			right = mid;
	}
	left--;
	s1 = (long long)left * (h / 2); s3 = (long long)(w - left) * h;
	if (min > s3 - s1)
		min = s3 - s1;
	//printf("min:%lld\n", s3 - s1);
	left++;
	if (left == w)
		return;
	s1 = (long long)left * (h / 2); s2 = (long long)left * (h - h / 2); s3 = (long long)(w - left) * h;
	if (s1 <= s3 && s3 <= s2) {
		right = w;
		if (min > s2 - s1)
			min = s2 - s1;
		//printf("min:%lld\n", s2 - s1);
		while (left < right) {
			mid = (left + right) / 2;
			s1 = (long long)mid * (h / 2); s3 = (long long)(w - mid) * h;
			if (s1 <= s3)
				left = mid + 1;
			else
				right = mid;
		}
		if (left == w)
			return;
	}
	s2 = (long long)left * (h - h / 2);s3 = (long long)(w - left) * h;
	if (min > s2 - s3)
		min = s2 - s3;
	//printf("min:%lld\n", s2 - s3);
}

int main() {
	long long min = (long long)MAX_H * MAX_W + 1;
	scanf("%d%d", &h, &w);
	if (h >= 3) {   //��ӂ�h�܂���w�ł��钷���`�̐���3�̎�
		if (h % 3 == 0)
			min = 0;
		else {
			if (min > w)
				min = w;
		}
	}
	if (w >= 3) {
		if (w % 3 == 0)
			min = 0;
		else {
			if (min > h)
				min = h;
		}
	}
	searchMin1(min);   //��ӂ�h�܂���w�ł��钷���`�̐���1�̎�
	searchMin2(min);
	printf("%lld\n", min);
	return 0;
}