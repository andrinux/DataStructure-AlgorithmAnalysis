/*Transfer a base-10 number to a base b number, 
*in a format of string
*b can be any number 2-36
*/

#include <stdio.h>
#include <string.h>

void itob(int number, char res[], int b);
void reverse(char s[]);

int main()
{
	int number = 123456;
	char res[50];
	int b=36;
	itob(number, res, b);
	printf("%s\n", res);
	return 1;
}

void itob(int number, char res[], int b)
{
	int sign,i;
	char sym[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	i = 0;
	sign = (number < 0) ? -1 : 1;
	if (sign == -1)
		number = number*-1;
	do{
		res[i++] = sym[number%b];
		number = number / b;
	} while (number);
	if (sign == -1)
		res[i++] = '-';
	res[i] = '\0';
	reverse(res);
}


/*
* reverse a string
*/
void reverse(char s[])
{
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i], s[i] = s[j], s[j] = c;
	}
}
