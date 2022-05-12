#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct DLlistNode {
	int st_entrance_year;
	char st_name[MAX_SIZE];
	float st_GPA;

	struct DLlistNode* llink;
	struct DLlistNode* rlink;
} DLlistNode;

typedef struct DLlistType {
	DLlistNode* head;
} DLlistType;


int get_length(DLlistType* dlist);
DLlistNode* delete_node_pos(DLlistType* dlist, int pos);
void insert_node_pos(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA);
void modification(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA);
DLlistNode* cut_list_pos(DLlistType* dlist, int pos1, int pos2);
void insert_list_pos(DLlistType* dlist1, DLlistType* dlist2, int pos);


void init(DLlistType* dq) {
	dq->head = NULL;
}


int is_empty(DLlistType* dlist) {
	if (dlist->head == NULL) return TRUE;
	else return FALSE;
}


void display(DLlistType* dlist) {
	DLlistNode* tmp = NULL;

	for (tmp = dlist->head; tmp != NULL; tmp = tmp->rlink) {
		printf("%d, ", tmp->st_entrance_year);
		printf("%s, ", tmp->st_name);
		printf("%.2f", tmp->st_GPA);
		printf("\n");
	}
	printf("\n");
}

DLlistNode* node_position(int pos, DLlistType* dlist) {
	DLlistNode* a;
	DLlistNode* temp;
	int i = 0;
	a = dlist->head; //a�� ù��� �ּ� ����
	if (dlist->head == NULL) { //����Ʈ�� ����ִ� ���
		printf("����Ʈ ����\n");
		return NULL; //NULL�ּ� ��ȯ
	}
	for (i = 0; i < (pos - 1); i++) //����Ʈ�� ������� �ʴ� ���� pos�� �ּҸ� ��ȯ�ϱ� ���� �ݺ���
	{
		temp = a->rlink;
		a = temp;
	}
	return a; //�ش� pos�ּ� ��ȯ

}


DLlistNode* create_node(int entrance_year, char name[MAX_SIZE], float GPA, DLlistNode* llink, DLlistNode* rlink) {
	DLlistNode* new_node;

	new_node = (DLlistNode*)malloc(sizeof(DLlistNode));
	if (new_node == NULL) {
		printf("%s\n", "�޸� �Ҵ� ����");
		exit(1); // �޸� ������ �߻��ϸ� ���α׷� ����
	}
	else {
		new_node->st_entrance_year = entrance_year;
		strcpy(new_node->st_name, name);
		new_node->st_GPA = GPA;
		new_node->llink = llink;
		new_node->rlink = rlink;
	}

	return new_node;
}


int get_length(DLlistType* dlist) {
	DLlistNode* temp;
	DLlistNode* a; //�� ����� �ּҸ� �����ϱ� ���� �ӽ� head
	int i = 0; //��� ����
	a = dlist->head;
	if (dlist->head == NULL) //����Ʈ�� ����ִ� ���
		return i; //0�� ��ȯ
	else { //����Ʈ�� ������� �������
		i++; //���� ����Ʈ�� ��尡 1�� �ΰ��
		while (1) { //����Ʈ�� ��尡 ����� ī��Ʈ�� ���� �ݺ���
			temp = a->rlink; //���� a�� ����Ű�� ����� ���� ����� �ּҸ� ����
			if (temp == NULL) //a�� ������ ����ּҸ� ������ ����
				break; //�ݺ��� stop
			a = temp; //a�� ����带 ���������� �����Ҽ� �ְ� ����
			i++; //1����
		}
		return i;//������ȯ
	}
}



DLlistNode* delete_node_pos(DLlistType* dlist, int pos) {
	DLlistNode* a; //pos�� �ּ�
	DLlistNode* b;
	DLlistNode* c;
	if (dlist->head == NULL) { //����Ʈ�� ���������
		printf("���� ���� ����\n");
		return NULL;
	}
	a = node_position(pos, dlist); //pos�� �ּ� a�� ��ȯ
	if (a == NULL) //��� ������ ��ġ�� �ƴ�
	{
		printf("position ����: position:1 ~ %d ����\n", get_length(dlist));
		return a; //NULL��ȯ
	}
	if ((1 < pos) && ((pos <= get_length(dlist) - 1))) { //��� ������ ��ġ�� ���, ����Ʈ�� ù��°�� ���� ����
		b = a->llink; //a ��带 ����Ʈ���� �������ֱ� ���� ����
		b->rlink = a->rlink;
		c = a->rlink;
		c->llink = a->llink;
	}
	if (pos == 1) { //ù ��° ����ϰ�� head�� �ٲٱ� ���� ����
		b = a->rlink;
		b->llink = NULL;
		dlist->head = a->rlink;
	}
	if (pos == get_length(dlist)) { //������ ����� ���
		b = a->llink;
		b->rlink = NULL;
	}
	return a; //���� �ּ� ��ȯ
}


