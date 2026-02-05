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



Algorithm:

• Create an unordered map to store number and its index

• Loop through the array from i = 0 to n-1

  • Calculate the required number
    → need = target - nums[i]

  • If need exists in the map
    → Return the indices {i, map[need]}

  • Else store current number and index in map
    → map[nums[i]] = i

• If no pair is found, return empty vector
