#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unsigned int i,sum = 0;
       for(i = 0; i != nums.size(); i++)
           sum ^= nums[i];
       for(i = 0; i!= nums.size()+1; i++)
           sum ^= i;
       return (sum);
    }
};



int main()
{
    int data[]= {0,2,4,3,6,5,9,7,8};
    int i=0;
    std::vector<int> nums;
    for(i=0; i<9; i++)
        nums.push_back(data[i]);
    Solution so;
    cout << so.missingNumber(nums);
    return 1;
}