void insert_node_pos(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA) {
	DLlistNode* newnode; //���� ������ ��� �ּ�
	DLlistNode* a;
	DLlistNode* b;
	if (dlist->head == NULL) { //����Ʈ�� ����ִ� ���
		newnode = create_node(entrance_year, name, GPA, NULL, NULL); //ù��°�� ����
		dlist->head = newnode; //head ����
	}
	else if ((1 < pos) && (pos <= (get_length(dlist) - 1))) { //����Ʈ�� ������� �ʴ� ���
		a = node_position(pos, dlist); //pos�ּ� ��ȯ
		newnode = create_node(entrance_year, name, GPA, a->llink, a); //��� ����
		b = a->llink; //��� ����
		b->rlink = newnode;
		a->llink = newnode;

	}
	else if (pos == 1) { //pos�� 1�ϰ��
		a = node_position(pos, dlist); //pos�ּ� ��ȯ
		newnode = create_node(entrance_year, name, GPA, NULL, a); //����
		a->llink = newnode;
		dlist->head = newnode;
	}
	else if (pos == get_length(dlist)) { //pos�� ����Ʈ�� ����������ϰ��
		a = node_position(pos, dlist);
		newnode = create_node(entrance_year, name, GPA, a->llink, a);
		a->llink->rlink = newnode;
		a->llink = newnode;
	}
	else if (pos == get_length(dlist) + 1) { //pos�� ����Ʈ�� ���̺��� 1�� ��ū���
		a = node_position(pos - 1, dlist);
		newnode = create_node(entrance_year, name, GPA, a, NULL);
		a->rlink = newnode;
	}
	else { //pos�� ����Ʈ ����+1 �ʰ��� ���, ����� �Լ� ����(���α׷�����x)
		printf("position ����: position:1 ~ %d ����\n", get_length(dlist) + 1);
	}
}


void modification(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA) {
	DLlistNode* a; //pos�� �ּ�
	if (dlist->head == NULL) { //����Ʈ�� ���������
		printf("���� ���� ����\n");
		return NULL;
	}
	a = node_position(pos, dlist); //pos�� �ּ� a�� ��ȯ
	if (a == NULL) //��� ������ ��ġ�� �ƴ�
	{
		printf("position ����: position:1 ~ %d ����\n", get_length(dlist));
		return a; //NULL��ȯ
	}
	a->st_entrance_year = entrance_year;
	strcpy(a->st_name, name);
	a->st_GPA = GPA;
}

DLlistNode* cut_list_pos(DLlistType* dlist, int pos1, int pos2) {
	DLlistNode* a; //pos�� �ּ�
	DLlistNode* b;
	DLlistNode* c;
	DLlistNode* d;

	if (dlist->head == NULL) { //����Ʈ�� ���������
		printf("���� ���� ����\n");
		return NULL;
	}

	a = node_position(pos1 - 1, dlist); //pos�� �ּ� a�� ��ȯ
	b = node_position(pos2 + 1, dlist);
	c = node_position(pos1, dlist);
	d = node_position(pos2, dlist)

	

;	if (a == NULL || b == NULL) //��� ������ ��ġ�� �ƴ�
	{
		printf("position ����: position:1 ~ %d ����\n", get_length(dlist));
		return a; //NULL��ȯ
	}
	else if (pos1 > 1) {
		a = node_position(pos1 - 1, dlist); //pos�� �ּ� a�� ��ȯ
		b = node_position(pos2 + 1, dlist);
		c = node_position(pos1, dlist);
		d = node_position(pos2, dlist);

		b->llink = a->rlink;
		c->llink = NULL;
		d->rlink = NULL;
	}
	else if (pos1 == 1) {
		b = node_position(pos2 + 1, dlist);
		c = node_position(pos1, dlist);
		d = node_position(pos2, dlist);

		dlist -> head = b;
		c->llink = NULL;
		d->rlink = NULL;

	}
	return c; //���� �ּ� ��ȯ
}


