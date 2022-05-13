#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 100 //MAX_NUM ����

#include<stdio.h> //��� ���� ����
#include<stdlib.h> // String ��� ���� ����


typedef struct {    //����ü ����
	int Corona;  //�ڷγ� ���� Ȯ��
	char name[20]; // �̸� ����
	int number; // ���� ����
	char date[10]; // ��¥ ����
}patient;

void insert(patient* ptr, int* num); //�Է� �Լ�
int delete(patient* ptr, int* num); // ���� �Լ�
int search(patient* ptr, int* num); // Ž�� �Լ�
int printAll(patient* ptr, int* num); // ��ü ���� �Լ�


int main(void) //���� �Լ�
{

	int buff; //�޴� ����

	patient user[MAX_NUM]; // ����ü �迭 ����

	int person = 0; // �迭 ���� ����
	int check = 0; //  �޴� ����

	while (1)
	{
		do {
			printf(" \n\n***** MENU ***** \n");
			printf("1. �Է� \n");
			printf("2. �˻� \n");
			printf("3. ���� \n");
			printf("4. ��� \n");
			printf("5. EXIT \n");

			printf("��ȣ�� ������ : ");
			check = scanf("%d", &buff); // �޴� ����

			while (getchar() != '\n');//�ٹٲ� �Ǳ� ������ ����

		} while (buff < 1 || buff>5 || check == 0); // ����� �� ���� �Է� �� ������ ����

		if (buff == 1) // buff�� 1�� ���
		{
			printf("\n �Է� \n");
			insert(user, &person); //�Է� �Լ�
		}
		else if (buff == 2) // buff�� 2�� ���
		{
			printf("\n �˻� \n");
			search(user, &person); // Ž�� �Լ�
		}
		else if (buff == 3) // buff�� 3�� ���
		{
			printf("\n ���� \n");
			delete(user, &person); // ���� �Լ�
		}
		else if (buff == 4) // buff�� 4�� ���
		{
			printf("\n ��� \n");
			printAll(user, &person); // ��� �Լ�
		}
		else if (buff == 5) // buff�� 5�� ���
		{
			printf("\n EXIT \n"); // ������
			return 0;
		}
	}

	return 0;
}

void insert(patient* ptr, int* num) //�Է� �Լ�
{

	char name[20]; // �̸�
	char date[10]; // ��¥
	int Corona; // �ڷγ� ����
	int number = *num + 1; // ȯ�� ����


	printf("�̸��� �Է��ϼ��� : "); gets_s(name, sizeof(name));
	printf("��¥�� �Է��ϼ��� : "); scanf("%s", date);
	printf("�ڷγ��Դϱ�?(Yes�� 1, No�� 0) "); scanf("%d", &Corona);


	strcpy(ptr[*num].name, name); // ������ �迭�� �̸� ����
	strcpy(ptr[*num].date, date); // ������ �迭�� ��¥ ����
	ptr[*num].Corona = Corona; // ������ �迭�� �ڷγ� ���� Ȯ�� ���� ����
	ptr[*num].number = number; // ������ �迭�� ȯ�� ���� ����

	printf("\n������ �Է� �Ϸ�\n");
	(*num)++;
}

int delete(patient* ptr, int* num) // ���� �Լ�
{
	int i, j; // for���� ���� ���� ����
	char name[20]; // �̸� �Է�


	printf("Input Name : ");    printf("�̸��� �Է��ϼ��� : "); gets_s(name, sizeof(name)); // �̸� �Է� �ޱ�
	while (1) {
		int a = *num;
		for (i = 0; i < a; i++) // �Է��� �̸��� ���� �迭 Ž��
		{
			if (strcmp(ptr[i].name, name) == 0) // ã�� ���
			{
				printf("������ ���� �Ϸ�\n");
				for (j = i + 1; j < *num; j++) // �� ���� ȯ�ڵ��� ��ȣ�� ������ ����ִ� for��.
				{

					strcpy(ptr[j - 1].name, ptr[j].name);
					strcpy(ptr[j - 1].date, ptr[j].date);
					ptr[j - 1].Corona = ptr[j].Corona;
					ptr[j - 1].number = ptr[j].number;

				}

				(*num)--; // ȯ�ڰ� �Ѹ� �پ����� ǥ��.

			}
		}
		break;
	}
	return;
	
}

int search(patient* ptr, int* num) // Ž�� �Լ�
{
	int i;
	char name[20]; // �Է¹��� �̸� ����


	printf("Input Name : ");     printf("�̸��� �Է��ϼ��� : "); gets_s(name, sizeof(name)); // �̸� �Է� �ޱ�

	for (i = 0; i < *num; i++) // �Է��� �̸��� ã�� for��
	{
		if (strcmp(ptr[i].name, name) == 0) // �̸��� ���� ���
		{
			if (ptr[i].Corona == 1) //�ڷγ� ���ο� ���� �ڷγ� ȯ�� OR �ڷγ� ȯ�ڰ� �ƴմϴ� ���
			{
				printf("�ڷγ� ȯ���Դϴ�.\n");
			}
			else
			{
				printf("�ڷγ� ȯ�ڰ� �ƴմϴ�.\n");
			}
			printf("��ȣ : %d\n", ptr[i].number);
			printf("��¥ : %s\n", ptr[i].date);
			printf("�̸� : %s\n", ptr[i].name);

		}
	}
	return;
}

int printAll(patient* ptr, int* num) // ��� �Լ�
{
	int i;


	for (i = 0; i < *num; i++) // �Էµ� ��� �迭�� ��ҵ��� ����ϱ� ���� for��
	{
		if (ptr[i].Corona == 1)
		{
			printf("�ڷγ� ȯ���Դϴ�.\n"); // �ڷγ� ���ο� ���� �ڷγ� ȯ�� OR �ڷγ� ȯ�ڰ� �ƴմϴ� ���
		}
		else
		{
			printf("�ڷγ� ȯ�ڰ� �ƴմϴ�.\n");
		}
		printf("��ȣ : %d\n", ptr[i].number);
		printf("��¥ : %s\n", ptr[i].date);
		printf("�̸� : %s\n\n", ptr[i].name);

	}

	return;
}