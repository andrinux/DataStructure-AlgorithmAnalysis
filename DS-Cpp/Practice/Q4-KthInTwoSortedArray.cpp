#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//Function to find the Kth Smallest Element in two sorted array.
	int findKthTwoSortedArray(unsigned int k, vector<int> NumA, unsigned int Astart, vector<int> NumB, unsigned int Bstart){
		//Basic case and corner case
		if (NumA.size() == 0 && NumB.size() == 0)
			return 0;

		if (Astart >= NumA.size() && Bstart >= NumB.size())
			return min(NumA[Astart - 1], NumB[Bstart - 1]);//All Empty
		if (Astart >= NumA.size() && Bstart < NumB.size())
			return NumB[Bstart + k - 1];
		if (Astart < NumA.size() && Bstart >= NumB.size())
			return NumA[Astart + k - 1];

		//No EMpty
		if (k == 1)
			return min(NumA[Astart], NumB[Bstart]);
		if (k == 0)
			return min(NumA[Astart - 1], NumB[Bstart - 1]);

		//General Case
		unsigned int offset = min( (unsigned int )min(NumA.size(), NumB.size()), k/2 );
		if (NumA[Astart + offset - 1] < NumB[Bstart + offset - 1])
			return findKthTwoSortedArray(k - offset, NumA, Astart + offset, NumB, Bstart);
		else if (NumA[Astart + offset - 1] > NumB[Bstart + offset - 1])
			return findKthTwoSortedArray(k - offset, NumA, Astart, NumB, Bstart + offset);
		else
			return findKthTwoSortedArray(k - offset - offset, NumA, Astart + offset, NumB, Bstart + offset);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() == 0 && nums2.size() == 0)
			return 0;

		unsigned int N = nums1.size() + nums2.size();
		if (N % 2 == 1)
			return 1.0 * findKthTwoSortedArray(N / 2 + 1, nums1, 0, nums2, 0);
		else
			return (findKthTwoSortedArray(N/2, nums1, 0, nums2, 0) + 
					findKthTwoSortedArray(N/2+1, nums1, 0, nums2, 0)) / 2.0;
	}

	double findMedianSortedArrays_On(vector<int>& nums1, vector<int>& nums2){
		unsigned int m = nums1.size();
		unsigned int n = nums2.size();
		unsigned int target = (m + n) / 2 - 1;
		unsigned int i = 0, j = 0;
		int ret1 = 0, ret2 = 0;
		//Skip the first target-1 numbers
		while ((i + j) <= target + 1){
			int n1 = INT_MAX, n2 = INT_MAX;

			if (i < nums1.size())
				n1 = nums1[i];
			else
				n1 = INT_MAX;
			if (j < nums2.size())
				n2 = nums2[j];
			else
				n2 = INT_MAX;
			if ((i + j) == target)		ret1 = min(n1, n2);
			if ((i + j) == target + 1)	ret2 = min(n1, n2);

			if (n1 <= n2)
				i++;
			else
				j++;

		}
		//cout << ret1 << ", " << ret2 << endl;
		if ((m + n) % 2 == 1)
			return ret2*1.0;
		else
			return (ret2 + ret1) / 2.0;
	}

};

int main()
{
	Solution so;

	vector<int> num1 = {1};
	vector<int> num2 = {1};
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1,3,5,6,7 };
	num2 = { 2};
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1, 3, 5, 6, 7 };
	num2 = { 2, 10 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;


	num1 = { 1 };
	num2 = { 2, 3, 4, 5, 6 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;
	
	num1 = { 1, 2};
	num2 = { 1, 2 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1, 2, 6};
	num2 = { 3, 4, 5 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	vector<int> r1 = { };
	vector<int> r2 = {  };
	cout << so.findMedianSortedArrays_On(r1, r2);
	cout << "----";
	cout << so.findMedianSortedArrays(r1, r2);
	cout << endl;

	vector<int> num3 = { 1, 12, 15, 26, 38 }; 
	vector<int> num4 = { 2, 13, 17, 30, 45, 50 };
	cout << so.findMedianSortedArrays_On(num3, num4);
	cout << " ==> ";
	cout << so.findMedianSortedArrays(num3, num4);
	cout << endl;

	num1 = { 1, 12, 15, 26, 38 };
	num2 = { 2, 13, 17, 30, 45 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1, 2, 5, 6, 8 };
	num2 = { 13, 17, 30, 45, 50 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1, 2, 5, 6, 8, 9, 10 };
	num2 = { 13, 17, 30, 45, 50 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	num1 = { 1, 2, 5, 6, 8, 9 };
	num2 = { 13, 17, 30, 45, 50 };
	cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	return 1;
}

