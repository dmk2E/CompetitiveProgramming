/*�A���S���Y���ƍH�v�_(Insert or Erase/CPU:  ms  Memory:  KB  Length:  B)
list�\���ɂ����āAinsert�֐��͎w�肳�ꂽ�A�h���X���w���v�f�̑O�ɐV�����v�f��ǉ�����(�v�f���ꂼ����w���C�e���[�^�͕ω����Ȃ�)�B��������}�������v�f�̃C�e���[�^��Ԃ�l�Ƃ���B
���X�g�\���́A�v�f�̍폜��ǉ���O(1)�ōςނ��A�v�f�̒T���ɂ�O(n)�������Ă��܂����Ƃł���A�폜����v�f��ǉ�����v�f�̃C�e���[�^�͂��炩���߉��z�z��Ŏ����Ă����K�v������B
��map�\���g���Ă��ŏ��̕��j�͊Ԉ���ĂȂ��������A�����Ń~�X�����������߂�TLE�~2�ƂȂ��Ă��܂����A�A�A�A�A�A�B
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<(int)(n);i++)
using namespace std;

int n;
list<int> a;
map<int,list<int>::iterator> v;

void showList(){
    int i,j;
    i=0;
    for(int x:a){
        if(i==v.size()-1){
            j=x;
            break;
        }
        printf("%d ",x);
        i++;
    }
    if(v.size())
        printf("%d\n",j);
}

int main() {
    int i,j;
    list<int>::iterator it;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        a.push_back(i);
        it=a.end();
        v[i]=--it;
    }
    scanf("%d",&n);
    while(n--){
        //showList();
        scanf("%d",&i);
        if(i==1){
            scanf("%d%d",&i,&j);
            it=v[i];
            v[j]=a.insert(++it,j);
        }else{
            scanf("%d",&i);
            a.erase(v[i]);
            v.erase(v.find(i));
        }
    }
    showList();
	return 0;
}