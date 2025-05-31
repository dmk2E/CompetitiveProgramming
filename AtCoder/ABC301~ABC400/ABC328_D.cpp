/*�A���S���Y���ƍH�v�_(Take ABC/CPU: 12 ms  Memory: 10308 KB  Length: 2513 B)
�W�����C�u�����ł��郊�X�g�\����begin()�̓��X�g�\���̐擪�̃C�e���[�^�[��Ԃ��̂ɑ΂��Aend()�͖��[�̎��̃C�e���[�^�[��Ԃ��B�擪�Ɩ��[���|�C���^�Ƃ��Ď����ʂȃm�[�h�͑��݂��Ȃ����߁Abegin()����O�A��������end()�ȍ~�̃C�e
���[�^�[�ɃA�N�Z�X���悤�Ƃ���ƃo�O��B�v�f���������r���̗v�f����T�����ĊJ���������Abegin()�ŋA���Ă��郊�X�g�\���̐擪�̍폜������\��������ꍇ�́A�����Ń��X�g������������悢�B
����̃��X�g�\�����g���āA��������폜����������V����"ABC"�̒T�����n�߂�΁A�v�Z�ʂ�O(2*|s|)�ʂɂȂ�A�\�������B�폜�������A�T�����J�n����ʒu�ɒ��ӁB
*/
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t){t=a,a=b,b=c}
#define MAX_S 200000
using namespace std;

typedef struct node {
	char c;
	struct node * prev, * next;
}Node;

class List {
	Node* nil;

public:
	List();
	~List();
	void push_front(char c);
	void push_back(char c);
	Node* pop_front();
	Node* pop_back();
	void deleteNode(Node *z);
	Node* getNil();
	void showList();
};

List::List() {
	nil = new Node;
	nil->prev = nil->next = nil;
}

List::~List() {
	Node *cur,*temp;
	cur = nil->next;
	while (cur != nil) {
		temp = cur;
		cur = cur->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
	delete nil;
}

void List::push_front(char c) {
	Node* z = new Node;
	z->c = c;
	z->prev = nil;
	z->next = nil->next;
	nil->next->prev = z;
	nil->next = z;
}

void List::push_back(char c) {
	Node* z=new Node;
	z->c = c;
	z->next = nil;
	z->prev = nil->prev;
	nil->prev->next = z;
	nil->prev = z;
}

Node* List::pop_front() {
	return nil->next;
}

Node* List::pop_back() {
	return nil->prev;
}

void List::deleteNode(Node *z) {
	z->prev->next = z->next;
	z->next->prev = z->prev;
	delete z;
}

Node* List::getNil() {
	return nil;
}

void List::showList() {
	Node* cur = nil->next;
	if (cur == nil) {
		puts("");
		return;
	}
	while (cur->next!= nil) {
		printf("%c",cur->c);
		cur=cur->next;
	}
	printf("%c\n",cur->c);
}

char str[MAX_S + 1], abc[4] = "ABC";
List s;

int main() {
	int i,now;
	Node* it,*start,*tmp;
	scanf_s("%s",str,MAX_S+1);
	//scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++)
		s.push_back(str[i]);
	for (now = 0,start=it=s.pop_front();it!=s.getNil();it=it->next) {
		//printf("start:%c,it:%c\n",start->c,it->c);
		if (it->c == abc[now]) {
			now++;
			if (now == 3) {
				tmp = it->next;
				for (i = 0;; i = (i + 1) % 2) {
					if (i % 2 == 0) {
						it = start->next;
						s.deleteNode(start);
						if (tmp == it)
							break;
					}
					else {
						start = it->next;
						s.deleteNode(it);
						if (tmp == start)
							break;
					}
				}
				//s.showList();
				i = 0;
				while (it->prev != s.getNil()){   //"ABC"���폜���ĐV���ȕ����񂪘A�����ꂽ�Ƃ��A�V����"ABC"���ł��Ȃ����m�F���邽�߂ɍő��2�߂�K�v������('C'����n�܂镶���񂪘A�����Ă����ꍇ)�B
					it = it->prev;
					i++;
					if (i == 2)
						break;
				}
				start = it;
				it = it->prev;
				now = 0;
			}
		}
		else if(it->c==abc[0]) {
			start = it;
			now = 1;
		}
		else {
			start = it->next;
			now = 0;
		}
	}
	s.showList();
	return 0;
}

/*
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define swap(a,b,t){t=a,a=b,b=c}
#define MAX_S 200000
using namespace std;

char str[MAX_S+1],abc[4]="ABC";
list<char> s;

list<char>::iterator deleteS(list<char>::iterator start, list<char>::iterator end) {
	int i,cnt=0;
	list<char>::iterator tmp=start;
	while (tmp != end) {
		tmp++;
		cnt++;
	}
	rep(i, cnt+1) {
		if (i % 2 == 0) {
			tmp = start;
			tmp++;
			s.erase(start);
		}
		else {
			start = tmp;
			start++;
			s.erase(tmp);
		}
	}
	return cnt%2==0?start:tmp;
}

void showString(list<char> s) {
	int i;
	list<char>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
		printf("%c", *it);
	puts("");
}

int main() {
	int i,now;
	list<char>::iterator it,start;
	scanf_s("%s",str,MAX_S+1);
	rep(i, strlen(str))
		s.push_back(str[i]);
	start = s.begin();
	showString(s);
	for (it = s.begin(),now=0; it != s.end(); it++) {
		if (*it == abc[now]) {
			if(now==0)
				start = it;
			now++;
			if (now == 3) {
				it = deleteS(start,it);
				if(it!=s.begin())
					it--;
				now = 0;
			}
		}
		else if(now>0){
			now = 0;
			if(it!=s.begin())
			it--;
		}
	}
	showString(s);
	return 0;
}
*/