#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ARR_SIZE 100000

// Complete selection_sort function to perform selection sorting
// ***** Complete ****** 
// * DON'T USE ARRAY INDEX
// ** USE ONLY POINTER ARITHMATIC 
void selection_sort(int *arr, int size)
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		int jMin = i;  
		for (j = i + 1; j < size; j++) {
			if (*(arr+j) < *(arr+jMin)) { 
				jMin = j;
			} 
		} 
		if (jMin != i) {
			temp = *(arr+i);  
			*(arr+i) = *(arr+jMin);    
			*(arr + jMin) = temp;
		} 
	}

	// ##### YOUR CODE HERE!!

	return;
}

// Complete insertion_sort function to perform insertion sorting
// ***** Complete ****** 
// * DON'T USE ARRAY INDEX
// ** USE ONLY POINTER ARITHMATIC 
void insertion_sort(int *arr, int size)
{
	int i, j, min; 
	for (i = 1; i < size; i++) {
		min = *(arr+i);
		j = i - 1;  
		while (j >= 0 && min < *(arr+j)) {
			*(arr+j+1) = *(arr+j);    
			j--; 
		} 
		*(arr+j+1) = min;
	}

	// ##### YOUR CODE HERE!!

	return;
}


// DON'T MODIFY check_result FUNCTION
void check_result(int *arr, clock_t start_t, clock_t end_t)
{
	bool sorted = true;
	for (int i = 1; i < ARR_SIZE; i++) {
		if (*(arr + i) < *(arr + i - 1)) {
			sorted = false;
			break;
		}
	}
	if (sorted) {
		printf("Success to sort numbers.\n");
	}
	else {
		printf("Fail to sort numbers.\n");
	}
	printf("It took %lf seconds.\n", (double)(end_t - start_t) / (double)(CLOCKS_PER_SEC));
	return;
}


int main(void)
{
	FILE *fp;
	int *arr_sel, *arr_ins, idx = 0, rand_val;
	clock_t start_t, end_t;
	fp = fopen("numbers.txt", "r");
	// Allocate memory for arr_sel & arr_ins
	// arr_sel will be used for selection sorting.
	// arr_ins will be used for insertion sorting.
	// ***** Complete ****** 
	arr_sel = malloc(sizeof(int)*ARR_SIZE);
	arr_ins = malloc(sizeof(int)*ARR_SIZE);

	// Check whether the memory allocation is success or not.
	// ***** Complete ****** 
	if (arr_sel && arr_ins) {
		// If arr_set and arr_ins is successfully allocated.

		// Open file numbers.txt as read mode & save file pointer to fp.
		if (fp) {
			printf("---1. Read from data file!! \n");
			for(int ne = 0; ne < ARR_SIZE; ne++){
				fscanf(fp, "%d", arr_sel+ne);
			}
			// Read all numbers from file to arr_sel.
			// Use for, while, do-while statement
			// Use fscanf, fgets to read a line from file.
			// ***** Complete ****** 
			
			fclose(fp);

// Close fp 
// ***** Complete ****** 


// Copy arr_sel to arr_ins 
// ***** Complete ****** 
			memcpy(arr_ins, arr_sel, ARR_SIZE);

			printf("\n---2. Selection Sorting \n");
			start_t = clock();
			selection_sort(arr_sel, ARR_SIZE);
			end_t = clock();
			check_result(arr_sel, start_t, end_t);

			printf("\n---3. Insertion Sorting \n");
			start_t = clock();
			insertion_sort(arr_ins, ARR_SIZE);
			end_t = clock();
			check_result(arr_ins, start_t, end_t);

		}
		else {
			printf("Error to open file numbers.txt\n");
		}
	}
	else {
		printf("memory allocation error\n");
	}

	// Free arr_sel if that was successfully allocated
	// ***** Complete ****** 
	if (arr_sel) { free(arr_sel); }

	// Free arr_ins if that was successfully allocated
	// ***** Complete ****** 
	if (arr_ins) { free(arr_ins); }

	return 0;
}


