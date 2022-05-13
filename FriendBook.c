#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 100 //MAX_NUM 정의

#include<stdio.h> //헤더 파일 선언
#include<stdlib.h> // String 헤더 파일 선언


typedef struct {    //구조체 선언
	int Corona;  //코로나 여부 확인
	char name[20]; // 이름 저장
	int number; // 순번 저장
	char date[10]; // 날짜 저장
}patient;

void insert(patient* ptr, int* num); //입력 함수
int delete(patient* ptr, int* num); // 삭제 함수
int search(patient* ptr, int* num); // 탐색 함수
int printAll(patient* ptr, int* num); // 전체 복사 함수


int main(void) //메인 함수
{

	int buff; //메뉴 선택

	patient user[MAX_NUM]; // 구조체 배열 선언

	int person = 0; // 배열 순번 결정
	int check = 0; //  메뉴 선택

	while (1)
	{
		do {
			printf(" \n\n***** MENU ***** \n");
			printf("1. 입력 \n");
			printf("2. 검색 \n");
			printf("3. 삭제 \n");
			printf("4. 출력 \n");
			printf("5. EXIT \n");

			printf("번호를 고르세요 : ");
			check = scanf("%d", &buff); // 메뉴 선택

			while (getchar() != '\n');//줄바꿈 되기 전까지 실행

		} while (buff < 1 || buff>5 || check == 0); // 제대로 된 값이 입력 될 때까지 실행

		if (buff == 1) // buff가 1일 경우
		{
			printf("\n 입력 \n");
			insert(user, &person); //입력 함수
		}
		else if (buff == 2) // buff가 2일 경우
		{
			printf("\n 검색 \n");
			search(user, &person); // 탐색 함수
		}
		else if (buff == 3) // buff가 3일 경우
		{
			printf("\n 삭제 \n");
			delete(user, &person); // 삭제 함수
		}
		else if (buff == 4) // buff가 4일 경우
		{
			printf("\n 출력 \n");
			printAll(user, &person); // 출력 함수
		}
		else if (buff == 5) // buff가 5일 경우
		{
			printf("\n EXIT \n"); // 나가기
			return 0;
		}
	}

	return 0;
}

void insert(patient* ptr, int* num) //입력 함수
{

	char name[20]; // 이름
	char date[10]; // 날짜
	int Corona; // 코로나 여부
	int number = *num + 1; // 환자 순번


	printf("이름을 입력하세요 : "); gets_s(name, sizeof(name));
	printf("날짜를 입력하세요 : "); scanf("%s", date);
	printf("코로나입니까?(Yes는 1, No는 0) "); scanf("%d", &Corona);


	strcpy(ptr[*num].name, name); // 포인터 배열에 이름 복사
	strcpy(ptr[*num].date, date); // 포인터 배열에 날짜 복사
	ptr[*num].Corona = Corona; // 포인터 배열에 코로나 여부 확인 변수 복사
	ptr[*num].number = number; // 포인터 배열에 환자 순번 복사

	printf("\n데이터 입력 완료\n");
	(*num)++;
}

int delete(patient* ptr, int* num) // 삭제 함수
{
	int i, j; // for문을 위한 변수 선언
	char name[20]; // 이름 입력


	printf("Input Name : ");    printf("이름을 입력하세요 : "); gets_s(name, sizeof(name)); // 이름 입력 받기
	while (1) {
		int a = *num;
		for (i = 0; i < a; i++) // 입력한 이름과 같은 배열 탐색
		{
			if (strcmp(ptr[i].name, name) == 0) // 찾을 경우
			{
				printf("데이터 삭제 완료\n");
				for (j = i + 1; j < *num; j++) // 뒷 순번 환자들의 번호를 앞으로 당겨주는 for문.
				{

					strcpy(ptr[j - 1].name, ptr[j].name);
					strcpy(ptr[j - 1].date, ptr[j].date);
					ptr[j - 1].Corona = ptr[j].Corona;
					ptr[j - 1].number = ptr[j].number;

				}

				(*num)--; // 환자가 한명 줄었음을 표시.

			}
		}
		break;
	}
	return;
	
}

int search(patient* ptr, int* num) // 탐색 함수
{
	int i;
	char name[20]; // 입력받을 이름 선언


	printf("Input Name : ");     printf("이름을 입력하세요 : "); gets_s(name, sizeof(name)); // 이름 입력 받기

	for (i = 0; i < *num; i++) // 입력한 이름을 찾는 for문
	{
		if (strcmp(ptr[i].name, name) == 0) // 이름이 같을 경우
		{
			if (ptr[i].Corona == 1) //코로나 여부에 따라 코로나 환자 OR 코로나 환자가 아닙니다 출력
			{
				printf("코로나 환자입니다.\n");
			}
			else
			{
				printf("코로나 환자가 아닙니다.\n");
			}
			printf("번호 : %d\n", ptr[i].number);
			printf("날짜 : %s\n", ptr[i].date);
			printf("이름 : %s\n", ptr[i].name);

		}
	}
	return;
}

int printAll(patient* ptr, int* num) // 출력 함수
{
	int i;


	for (i = 0; i < *num; i++) // 입력된 모든 배열의 요소들을 출력하기 위한 for문
	{
		if (ptr[i].Corona == 1)
		{
			printf("코로나 환자입니다.\n"); // 코로나 여부에 따라 코로나 환자 OR 코로나 환자가 아닙니다 출력
		}
		else
		{
			printf("코로나 환자가 아닙니다.\n");
		}
		printf("번호 : %d\n", ptr[i].number);
		printf("날짜 : %s\n", ptr[i].date);
		printf("이름 : %s\n\n", ptr[i].name);

	}

	return;
}