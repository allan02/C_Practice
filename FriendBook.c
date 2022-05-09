#define MAX_NAME_LEN 20
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char name[MAX_NAME_LEN];
}friend_info_t;


typedef struct NODE {
	friend_info_t friend;
	struct NODE *next;
}node_t;


int num_of_friends = 0;
node_t head;
node_t *tail = NULL;

void add() {
	node_t *p;
	p = (node_t *)malloc(sizeof(node_t));
	if (p) {
		printf("\nInput friend's name : ");
		gets(p->friend.name);
		p->next = NULL;
		if (head.next == NULL) {
			head.next = p;
			tail = p;
			num_of_friends++;
		}
		else {
			if (tail->next == NULL) {
				tail->next = p;
				tail = p;
				num_of_friends++;
			}
			else {
				printf("\nError in linked-list");
				free(p);
			}
		}
	}
	else {
		printf("\nError to allocate memory");
	}
}

void show() {
	printf("\nYou have %d friends", num_of_friends);
	printf("\n--------------------------");
	node_t *curr = &head;
	while (curr->next != NULL) {
		curr = curr->next;
		printf("\n\t%s", curr->friend.name);
	}
	printf("\n--------------------------\n\n");
}


void delete() {
	char dfriend[MAX_NAME_LEN];
	printf("\nInput friend's name to delete : ");
	gets(dfriend);
	node_t *curr = &head;
	node_t *prev;
	while (curr->next) {
		prev = curr;
		curr = curr->next;
		if (!strcmp(curr->friend.name, dfriend)) {
			prev->next = curr->next;
			free(curr);
			// Finish process
			num_of_friends--;
			return;
		}
	}
}

void insert() {
	char pfriend[MAX_NAME_LEN];
	node_t *curr = &head;
	node_t *prev, *p;
	p = (node_t *)malloc(sizeof(node_t));
	if (p) {
		printf("\nInput new friend's name : ");
		gets(p->friend.name);
		printf("\nInsert before : ");
		gets(pfriend);
		while (curr->next) {
			prev = curr;
			curr = curr->next;
			if (!strcmp(curr->friend.name, pfriend)) {
				p->next = prev->next;
				prev->next = p;
				num_of_friends++;
				return;
			}
		}
	}
	else {
		printf("\nError to allocate memory");
	}
}


int main() {
	int buff;
	while (1)
	{
		printf("\n---- FriendBook ----");
		printf("\n1. Add new friend");
		printf("\n2. Show all friends");
		printf("\n3. Delete a friend"); 
		printf("\n4. Insert a friend");
		printf("\n0. Exit");
		printf("\nSelect a menu : ");
		
		scanf("%d", &buff);
		while (getchar() != '\n');

		if (buff == 1)
		{
			printf("\nAdd new friend \n");
			add();
		}
		else if (buff == 2)
		{
			printf("\nShow all friends \n");
			show();
		}
		else if (buff == 3)
		{
			printf("\Delete friends\n");
			delete();
		}
		else if (buff == 4)
		{
			printf("\Insert friends\n");
			insert();
		}
		else if (buff == 0)
		{
			printf("\n EXIT \n");
			return 0;
		}



	}
}

