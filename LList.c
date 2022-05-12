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
	a = dlist->head; //a에 첫노드 주소 전달
	if (dlist->head == NULL) { //리스트가 비어있는 경우
		printf("리스트 공백\n");
		return NULL; //NULL주소 반환
	}
	for (i = 0; i < (pos - 1); i++) //리스트가 비어있지 않는 경우와 pos의 주소를 반환하기 위한 반복문
	{
		temp = a->rlink;
		a = temp;
	}
	return a; //해당 pos주소 반환

}


DLlistNode* create_node(int entrance_year, char name[MAX_SIZE], float GPA, DLlistNode* llink, DLlistNode* rlink) {
	DLlistNode* new_node;

	new_node = (DLlistNode*)malloc(sizeof(DLlistNode));
	if (new_node == NULL) {
		printf("%s\n", "메모리 할당 오류");
		exit(1); // 메모리 오류가 발생하면 프로그램 종료
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
	DLlistNode* a; //각 노드의 주소를 참조하기 위한 임시 head
	int i = 0; //노드 개수
	a = dlist->head;
	if (dlist->head == NULL) //리스트가 비어있는 경우
		return i; //0을 반환
	else { //리스트가 비어있지 않은경우
		i++; //만약 리스트에 노드가 1개 인경우
		while (1) { //리스트에 노드가 몇개인지 카운트를 위한 반복문
			temp = a->rlink; //현재 a가 가르키는 노드의 다음 노드의 주소를 받음
			if (temp == NULL) //a가 마지막 노드주소를 가지고 있음
				break; //반복문 stop
			a = temp; //a가 각노드를 순차적으로 참조할수 있게 해줌
			i++; //1증가
		}
		return i;//개수반환
	}
}



DLlistNode* delete_node_pos(DLlistType* dlist, int pos) {
	DLlistNode* a; //pos의 주소
	DLlistNode* b;
	DLlistNode* c;
	if (dlist->head == NULL) { //리스트가 비어있으면
		printf("공백 삭제 오류\n");
		return NULL;
	}
	a = node_position(pos, dlist); //pos의 주소 a에 반환
	if (a == NULL) //사용 가능한 위치가 아님
	{
		printf("position 오류: position:1 ~ %d 선택\n", get_length(dlist));
		return a; //NULL반환
	}
	if ((1 < pos) && ((pos <= get_length(dlist) - 1))) { //사용 가능한 위치일 경우, 리스트의 첫번째와 끝은 제외
		b = a->llink; //a 노드를 리스트에서 제거해주기 위한 과정
		b->rlink = a->rlink;
		c = a->rlink;
		c->llink = a->llink;
	}
	if (pos == 1) { //첫 번째 노드일경우 head를 바꾸기 위한 과정
		b = a->rlink;
		b->llink = NULL;
		dlist->head = a->rlink;
	}
	if (pos == get_length(dlist)) { //마지막 노드일 경우
		b = a->llink;
		b->rlink = NULL;
	}
	return a; //삭제 주소 반환
}


void insert_node_pos(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA) {
	DLlistNode* newnode; //새로 생성된 노드 주소
	DLlistNode* a;
	DLlistNode* b;
	if (dlist->head == NULL) { //리스트가 비어있는 경우
		newnode = create_node(entrance_year, name, GPA, NULL, NULL); //첫번째에 연결
		dlist->head = newnode; //head 변경
	}
	else if ((1 < pos) && (pos <= (get_length(dlist) - 1))) { //리스트가 비어있지 않는 경우
		a = node_position(pos, dlist); //pos주소 반환
		newnode = create_node(entrance_year, name, GPA, a->llink, a); //노드 생성
		b = a->llink; //노드 삽입
		b->rlink = newnode;
		a->llink = newnode;

	}
	else if (pos == 1) { //pos가 1일경우
		a = node_position(pos, dlist); //pos주소 반환
		newnode = create_node(entrance_year, name, GPA, NULL, a); //삽입
		a->llink = newnode;
		dlist->head = newnode;
	}
	else if (pos == get_length(dlist)) { //pos가 리스트의 마지막노드일경우
		a = node_position(pos, dlist);
		newnode = create_node(entrance_year, name, GPA, a->llink, a);
		a->llink->rlink = newnode;
		a->llink = newnode;
	}
	else if (pos == get_length(dlist) + 1) { //pos가 리스트의 길이보다 1이 더큰경우
		a = node_position(pos - 1, dlist);
		newnode = create_node(entrance_year, name, GPA, a, NULL);
		a->rlink = newnode;
	}
	else { //pos이 리스트 길이+1 초과일 경우, 출력후 함수 종료(프로그램종료x)
		printf("position 오류: position:1 ~ %d 선택\n", get_length(dlist) + 1);
	}
}


void modification(DLlistType* dlist, int pos, int entrance_year, char name[MAX_SIZE], float GPA) {
	DLlistNode* a; //pos의 주소
	if (dlist->head == NULL) { //리스트가 비어있으면
		printf("공백 삭제 오류\n");
		return NULL;
	}
	a = node_position(pos, dlist); //pos의 주소 a에 반환
	if (a == NULL) //사용 가능한 위치가 아님
	{
		printf("position 오류: position:1 ~ %d 선택\n", get_length(dlist));
		return a; //NULL반환
	}
	a->st_entrance_year = entrance_year;
	strcpy(a->st_name, name);
	a->st_GPA = GPA;
}

DLlistNode* cut_list_pos(DLlistType* dlist, int pos1, int pos2) {
	DLlistNode* a; //pos의 주소
	DLlistNode* b;
	DLlistNode* c;
	DLlistNode* d;

	if (dlist->head == NULL) { //리스트가 비어있으면
		printf("공백 삭제 오류\n");
		return NULL;
	}

	a = node_position(pos1 - 1, dlist); //pos의 주소 a에 반환
	b = node_position(pos2 + 1, dlist);
	c = node_position(pos1, dlist);
	d = node_position(pos2, dlist)

	

;	if (a == NULL || b == NULL) //사용 가능한 위치가 아님
	{
		printf("position 오류: position:1 ~ %d 선택\n", get_length(dlist));
		return a; //NULL반환
	}
	else if (pos1 > 1) {
		a = node_position(pos1 - 1, dlist); //pos의 주소 a에 반환
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
	return c; //삭제 주소 반환
}


void insert_list_pos(DLlistType* dlist1, DLlistType* dlist2, int pos) {
	DLlistNode* a;
	DLlistNode* b;
	DLlistNode* temp1;
	DLlistNode* temp2;


	if (dlist1->head == NULL) { //리스트가 비어있는 경우

		dlist1->head = dlist2 ->head; //head 변경
	}
	else if ((1 < pos) && (pos <= (get_length(dlist1) - 1))) { //리스트가 비어있지 않는 경우
		a = node_position(pos, dlist1); //pos주소 반환
		b = a->llink; //노드 삽입
		b->rlink = dlist2 -> head;
		a->llink = dlist2 -> head;

	}
	else if (pos == 1) { //pos가 1일경우
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

	// 리스트 dList1에  4명 학생 정보 추가.
	printf("\ndList1 student information by insert_node_pos: \n");
	insert_node_pos(&dList1, 1, st_array[0].st_entrance_year, st_array[0].st_name, st_array[0].st_GPA);
	insert_node_pos(&dList1, 1, st_array[1].st_entrance_year, st_array[1].st_name, st_array[1].st_GPA);
	insert_node_pos(&dList1, 1, st_array[2].st_entrance_year, st_array[2].st_name, st_array[2].st_GPA);
	insert_node_pos(&dList1, 1, st_array[3].st_entrance_year, st_array[3].st_name, st_array[3].st_GPA);

	// 리스트 dList1의 학생 정보 출력.
	display(&dList1);

	// 리스트 dList1의 길이.
	printf("dList1 length: %d \n\n", get_length(&dList1));

	//리스트 dList1의 맨 처음 노드 하나를 삭제.
	removed_node = delete_node_pos(&dList1, 1);

	// 리스트 dList1에서 삭제된 노드의 학생 정보 출력.
	printf("Deletion by delete_node_pos(&dList1, 1) : \n");
	printf("Entrance year: %d, student name: %s, student GPA : %0.2f \n\n",
		removed_node->st_entrance_year, removed_node->st_name, removed_node->st_GPA);
	free(removed_node);

	// 리스트 dList1에서 노드의 데이터 수정 및 출력
	printf("Modification by modification(&dList1, 2, 2016, cname, 3.7) : \n");
	modification(&dList1, 2, 2016, cname, 3.7);
	display(&dList1);

	// 리스트 dList2에  6명 학생 정보 추가.
	printf("\ndList2 student information by insert_node_pos: \n");
	insert_node_pos(&dList2, 1, st_array[4].st_entrance_year, st_array[4].st_name, st_array[4].st_GPA);
	insert_node_pos(&dList2, 1, st_array[5].st_entrance_year, st_array[5].st_name, st_array[5].st_GPA);
	insert_node_pos(&dList2, 1, st_array[6].st_entrance_year, st_array[6].st_name, st_array[6].st_GPA);
	insert_node_pos(&dList2, 1, st_array[7].st_entrance_year, st_array[7].st_name, st_array[7].st_GPA);
	insert_node_pos(&dList2, 1, st_array[8].st_entrance_year, st_array[8].st_name, st_array[8].st_GPA);
	insert_node_pos(&dList2, 1, st_array[9].st_entrance_year, st_array[9].st_name, st_array[9].st_GPA);
	display(&dList2);

	// 리스트 dList3에 있는 3명 학생 정보 출력
	printf("\ndList3 student information by cut_list_pos: \n");
	dList3.head = cut_list_pos(&dList2, 1, 3);
	display(&dList3);

	// 리스트 dList1에 리스트 dList2를 추가
	printf("\ndList1 student information after insert_list_pos(&dList1, &dList2, 1): \n");
	insert_list_pos(&dList1, &dList2, 1);
	display(&dList1);

	return 0;
}

