class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> set;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (set.count(need)) {
                return {i, set[need]};
            }
            set[nums[i]] = i;
        }
        return {};
    }
};