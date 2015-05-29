/*
* Write code to reverse a C - Style String. (C - String means that ¡°abcd¡± is represented 
* as five characters, including the null character.)
*/
#include <iostream>
#include <string>
#include <cstring>

//input is a C style string
char *reverse(char str[]){
	char *i = str;
	char *j = str;
	char tmp;
	while ((*j) != NULL)
		j++;
	j--;
	while (i < j){
		tmp = *i;
		*i = *j;
		*j = tmp;
		i++; j--;
	}
	return str;
}

int main()
{
	char str1[] = "Happy Day";
	char str2[] = "ABCDEFGHIGJK";
	puts(str1); puts(reverse(str1));
	puts(str2); puts(reverse(str2));
	return 1;
}