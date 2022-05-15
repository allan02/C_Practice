//p15
/*
#include<stdio.h>

int main(void) {
	FILE * fp;
	fp = fopen("test.txt", "w" );
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
*/









//p16
/*
#include<stdio.h>

int main(void) {
	int c;
	FILE * fp;
	fp = fopen("test.txt", "w");
	if (fp) {
		while ((c = fgetc(fp)) != EOF) {
			putchar(c);
		}
		fclose(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/










//p17
/*
#include<stdio.h>

int main(void) {
	int c;
	FILE * fp, *ft;
	fp = fopen("test.txt", "w");
	ft = fopen("test_copy.txt", "w");
	if (fp && ft) {
		while ((c = fgetc(fp)) != EOF) {
			fputs(c, ft);
		}
		fclose(fp);
		fclose(ft);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/











//p19
/*
#include<stdio.h>

int main(void) {
	int c;
	FILE * fp, *ft;
	char * name = "My name is Jae Hyeon Yoo";
	char * company = "DanKook University";
	fp = fopen("name.txt", "w");

	if (fp) {
		fputs(name, fp);
		fputs(company, fp);
		fclose(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/






//p20
/*
#include<stdio.h>

int main(void) {
	int c;
	FILE * fp, *ft;
	char * name = "My name is Jae Hyeon Yoo";
	char * company = "DanKook University";
	fp = fopen("name.txt", "w");

	if (fp) {
		fputs(name, fp);
		fputc('\n', fp);
		fputs(company, fp);
		fclose(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/






//p21
/*
#include<stdio.h>

int main(void) {
	FILE * fp, *ft;
	char buff[100];
	
	fp = fopen("name.txt", "r");
	if (fp) {
		while (fgets(buff, 100, fp) != NULL) {
			printf("%s", buff);
		}
		fclose(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}
*/







//p25
/*
#include<stdio.h>
void do_save_exam_result(FILE * fp);
int main(void) {
	FILE * fp;
	char fname[100];

	printf("Input file name to save: ");
	scanf("%s", fname);

	fp = fopen(fname, "w");
	if (fp) {
		do_save_exam_result(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	fclose(fp);
	return 0;
}

void do_save_exam_result(FILE * fp) {
	char name[20];
	int id;
	double result;

	while (1) {
		printf("Input exam result: ");
		scanf("%d", &id);
		if (id < 0) break;
		scanf("%s %lf", name, &result);

		fprintf(fp, "%d %s %lf", id, name, result);
	}
	return;
}
*/





//p28
/*
#include<stdio.h>
void do_save_exam_result(FILE * fp);
int main(void) {
	FILE * fp;
	char fname[100];

	printf("Input file name to save: ");
	scanf("%s", fname);

	fp = fopen(fname, "w");
	if (fp) {
		do_save_exam_result(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	fclose(fp);
	return 0;
}

void do_save_exam_result(FILE * fp) {
	char name[20];
	int id;
	double result;

	while (1) {
		printf("Input exam result: ");
		scanf("%d", &id);
		if (id < 0) break;
		scanf("%s %lf", name, &result);

		fprintf(fp, "%d %s %lf", id, name, result);
	}
	return;
}
*/





//p28 read부분
/*
#include <stdio.h>

void do_avg_exam_result(FILE *fp);
int main(void) {
	FILE *fp;
	char fname[100];
	printf("Input file name to read: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp) {
		do_avg_exam_result(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}


void do_avg_exam_result(FILE *fp) {
	char name[20];
	int id, num = 0;
	double result;
	double total = 0.0;
	while (!feof(fp)) {
		fscanf(fp, "%d %s %lf", &id, name, &result);
		num++;
		total += result;
		printf("%d %s %lf\n", id, name, result);
	}
	printf("Average of exam is %lf", (total / num));
	return;
}
*/





//p34
/*
#include <stdio.h>
void do_save_exam_result(FILE *fp);
int main(void) {
	FILE *fp;
	char fname[100];
	printf("Input file name to save: ");
	scanf("%s", fname); fp = fopen(fname, "wb");
	if (fp) {
		do_save_exam_result(fp);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}

void do_save_exam_result(FILE *fp) {
	struct {
		int id;
		char name[20];
		double result;
	} info;
	while (1) {
		printf("Input exam result: ");
		scanf("%d", &info.id);
		if (info.id < 0) break;
		scanf("%s %lf", info.name, &info.result);
		fwrite(&info, sizeof(info), 1, fp);
	}
	return;
}

*/

/*

//48p
#include <stdio.h>
#include <stdlib.h>
void clone_lenna(FILE *fp, FILE *ft);

int main(void) {
	FILE *fp, *ft;
	fp = fopen("lenna.png", "rb");
	ft = fopen("lenna_copy.png", "wb");
	if (fp && ft) {
		clone_lenna(fp, ft);
		fclose(fp);
		fclose(ft);
	}
	else {
		printf("Fail to open file\n");
	}
	return 0;
}

void clone_lenna(FILE *fp, FILE *ft) {
	unsigned char buff[100];
	size_t readb, writeb;
	while ((readb = fread(buff, sizeof(unsigned char), 100, fp)) > 0) {
		writeb = fwrite(buff, sizeof(unsigned char), readb, ft);
		if (writeb < 0) {
			printf("Error %d\n", writeb);
				exit(0);
		}
		if (writeb != readb) {
			printf("Error %d\n", writeb);
			exit(0);
		}
	}
}
*/
/*
#include<stdio.h>

int main(void) {
	int c;
	while (1) {
		fscanf(stdin, "%d", &c);
		if (c == -1) break;
		fprintf(stdout, "input is %d\n", c);
	}
	return 0;
}
*/




//컴파일러까지 가지 않으므로,, 2+3을 string으로 인식..  2+3*2+3 으로 인식하여 11로 출력
// "square.h" ""표시는 현재 같은 디렉토리에서 가져와라 <>표시는 윈도우 디렉토리에서 가져와라!
/*#include<stdio.h>
#define SQUARE(x) (x*x)

int main(void) {
	int a;
	a = SQUARE(2 + 3);
	printf("%d", a);

	return 0;
}
*/

#include<stdio.h>

int main(void) {
	printf("asd");
}