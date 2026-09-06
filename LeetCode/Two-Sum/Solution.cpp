1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        
5        for (int i = 0; i < nums.size(); i++) {
6            for (int j = i + 1; j < nums.size(); j++) {
7                
8                if (nums[i] + nums[j] == target) {
9                    return {i, j};
10                }
11            }
12        }
13        
14        return {};
15    }
16};