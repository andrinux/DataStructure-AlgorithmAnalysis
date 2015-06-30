/*
* This is an implementation of Recursion version of Merge sort.
* Iterative Version as well.
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <iomanip>

#define M 100
using namespace std;


//In-place merge.
void do_merge(vector<int> &data, int s, int e)
{
	vector<int> sorted;
	int i = s;
	int j = (s+e)/2 + 1;
	while (sorted.size() < (e - s + 1)){
		if (data[i] < data[j]){
			sorted.push_back(data[i]);
			i++;
			if (i > (e + s) / 2){
				for (; j <= e; j++)
					sorted.push_back(data[j]);
			}
		}
		else{
			//data[i] <= data[j]
			sorted.push_back(data[j]);
			j++;
			if (j > e){
				for (; i <=  (e + s) / 2; i++)
					sorted.push_back(data[i]);
			}
		}
	}
	for (i = s; i <= e; i++)
		data[i] = sorted[i - s];

}

void mergeSortR(vector<int>& data, int s, int e){
	if (s == e)
		return;
	int m = (s + e) / 2;
	mergeSortR(data, s, m);
	mergeSortR(data, m + 1, e);
	do_merge(data, s, e);
}

void mergeSort(vector<int>& data){

}

int main()
{
	srand((unsigned) time(NULL));
	vector<int> data;
	for (int i = 0; i != M; i++)
		data.push_back(rand() % 1000);
	//for (int i = 0; i != M; i++){
	//	cout << setw(3) << data[i] << " -> ";
	//	if ((i + 1) % 10 == 0)
	//		std::cout << std::endl;
	//}
	//std::cout << "\n--------------------\n";

	mergeSortR(data, 0, data.size()-1);
	
	//for (int i = 0; i != M; i++){
	//	cout << setw(3) << data[i] << " -> ";
	//	if ((i + 1) % 10 == 0)
	//		std::cout << std::endl;
	//}
	return 0;
}