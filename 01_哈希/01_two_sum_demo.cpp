#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 题号：1. 两数之和（Two Sum）
 * 难度：简单
 * 链接：https://leetcode.cn/problems/two-sum/
 *
 * 题意：
 *   给定整数数组 nums 和目标值 target，
 *   返回两个数之和等于 target 的下标（每种输入只有一个答案，不重复使用同一元素）。
 *
 * 思路（哈希表，O(n)）：
 *   遍历数组，对每个 nums[i]，先查哈希表中是否存在 target - nums[i]，
 *   存在则直接返回两个下标；否则将 nums[i] 及其下标存入哈希表。
 *
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {}; // 题目保证有解，不会到达此处
    }
};

// ===== 测试 =====
int main() {
    Solution sol;

    auto print = [](const vector<int>& v) {
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;
    };

    // case 1: [2,7,11,15], target=9  => [0,1]
    vector<int> nums1 = {2, 7, 11, 15};
    print(sol.twoSum(nums1, 9));

    // case 2: [3,2,4], target=6  => [1,2]
    vector<int> nums2 = {3, 2, 4};
    print(sol.twoSum(nums2, 6));

    // case 3: [3,3], target=6  => [0,1]
    vector<int> nums3 = {3, 3};
    print(sol.twoSum(nums3, 6));

    return 0;
}
