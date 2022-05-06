

#include <stdio.h>
#include <stdlib.h>

struct NODE //����ü ����
{
	struct NODE* llink;
	struct NODE* rlink;
	int data;

};

struct NODE* head;
struct NODE* tail;

//��� ���� �Լ�
struct NODE* makenode(int value) {
	struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
	node->llink = NULL;
	node->data = value;
	node->rlink = NULL;
	return node;
}

//��� �Լ�
void print() {
	struct NODE *p;
	p = head;
	while (p->rlink != tail) {
		printf("%d-->", p->data);
		p = p->rlink;
	}
	printf("%d", p->data);
}

//�ʱ�ȭ �Լ�
void init() {
	head = (struct NODE*)malloc(sizeof(struct NODE));
	tail = (struct NODE*)malloc(sizeof(struct NODE));
	head->data = 0;
	tail->data = 0;

	head->rlink = tail;
	head->llink = head;
	tail->rlink = tail;
	tail->llink = head;
}

//�ڷκ��� ��� �����ϴ� �Լ�
void push_back(int value) {
	struct NODE* newnode = makenode(value);
	struct NODE* p;
	p = tail;
	p->llink->rlink = newnode;
	newnode->llink = p->llink;
	p->llink = newnode;
	newnode->rlink = p;
}


//��� �����ϴ� �Լ�
void removenode(int value) {
	struct NODE* p;
	p = head->rlink;
	while (p->rlink != tail) {
		if (p->data == value) {
			p->rlink->llink = p->llink;
			p->llink->rlink = p->rlink;
			free(p);
			return;
		}
		p = p->rlink;
	}
}

//main�Լ�
int main() {
	init(); //head�� tail �ʱ�ȭ (data = 0)
	push_back(10); //10 �߰�
	push_back(30); //30 �߰�
	push_back(50); //50 �߰�
	print();  //���
	removenode(10);
	printf("\nAfter remove 10\n");
	print();
	return 0;
}
