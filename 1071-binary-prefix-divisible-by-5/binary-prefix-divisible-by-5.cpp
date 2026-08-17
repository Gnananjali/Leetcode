class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int rem=0;
        vector<bool> ans;

        for(int num:nums){
            rem = (rem * 2 + num)%5;
            ans.push_back(rem==0);
        }
        return ans;
    }
};