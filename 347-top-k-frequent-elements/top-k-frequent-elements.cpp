class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>> box;
        for(auto& it : mp){
            box.push_back({it.second, it.first});
        }
        sort(box.rbegin(), box.rend());
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(box[i].second);
        }
        return res;
    }
};