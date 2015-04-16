//This is a simple method to count different words in a txt file.
//Use a Binary Search Tree

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define MAXWORD 20

struct tnode{
	char word[MAXWORD];
	int count;
	struct tnode *left;
	struct tnode *right;
};

int getword(FILE *in, char *word);
struct tnode *addtree(struct tnode *root, char word[]);
void dispTree(struct tnode *root);

int main()
{
	struct tnode *root=NULL;
	FILE *in;
	in = fopen("test1.txt", "r");
	char word[20];
	while (getword(in, word) > 0){
		root=addtree(root, word);
	}
	dispTree(root);
	return 1;
}

int getword(FILE *in, char *word)
{
	int status=OUT;
	int len=0;
	int c;
	while ((c = fgetc(in)) != EOF && !isalpha(c))
		;
	if (isalpha(c)){
		word[len++] = c;
	}
	while ((c = fgetc(in)) != EOF && isalpha(c)){
		word[len++] = c;
	}
	word[len] = '\0';
	return len;
}
//Add a new Node
struct tnode *addtree(struct tnode *p, char word[])
{
	int cond;
	if (p == NULL){
		p = (struct tnode *) malloc(1* sizeof(struct tnode));
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
		strcpy(p->word, word);
	}
	else{
		cond = strcmp(p->word, word);
		if (cond == 0)
			p->count++;
		else if (cond < 0){
			p->left=addtree(p->left, word);
		}
		else{
			p->right=addtree(p->right, word);
		}
	}
	return p;
}

void dispTree(struct tnode *p)
{
	if (p != NULL){
		dispTree(p->left);
		printf("%d, %s\n", p->count, p->word);
		dispTree(p->right);
	}
}