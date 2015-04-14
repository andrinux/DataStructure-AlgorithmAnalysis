#include <stdio.h>
#include <string.h>

int findStr(char str[], char substr[]);

int main()
{
	char str[100] = "sGoodDayGoodHelloBaby";
	char substr[10] = "Good";
	int pos = 0;
	printf("%d", findStr(str, substr));
	return 1;
}

int findStr(char str[], char substr[])
{
	unsigned int i=0, j=0, k=0;
	int pos=-1;
	for (i = 0; i<strlen(str)-strlen(substr)-1; i++){  //Here can be much simpler
		for (j = i, k = 0; str[j] == substr[k]; j++, k++)
			;
		if (substr[k] == '\0'){
			pos = i;
			break;
		}
	}
	return pos;
}

