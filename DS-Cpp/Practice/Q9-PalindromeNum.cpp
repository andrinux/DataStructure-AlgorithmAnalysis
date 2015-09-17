#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//Check Plaindrome without extra space.

class Solution {
public:
	//the Nth from right, 3->2->1->0
	int getNth(int x, int N){
		int div = (int) pow(10, N);
		int res = x / div;
		return res % 10;
	}

	bool isPalindrome_Slow(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		//Get length
		int len = 0;
		int tmp = x;
		while (tmp){
			len++;
			tmp /= 10;
		}
		//Get Search start point.
		int low = 0;
		int up = 0;
		if (len % 2 == 1){
			low = len / 2; //start from the same point.
			up = len / 2;
		}
		else{
			low = len / 2 - 1;
			up = len / 2;
		}
		//Check Palindrome.
		while (low >= 0 && up <= len - 1 && getNth(x, low) == getNth(x, up)){
				low--;
				up++;
		}
		if (low == -1 && up == len)
			return true;
		else
			return false;
	}

	/*
	* Fast Version, Avoid Function calling and repeated dividing.
	* Use a Stack to contain the numbers, 
	* the first half, push back and the second half pop out.
	*/
	bool isPalindrome_V2(int x) {
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		//Get length
		int len = 0;
		int tmp = x;
		while (tmp){
			len++;
			tmp /= 10;
		}
		stack<int> numbers;
		//Push
		int i = 0;
		for (i = 0; i < len / 2; i++){
			numbers.push(x % 10);
			x /= 10;
		}
		//Skip
		if (len % 2 == 1)
			x /= 10;
		//Pop.
		while (x){
			if (x % 10 == numbers.top()){
				x /= 10;
				numbers.pop();
			}
			else
				return false;
		}
		if (x == 0)
			return true;
		else
			return false;
	}


	bool isPalindrome(int x) {
		int ori = x;
		if (x < 0)
			return false;
		if (x < 10)
			return true;
		int sum = 0;
		while (x){
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		return ori == sum;
	}
};

