//K&R-Problem 4.1
//Get the most right side position of a sub string

#include <stdio.h>
int strIndex(char s[], char t[]);
void strIndex_All(char s[], char t[], int pos[]);

int main()
{
	char s[100] = "GoodhisIsAGoodHappyGoodDayGoodDay";
	char t[10] = "Good";
	int pos[10] ;
	for (int i = 0; i < 10; i++)
		pos[i] = -1;
	//printf("In a line: %d\n", strIndex(s, t));

	strIndex_All(s, t, pos);
	for (int i = 0; pos[i] != -1; i++)
		printf("%d-", pos[i]);
	return 1;
}
//This function return the right side pos of a string
int strIndex(char s[], char t[])
{
	int i, j, k;
	int pos = -1;
	for (i = 0; s[i] != '\0'; i++){
		for (k = i, j = 0; t[j] != '\0' && t[j] == s[k]; j++, k++){
			;
		}
		if (j>0 && t[j] == '\0')
			pos = i;
	}
	return pos;
}

void strIndex_All(char s[], char t[], int *pos)
{
	int i, j, k;
	int cnt = 0;
	for (i = 0; s[i] != '\0'; i++){
		for (k = i, j = 0; t[j] != '\0' && t[j] == s[k]; j++, k++){
			;
		}
		if (t[j] == '\0')
			pos[cnt++] = i;
	}
}
