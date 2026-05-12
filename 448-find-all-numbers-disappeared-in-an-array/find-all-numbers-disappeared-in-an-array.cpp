class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> map(nums.begin(), nums.end());
        vector<int> result;

        for(int i=1;i<=nums.size();i++){
            if(!map.count(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};