void insert_list_pos(DLlistType* dlist1, DLlistType* dlist2, int pos) {
	DLlistNode* a;
	DLlistNode* b;
	DLlistNode* temp1;
	DLlistNode* temp2;


	if (dlist1->head == NULL) { //����Ʈ�� ����ִ� ���

		dlist1->head = dlist2 ->head; //head ����
	}
	else if ((1 < pos) && (pos <= (get_length(dlist1) - 1))) { //����Ʈ�� ������� �ʴ� ���
		a = node_position(pos, dlist1); //pos�ּ� ��ȯ
		b = a->llink; //��� ����
		b->rlink = dlist2 -> head;
		a->llink = dlist2 -> head;

	}
	else if (pos == 1) { //pos�� 1�ϰ��
		a = node_position(pos, dlist1);
		temp1 = node_position(get_length(dlist2), dlist2);
		temp1->rlink = a;
		dlist1->head = node_position(pos, dlist2);
	}
}





int main() {
	DLlistType  dList1, dList2, dList3;
	char cname[MAX_SIZE] = "Mark";
	DLlistNode* removed_node = NULL;

	DLlistNode st_array[MAX] = {
		{ 2012, "Chris", 4.2, NULL, NULL },
		{ 2015, "Tom", 3.2, NULL, NULL },
		{ 2017, "John", 3.5, NULL, NULL },
		{ 2012, "James", 2.3, NULL, NULL },
		{ 2013, "Bob", 2.7, NULL, NULL },
		{ 2016, "Peter", 4.3, NULL, NULL },
		{ 2019, "Jacob", 3.9, NULL, NULL },
		{ 2014, "Kevin", 2.6, NULL, NULL },
		{ 2016, "Paul", 3.4, NULL, NULL },
		{ 2018, "Nick", 2.8, NULL, NULL }
	};

	init(&dList1); init(&dList2); init(&dList3);

	// ����Ʈ dList1��  4�� �л� ���� �߰�.
	printf("\ndList1 student information by insert_node_pos: \n");
	insert_node_pos(&dList1, 1, st_array[0].st_entrance_year, st_array[0].st_name, st_array[0].st_GPA);
	insert_node_pos(&dList1, 1, st_array[1].st_entrance_year, st_array[1].st_name, st_array[1].st_GPA);
	insert_node_pos(&dList1, 1, st_array[2].st_entrance_year, st_array[2].st_name, st_array[2].st_GPA);
	insert_node_pos(&dList1, 1, st_array[3].st_entrance_year, st_array[3].st_name, st_array[3].st_GPA);

	// ����Ʈ dList1�� �л� ���� ���.
	display(&dList1);

	// ����Ʈ dList1�� ����.
	printf("dList1 length: %d \n\n", get_length(&dList1));

	//����Ʈ dList1�� �� ó�� ��� �ϳ��� ����.
	removed_node = delete_node_pos(&dList1, 1);

	// ����Ʈ dList1���� ������ ����� �л� ���� ���.
	printf("Deletion by delete_node_pos(&dList1, 1) : \n");
	printf("Entrance year: %d, student name: %s, student GPA : %0.2f \n\n",
		removed_node->st_entrance_year, removed_node->st_name, removed_node->st_GPA);
	free(removed_node);

	// ����Ʈ dList1���� ����� ������ ���� �� ���
	printf("Modification by modification(&dList1, 2, 2016, cname, 3.7) : \n");
	modification(&dList1, 2, 2016, cname, 3.7);
	display(&dList1);

	// ����Ʈ dList2��  6�� �л� ���� �߰�.
	printf("\ndList2 student information by insert_node_pos: \n");
	insert_node_pos(&dList2, 1, st_array[4].st_entrance_year, st_array[4].st_name, st_array[4].st_GPA);
	insert_node_pos(&dList2, 1, st_array[5].st_entrance_year, st_array[5].st_name, st_array[5].st_GPA);
	insert_node_pos(&dList2, 1, st_array[6].st_entrance_year, st_array[6].st_name, st_array[6].st_GPA);
	insert_node_pos(&dList2, 1, st_array[7].st_entrance_year, st_array[7].st_name, st_array[7].st_GPA);
	insert_node_pos(&dList2, 1, st_array[8].st_entrance_year, st_array[8].st_name, st_array[8].st_GPA);
	insert_node_pos(&dList2, 1, st_array[9].st_entrance_year, st_array[9].st_name, st_array[9].st_GPA);
	display(&dList2);

	// ����Ʈ dList3�� �ִ� 3�� �л� ���� ���
	printf("\ndList3 student information by cut_list_pos: \n");
	dList3.head = cut_list_pos(&dList2, 1, 3);
	display(&dList3);

	// ����Ʈ dList1�� ����Ʈ dList2�� �߰�
	printf("\ndList1 student information after insert_list_pos(&dList1, &dList2, 1): \n");
	insert_list_pos(&dList1, &dList2, 1);
	display(&dList1);

	return 0;
}

