#include <map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_map<int, int> vdata;
        for(int i = 0; i != nums.size(); i++){
            if(vdata[nums[i]] == 0)
                vdata[nums[i]] = 1;
            else
                vdata[nums[i]] = 0;
        }
        unordered_map<int, int>::const_iterator itr=vdata.begin();
        for(; itr != vdata.end(); itr++)
            if(itr->second == 1)
                return itr->first;
    }
};
