//interger to string
/*
* Update histroy: fix bug of display -2^(31)=-2147483648;
* line 35 and 37
*
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void itoa(int number);
void reverse(char s[]);

int main()
{
	int number =INT_MIN;
	itoa(number);
	return 1;
}

/*
* itoa: integer-tranfer-to-alphabeta
* Note that, sign symbol
*/
void itoa(int number)
{
	char s[20] = { 0 };
	int i = 0;
	int sign = 0;
	if (number < 0){
		sign = -1;
		number *= -1;
	}
	do	{
		s[i++] = abs(number % 10) + '0';
		number /= 10;
	} while (number);
	s[i++] = (sign == -1) ? '-' : '\0';
	s[i] = '\0';
	reverse(s);
	printf("%s\n", s);
}
/*
* reverse a string
*/
void reverse(char s[])
{
	int i, j,c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i], s[i] = s[j], 	s[j] = c;
	}
}