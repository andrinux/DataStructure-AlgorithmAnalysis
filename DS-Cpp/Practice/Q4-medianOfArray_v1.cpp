#include <iostream>
#include <vector>
#include <algorithm>

/*
* This version of answer is too complicated.
* Ref: http://www.cnblogs.com/tenosdoit/p/3554479.html
* The ref is for an older problem: upper median.
* Not correct for A: [2,6], B [3,4]
*/
using namespace std;

#define MAX INT_MAX

class Solution {
public:
	double getMedian(vector<int>& nums, unsigned int start, unsigned int end){
		unsigned int len = end - start + 1;
		unsigned int loc1 = (start + end) / 2;
		unsigned int loc2 = (start + end) / 2 + 1;
		if (len % 2 == 1)
			return nums[loc1] * 1.0;
		else
			return(nums[loc1] + nums[loc2]) / 2.0;
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//current size of two vectors
		if (nums1.size() < nums2.size())
			nums1.swap(nums2);
		unsigned int m = nums1.size(), n = nums2.size();
		if (m == 0 && n == 0)
			return 0;
			
		//nums1 is always the longer one. m is larger
		unsigned int mstart = 0, mend = max(m - 1, unsigned(0));
		unsigned int nstart = 0, nend = max(n - 1, unsigned(0));//0 default is signed...
		double m_median = 0, n_median = 0;
		while (m > 1 && n > 1 ){
			m_median = getMedian(nums1, mstart, mend);
			n_median = getMedian(nums2, nstart, nend);
			unsigned int len = min(m, n) / 2;
			
			if (m_median < n_median){
				mstart = mstart + len;
				nend = nend - len;
				m -= len; n -= len;
			}
			else if (m_median > n_median){
				nstart = nstart + len;
				mend = mend - len;
				m -= len; n -= len;
			}
			else{
				return m_median*1.0;
			}
		}
		if (m == 0)
			return getMedian(nums2, nstart, nend);
		if (n == 0)
			return getMedian(nums1, mstart, mend);
		//Basic case is that one vector's length becomes 1 or shorter
		if (m == 1 && n == 1)
			return (nums1[mstart] + nums2[nstart]) / 2.0;
		//A long vector with a short one.
		if (n == 1 && m > 1){
			m_median = getMedian(nums1, mstart, mend);
			n_median = getMedian(nums2, nstart, nend);
			if (m % 2 == 1){
				//odd. at least three.
				int N1 = nums1[(mstart + mend) / 2 - 1];
				int N2 = nums1[(mstart + mend) / 2];
				int N3 = nums1[(mstart + mend) / 2 + 1];
				if (n_median <= N1)
					return (N1 + N2) / 2.0;
				else if (n_median > N1 && n_median <= N2)
					return (N2 + n_median) / 2.0;
				else if (n_median > N2 && n_median <= N3)
					return (N2 + n_median) / 2.0;
				else
					return (N2 + N3) / 2.0;
			}
			else{
				//eve, at least two
				int N2 = nums1[(mstart + mend) / 2 ];
				int N3 = nums1[(mstart + mend) / 2 + 1];
				if (n_median <= N2)
					return N2;
				else if (n_median > N2 && n_median <= N3)
					return n_median;
				else
					return N3;
			}
		}

    }

	double findMedianSortedArrays_On(vector<int>& nums1, vector<int>& nums2){
		unsigned int m = nums1.size();
		unsigned int n = nums2.size();
		unsigned int target = (m + n) / 2 - 1;
		unsigned int i = 0, j = 0;
		int ret1 = 0, ret2 = 0;
		//Skip the first target-1 numbers
		while((i+j) <= target+1){
			int n1=INT_MAX, n2=INT_MAX;
			
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

    vector<int> num1 = {1,2,6};
    vector<int> num2 = {3,4,5}; 
    cout << so.findMedianSortedArrays_On(num1, num2);
	cout << "----";
	cout << so.findMedianSortedArrays(num1, num2);
	cout << endl;

	//vector<int> r1 = { 1 };
	//vector<int> r2 = { 2 };
	//cout << so.findMedianSortedArrays_On(r1, r2);
	//cout << "----";
	//cout << so.findMedianSortedArrays(r1, r2);
	//cout << endl;

	//vector<int> num3 = { 1, 12, 15, 26, 38 }; 
	//vector<int> num4 = { 2, 13, 17, 30, 45, 50 };
	//cout << so.findMedianSortedArrays_On(num3, num4);
	//cout << " ==> ";
	//cout << so.findMedianSortedArrays(num3, num4);
	//cout << endl;

	//num1 = { 1, 12, 15, 26, 38 };
	//num2 = { 2, 13, 17, 30, 45 };
	//cout << so.findMedianSortedArrays_On(num1, num2);
	//cout << "----";
	//cout << so.findMedianSortedArrays(num1, num2);
	//cout << endl;

	//num1 = { 1, 2, 5, 6, 8 };
	//num2 = { 13, 17, 30, 45, 50 };
	//cout << so.findMedianSortedArrays_On(num1, num2);
	//cout << "----";
	//cout << so.findMedianSortedArrays(num1, num2);
	//cout << endl;

	//num1 = { 1, 2, 5, 6, 8, 9, 10 };
	//num2 = { 13, 17, 30, 45, 50 };
	//cout << so.findMedianSortedArrays_On(num1, num2);
	//cout << "----";
	//cout << so.findMedianSortedArrays(num1, num2);
	//cout << endl;

	//num1 = { 1, 2, 5, 6, 8, 9 };
	//num2 = { 13, 17, 30, 45, 50 };
	//cout << so.findMedianSortedArrays_On(num1, num2);
	//cout << "----";
	//cout << so.findMedianSortedArrays(num1, num2);
	//cout << endl;

	return 1;
}
