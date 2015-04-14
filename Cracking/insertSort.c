//Insertion Sorting
#include <stdio.h>

void insertSort(int v[], int len);

int main()
{
	int v[16] = { 13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
	int N = 16;
	for (int i = 0; i < N; i++)
		printf("%d, ", v[i]);
	printf("\n");
	insertSort(v, N);
	return 1;
}


void insertSort(int v[], int len)
{
	int i; //i is the index of original array
	int j; //j is the index of current array
	int tmp;

	for (i = 1; i < len; i++){
		tmp = v[i];
		for (j = 0; j < i; j++){
			if (v[i] < v[j]){
				for (int k = i; k > j; k--)
					v[k] = v[k - 1];
				v[j] = tmp;
			}
		}
	}
	for (i = 0; i < len; i++)
		printf("%d, ",v[i]);
}