/*�A���S���Y���ƍH�v�_(Extended ABC/CPU: 1 ms  Memory: 3688 KB  Length: 1107 B)
��ԑJ�ړI�ɉ����āA�ň��v�Z�ʂ�O(n)�ƂȂ������A�u"AC"�v�Ƃ�����������g��ABC������ƂȂ邱�Ƃ��蕶����ǂݎ�邱�Ƃ��ł��Ȃ������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define MAX_S 100
using namespace std;

string str;

int main() {
	int i, cnt = 0;
	bool flagA, flagB, flagC;
	getline(cin, str);
	if (str.length() == 0) {
		puts("Yes1");
		return 0;
	}
	flagA = flagB = flagC = false;
	if (str[0] == 'A') {
		flagA = true;
	}
	else if (str[0] == 'B') {
		flagB = true;
	}
	else if(str[0]=='C') {
		flagC = true;
	}
	for (i = 0; str[i] != '\0'; i++) {
		if (flagA) {
			if (str[i] == 'A') {
				continue;
			}
			if (str[i] == 'B') {
				flagA = false;
				flagB = true;
				continue;
			}
			if (str[i] == 'C') {
				flagA = false;
				flagC = true;
				continue;
			}
		}
		if (flagB) {
			if (str[i] == 'A')
				break;
			if (str[i] == 'B') {
				continue;
			}
			if (str[i] == 'C') {
				flagB = false;
				flagC = true;
				continue;
			}
		}
		if (flagC) {
			if (str[i] == 'A')
				break;
			if (str[i] == 'B')
				break;
			if (str[i] == 'C')
				continue;
		}
	}
	if (str[i] == '\0')
		puts("Yes");
	else
		puts("No");
	return 0;
}