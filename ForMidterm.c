
//fseek을 이용한 스트림 위치 변환
/*
#include<stdio.h>
int main(void) {
	char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	FILE *fp; fp = fopen("alpha.txt", "w");
	if (fp) {
		fputs(str, fp);
		fclose(fp);
		fp = fopen("alpha.txt", "r");
		if (fp) {
			fseek(fp, 3, SEEK_SET);
			printf("offset 3 from SEEK_SET = %c\n", fgetc(fp));
			fseek(fp, -2, SEEK_END);
			printf("offset -2 from SEEK_END = %c\n", fgetc(fp));
			fclose(fp);
		}
	}
	return 0;
}
*/



//fscanf fprintf를 통한 입출력 연습 코드
/*
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int c;
	while (1) { 
		fscanf(stdin, "%d", &c); 
		if (c == -1)
			break; 
		fprintf(stdout, "input is %d\n", c);
	} 
	return 0; 
}
*/


/*
//define을 이용한 전처리
#include <stdio.h>
#define MAX_ARR 20

int main(void){ 
	int arr[MAX_ARR]; 
	for(int i=0;i<MAX_ARR;i++) { 
		arr[i] = i;  
	} 
	for(int i=0;i<MAX_ARR;i++) {
		printf("%d ", arr[i]);
	} 
	return 0;
}
*/



/*
//파일 읽어오기!!!

#include <stdio.h>
int main(void){
	FILE *fp;
	int c;
	fp = fopen("test.txt","r");
	if(fp) {
		while((c = fgetc(fp)) != EOF)
		{
			putchar(c);
		}
		fclose(fp);
	} else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/

/*
//파일 쓰기!!!!!!
#include <stdio.h>
int main(void){
	FILE *fp, *ft;
	int c;
	fp = fopen("test.txt","r");
	ft = fopen("test_copy.txt","w");
	if(fp && ft) {
		while((c = fgetc(fp)) != EOF)
		{
			fputc(c, ft);
		}
		fclose(fp);
		fclose(ft);}
	else {
		printf("Fail to open file\n");
	}
	return 0;
*/



/*
#include <stdio.h>
int main(void){
	FILE *fp, *ft;
	char *name="My name is Woojin Jeong";
	char *company="Dankook university";
	fp = fopen("name.txt","w");
	if(fp) {
		fputs(name, fp);
		fputc('\n', fp);
		fputs(company, fp);
		fclose(fp);}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}

*/

#include <stdio.h>
int main(void) {
	FILE *fp;
	fp = fopen("test.txt", "w");
	if (fp) {
		fputc('a', fp);
		fputc('b', fp);
		fputc('c', fp);
		fclose(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}

