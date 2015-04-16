//Shell Sorting
#include <stdio.h>

void shellSort(int v[], int len);

int main()
{
	int v[16] = { 13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
	int N = 16;
	for (int i = 0; i < N; i++)
		printf("%d, ", v[i]);
	printf("\n");
	shellSort(v, N);
	return 1;
}


void shellSort(int a[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2) /
	for (i = 0; i < gap; i++)        
	{
		for (j = i + gap; j < n; j += gap)
			if (a[j] < a[j - gap])
			{
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
	}
	for (int i = 0; i < n; i++)
		printf("%d, ", a[i]);
}
