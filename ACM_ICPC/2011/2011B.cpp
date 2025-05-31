/*�A���S���Y���ƍH�v�_(���E�̓V��/CPU: 0 ms  Memory: 3348 KB  Length: 906 B)
�o�����X�����Ă��邽�߂̕K�v�����Ƃ��āA������str��擪���珄�񂵂Ă������A('('�̐�)>=(')'�̐�) �� ('['�̐�)>=(']'�̐�) �͕K���������B������A'('�Ȃ�+1,')'�Ȃ�-1����ϐ�cnt1,'['��']'�ɂ��Ă����l�̓���������ϐ�
cnt2��p���Ĕ��肷��B�܂�Acnt1=cnt2=0����X�^�[�g���āA�u���߂�cnt1>0�܂���cnt2>0�ɂȂ�������str[s]�̊��ʁv�Ɓucnt1=0����cnt2=0�ɍĂтȂ�������str[e]�̊��ʁv�͑Ή����銇�ʂƂȂ��Ă���K�v������B�܂��r����cnt1,
cnt2�̂ǂ��炪���̐��ɂȂ��Ă͂����Ȃ��B���̎��A�����𖞂����Ȃ�A[s,e)��str�̕�����ɂ��āA���l�̔�����s���΂悢�B���̎����͍ċA��p���čs���B
str��̑S�Ă̕������ő�2,3�񂾂����񂷂邩��A�ň��v�Z�ʂ� O(|s|)<10^3 �ƂȂ�A�\�������B
���ꔭAC�o���Ȃ������� cnt1,cnt2�̂����ꂩ�����ɂȂ������_�Ńo�����X�ł͂Ȃ�����A���̎��_��false��Ԃ��悤�ɂ����B
���X�^�b�N��p���������̕����y�������B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
#define NIL -1
using namespace std;

string str;

bool isBalanced(int s,int e){//������str�ɂ�����[s,e)�̕������o�����X���Ă��邩���肷��B
	//printf("f(%d,%d) ",s,e);
	int i,ss=NIL,ee=NIL,cnt1=0,cnt2=0;
	for(i=s;i<e;i++){
		switch(str[i]){
			case '(':
				if(ss==NIL)
					ss=i;
				cnt1++;
				break;
			case '[':
				if(ss==NIL)
					ss=i;
				cnt2++;
				break;
			case ')':
				ee=i;
				cnt1--;
				break;
			case ']':
				ee=i;
				cnt2--;
				break;
			default:
				break;
		}
		if(cnt1<0||cnt2<0)
			return false;
		if(ss!=NIL){
			if(cnt1==0&&cnt2==0){
				//printf("judge(%d,%d)",ss,ee);
				if(((str[ss]=='('&&str[ee]==')')||(str[ss]=='['&&str[ee]==']'))&&isBalanced(ss+1,ee)){
					i=ee;
					ss=ee=NIL;
					cnt1=cnt2=0;
					//printf("true ");
				}else{
					//printf("false ");
					return false;
				}
			}
		}
	}
	//printf("finished ");
	return (ss==NIL)&&(ee==NIL);
}

int main() {
	while(1){
		getline(cin,str);
		if(str[0]=='.')
			break;
		printf("%s\n",isBalanced(0,(int)str.length())?"yes":"no");
	}
	return 0;
}