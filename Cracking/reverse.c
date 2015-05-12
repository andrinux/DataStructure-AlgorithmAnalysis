//This is used to reverse the input to another order;
//Input is a string

#include<stdio.h>
#include<string.h>


void reverse(char s[]);
int main()
{
	char s[]= "HelloWorld!";
	//char *s = "HelloWorld";
	reverse(s);
	return 1;
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	printf("%s, ", s);
}