#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_NAME_LEN 20

struct linked_list
{
	char name[MAX_NAME_LEN];
	struct linked_list *next;
	struct linked_list *previous;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

node * getNewNode(char * val);
void insert_at_head(char * value);
void insert_at_tail(char * value);
void insert_at_middle(char * value, char * name);
void deleteNode(char * name);
void printLinkedListForward();
void printLinkedListBackward();

//bool isValueAvailable(char * value);


int main()
{
	int buff;
	while (1) {

		printf("\n---- FriendBook ----");
		printf("\n1. Insert At Head");
		printf("\n2. Insert At Tail");
		printf("\n3. Insert At Middle");
		printf("\n4. Delete Node");
		printf("\n5. Print Forward");
		printf("\n6. Print Backward");
		printf("\n0. Exit");
		printf("\nSelect a menu : ");

		scanf("%d", &buff);
		while (getchar() != '\n');

		if (buff == 1)
		{
			char na[MAX_NAME_LEN];
			printf("\nInsert At Head\n");
			printf("\nInput friend's name : ");
			gets(na);
			insert_at_head(na);

		}
		else if (buff == 2)
		{
			char na[MAX_NAME_LEN];
			printf("\nInsert At Tail\n");
			printf("\nInput friend's name : ");
			gets(na);
			insert_at_tail(na);
		}
		else if (buff == 3)
		{
			char na[MAX_NAME_LEN];
			char na2[MAX_NAME_LEN];

			printf("\nInsert At Middle\n");
			printf("\nInput friend's name : ");
			gets(na);

			printf("\nInput Name for Insert : \n");
			gets(na2);
			insert_at_middle(na, na2);
		}

		else if (buff == 4)
		{
			char na[MAX_NAME_LEN];
			printf("\Input Name for Delete\n");
			gets(na);
			deleteNode(na);
		}
		else if (buff == 5)
		{
			printf("\Print Forward\n");
			printLinkedListForward();
		}
		else if (buff == 6)
		{
			printf("\Print Backward\n");
			printLinkedListBackward();
		}
		else if (buff == 0)
		{
			printf("\n EXIT \n");
			return 0;
		}



	}
	/*
	//Searching the value in the list
	int value = h;
	if (isValueAvailable(value) == true)
		printf("%d found in the list.\n\n", value);
	else
		printf("%d not found in the list.\n\n", value);

	*/
	return 0;
}


/*
	User defined functions
*/

//create a new node and returns to caller
node* getNewNode(char * val)
{
	node * temp_node;
	temp_node = (node *)malloc(sizeof(node));
	strcpy(temp_node->name, val);

	temp_node->next = NULL;
	temp_node->previous = NULL;

	return temp_node;
}

//Insert a node at front of the list. This node will be the new head
void insert_at_head(char * value)
{
	node *newNode = getNewNode(value);


	if (head == NULL) //For the 1st element
	{
		//For now, newNode is the only one node of list
		//So it it is head and also tail
		head = newNode;
		tail = newNode;
		return;
	}

	//newNode will be the NEW HEAD of list.
	//So it'll point to head as 'next node'
	newNode->next = head;
	head->previous = newNode; //before, the previous node of head was NULL. but now newNode

	head = newNode; //update the global node 'head' by newNode
}

//Insert a node after last node
void insert_at_tail(char * value)
{
	node *newNode = getNewNode(value);

	if (head == NULL) //For the 1st element
	{
		head = newNode;
		tail = newNode;
		return;
	}

	//'tail' is a global node. 'newNode' will be the next node of tail.
	//finally newNode will be the 'tail' node of the list
	tail->next = newNode;
	newNode->previous = tail; //'newNode' point 'tail' node as previous node

	tail = newNode; // update the global node 'tail' by newNode.
}

//Insert a node at front of the list. This node will be the new head
//Insert a node at front of the list. This node will be the new head
void insert_at_middle(char * value, char * name)
{
	node *newNode = getNewNode(value);

	if (head == NULL) //For the 1st element
	{
		//For now, newNode is the only one node of list
		//So it it is head and also tail
		head = newNode;
		tail = newNode;
		return;
	}

	node *temp = (node *)malloc(sizeof(node));
	temp = head;
	
	//find the position where our newNode will put
	while ( strcmp(temp->name, name) && temp->next != NULL) {
		temp = temp->next;
	}

	newNode->next = temp->next; //newNode's next node will be the next node of temp
	newNode->previous = temp; //newNode's previous node will be the temp node

	if (temp->next)
		temp->next->previous = newNode; //newNode will be the previous node of temp->next node

	temp->next = newNode; //update the next node of temp
}


// delete any node of list according to position
void deleteNode(char * name) {

	node *temp = (node*)malloc(sizeof(node));
	node *tempAnother = (node*)malloc(sizeof(node));

	temp = head;

	while (strcmp(temp->name, name) && temp->next != NULL) { // find the desired node to delete
		temp = temp->next;
	}

	if (temp->next != NULL) { // desired position found

		// temp node will be deleted
		
		tempAnother = temp->previous;
		tempAnother->next = temp->next;

		if (temp->next == NULL) // desired node is the last node of list
			tail = tempAnother;
		else
			temp->next->previous = tempAnother; // tempAnother is the previous node of temp->next node

		free(temp);
	}
	else
		printf("\nDesired position does not exist! Position\n");
}


// print the list in forward order
void printLinkedListForward()
{
	printf("\nYour updated linked list in FORWARD ORDER:\n");

	node *myList;
	myList = head;

	while (1)
	{
		if (head == NULL || tail == NULL) break;

		printf("%s ", myList->name);

		if (myList == tail) break;

		myList = myList->next;
	}
	puts("\n");
}

// print the list in reverse order
void printLinkedListBackward()
{
	printf("\nYour full linked list in REVERSE ORDER:\n");

	node *myList;
	myList = tail;

	while (1)
	{
		if (head == NULL || tail == NULL) break;

		printf("%s ", myList->name);

		if (myList->previous == NULL) break;

		myList = myList->previous;
	}
	puts("\n");
}


/*
//This function search the value in the list
bool isValueAvailable(int value)
{
	node *p = head;
	while (p != NULL)
	{
		if (p->number == value)
		{
			return true;
		}
		else
		{
			p = p->next;
		}
	}
	return 0;
}
*/