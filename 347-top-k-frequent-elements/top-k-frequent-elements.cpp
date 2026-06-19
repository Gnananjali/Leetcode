class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vect;
        for(auto& it:mp){
        vect.push_back({it.second, it.first});
        }
        sort(vect.rbegin(), vect.rend());
        vector<int> res;
        
            for(int i=0;i<k;i++){
                res.push_back(vect[i].second);
            
        }
        return res;
    }
};