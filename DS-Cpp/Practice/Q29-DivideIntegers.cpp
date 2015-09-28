#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//M is large and N is smaller number.
	int divide_1(int M, int N) {
		//Corner cases.
		if (N == 0)
			return INT_MAX;
		if (N == INT_MIN)
			return 0;
		if (M == INT_MIN && N == 1)
			return INT_MIN;
		if (M == INT_MIN && N == -1)
			return INT_MAX;
		//Convert to positive numbers
		int sym1 = M > 0 ? 1 : -1;
		int sym2 = N > 0 ? 1 : -1;
		int newM = M > 0 ? M : -M;
		int newN = N > 0 ? N : -N;
		// do division.
		int result = 0;
		int Rem = newM;
		int curN = newN, factor = 1;
		while (Rem >= curN && curN <= INT_MAX/2){//curN will overflow.
			curN = curN << 1;
			factor = factor << 1;
			if (Rem <= curN){
				result += (factor >> 1);
				Rem = Rem - (curN >> 1);
				curN = newN;
				factor = 1;
			}
		}
		return (int) (sym1*sym2*result);
	}

	//Rewrite.
	int divide(int M, int N) {
		//Corner cases
		if (N == 0)
			return INT_MAX;
		int sym1 = M > 0 ? 1 : -1;
		int sym2 = N > 0 ? 1 : -1;
		//convert to positive.
		long long newM = llabs(M);
		long long newN = llabs(N);

		// do division.
		long long result = 0;
		long long Rem = newM;
		long long curN = newN, factor = 1;
		while (Rem >= curN ){//curN will overflow.
			curN = curN << 1;
			factor = factor << 1;
			if (Rem <= curN){
				result += (factor >> 1);
				Rem = Rem - (curN >> 1);
				curN = newN;
				factor = 1;
			}
		}
		int sym = (sym1 == sym2) ? 1 : -1;
		result = (sym == 1) ? result : (result - result - result);
		if (result<INT_MIN || result>INT_MAX)
			return INT_MAX;
		else
			return (int)(result);
	}
};

int main()
{
	Solution so;
	cout << so.divide(19, -4) << " -> " << (-19/ 4) << endl;
	cout << so.divide(INT_MAX, 1) << " -> " << (INT_MAX/1) << endl;
	cout << so.divide(INT_MIN, -1) << " -> " << (INT_MIN/ -1) << endl;
	cout << so.divide(INT_MIN, -2) << " -> " << (INT_MIN/ -2) << endl;
	cout << so.divide(15, 3) << " -> " << (15/ 3) << endl;
	cout << so.divide(15468, 98) << " -> " << (15468/ 98) << endl;
	cout << so.divide(1234, 2345) << " -> " << (1234/ 2345) << endl;
	cout << so.divide(7654, INT_MAX) << " -> " << (7654/ INT_MAX) << endl;
	cout << so.divide(7654, INT_MAX) << " -> " << (7654/ INT_MAX) << endl;
	cout << so.divide(INT_MAX, INT_MAX) << " -> " << (INT_MAX / INT_MAX) << endl;
	cout << so.divide(INT_MIN, INT_MIN) << " -> " << (INT_MIN / INT_MIN) << endl;
	cout << so.divide(INT_MAX / 2 + 100, INT_MAX / 2 + 1) << " -> " << (INT_MAX / 2 + 100)/ (INT_MAX / 2 + 1) << endl;
	return 1;
}
