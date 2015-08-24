#include <iostream>
#include <vector>
#include <unordered_map>

//Res is 16ms. Top 50%.
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> res;
       unordered_map<int, int> maps;
       unordered_map<int, int>::iterator itr;
       unsigned int i=0;
       for(i = 0; i != nums.size(); i++){
           itr = maps.find(target - nums[i]);
           if(itr == maps.end())
               maps.insert(pair<int,int>(nums[i], i));
           else{
               cout<<"index1="<< 1+itr->second <<", index2="<< 1+i <<endl;
               res.push_back(1+itr->second);
               res.push_back(1+i);
               return res;
           }
       }
       return res;
    }
};

int main()
{
    int data[] = {2, 7, 11, 15, 20, 100};
    vector<int> nums;
    for(unsigned i=0; i!= 6; i++)
        nums.push_back(data[i]);

    Solution so;
    so.twoSum(nums, 9);
    return 1;
}
