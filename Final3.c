/*
** Final exam #3
** Name : À¯ÀçÇö
** Student ID : 32172698
*/


#include<stdio.h>

#define MAX_NAME_LEN 20
// Use the following data
#define SIZE_OF_DATA 5


typedef struct {
	int ID;
	int MA;
	int EN;
	// Design structure to include ID, Math & English

} grade_t;


typedef struct NODE {
	grade_t friend;
	struct NODE *next;
	// Design single linked list with grade_t
} node_t;


grade_t grades[SIZE_OF_DATA] = {
	/* ID, Math, English */
	{1, 90, 35},
	{2, 80, 90},
	{3, 75, 60},
	{4, 60, 50},
	{5, 0, 30}
};



node_t head;
node_t *tail = NULL;




int main(void)
{
	int avgma = 0;
	int avgen = 0;

	for (int i = 0; i < SIZE_OF_DATA; i++) {
		node_t *p;
		p = (node_t *)malloc(sizeof(node_t));
		if (p) {
			p->friend.ID = grades[i].ID;
			p->friend.MA = grades[i].MA;
			p->friend.EN = grades[i].EN;
			p->next = NULL;
			if (head.next == NULL) {
				head.next = p;
				tail = p;
			}
			else {
				if (tail->next == NULL) {
					tail->next = p;
					tail = p;
					
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
	
	node_t *curr = &head;
	while (curr->next != NULL) {

		curr = curr->next;
		avgma += curr->friend.MA;
		avgen += curr->friend.EN;
	}
	
	printf("Average of Math : %d\n", avgma / 5);
	printf("Average of English : %d\n\n", avgen / 5);
	
	return 0;
}

