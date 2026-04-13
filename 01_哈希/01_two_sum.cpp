#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> seen; // valur-> index
        for (int i=0; i < (int)nums.size() - 1; i++ ){
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()){
                return {it->second, i};
            }

        }



    }



}
