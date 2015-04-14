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

/*
void shellSort(int v[], int len)
{
	int step;
	int col, row, i, j;
	int tmp;
	for (step = len / 2; step > 0; step /= 2){
		//For each column, do an insertion sorting
		for (col = 0; col < step; col++){
			//Begin insert sort, the data to be sorted is:
			//col+step*1, col+step*2, col+step*3...
			for (row = 1; row <= (len -1 - col) / step; row++){
				tmp = v[col + row*step]; //Value to be placed
				for (i = 0; i < row; i++){//Search row 0 to cur row
					if (v[col + i*step] > tmp){//If some row bigger than cur, shift down one by one
						for (j = row - 1; j >=i; j--){
							v[(j+1)*step+col] = v[j*step+col];
						}
						v[col+step*i] = tmp;
					}
				}
			}
		}
	}

	for (int i = 0; i < len; i++)
		printf("%d, ",v[i]);
}
*/
void shellSort(int a[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2) //步长  
	for (i = 0; i < gap; i++)        //直接插入排序  
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