class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char c:s){
            mp[c]++;
        }
        unordered_set<int> mp1;
        int count=0;
        for(auto &it:mp){
            int freq = it.second;

            while(mp1.count(freq) && freq >0){
                freq--;
                count++;
            }
            mp1.insert(freq);
        }
        return count;
    }
};