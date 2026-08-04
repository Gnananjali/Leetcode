class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> mp;
        
        int largest = nums[n-1];
        int smallest = nums[0];
        vector<int> ans;
        for(int num:nums) mp.insert(num);
        for(int x=smallest;x<=largest;x++){
            
            if(!mp.count(x)){
                ans.push_back(x);
            }
            continue;
        }
        return ans;
    }
};