class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>> vect;
        vector<int> ans;
        for(auto& it:mp){
            vect.push_back({it.second, it.first});
        }
        sort(vect.rbegin(), vect.rend());
        for(int i=0;i<k;i++){
            ans.push_back(vect[i].second);
        }
        return ans;
    }
};