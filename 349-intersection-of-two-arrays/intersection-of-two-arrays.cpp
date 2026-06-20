class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> mp(nums1.begin(), nums1.end());
        
        vector<int> res;
        for(int num:nums2){
            if(mp.count(num))
            res.push_back(num);
            mp.erase(num);
        }
        return res;
    }
};