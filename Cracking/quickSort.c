#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXLENGTH 200


int readLines(FILE *in, char *lineptr[]);
int getLine(FILE *in, char *strline);

void quicksort(char *v[], int left, int right);

int main()
{
	FILE *in;
	
	char *lineptr[MAXLINE];
	int nline = 0;
	in = fopen("test.txt", "r");
	nline = readLines(in, lineptr);
	for (int i = 0; i < nline; i++){
		printf("%s\n", lineptr[i]);
	}
	
	printf("==================\n");

	quicksort(lineptr, 0, nline - 1);
	for (int i = 0; i < nline; i++){
		printf("%s\n", lineptr[i]);
	}
	
	fclose(in);
	return 1;
}

int readLines(FILE *in, char *lineptr[])
{
	int nline = 0;
	int len;
	char line[MAXLENGTH];
	while ((len = getLine(in, line)) > 0){
		lineptr[nline] = (char*)malloc(sizeof(char)*MAXLENGTH);
		strcpy(lineptr[nline], line);
		nline++;
	}
	return nline;
}

int getLine(FILE *in, char *strline)
{
	char c;
	int len=0;
	while ((c = fgetc(in)) != '\n' && c != EOF){
		*(strline + len) = c;
		len++;
	}
	strline[len] = '\0';

	return len;
}

void quicksort(char *v[], int left, int right)
{
	char *mid=v[left];
	int i=left, j=right;

	if(left < right){
		while (i < j){
			while (i < j && (strcmp(mid, v[j]) < 0))
				j--;
			if (i < j){
				v[i++] = v[j];
			}
			while (i<j && (strcmp(mid, v[i])>0))
				i++;
			if (i < j){
				v[j--] = v[i];
			}

			v[i] = mid;
		}
		quicksort(v, left, i - 1);
		quicksort(v, i + 1, right);
	}
}