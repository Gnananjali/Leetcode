class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.size() != t.size()) return false;
        for(char ch: s){
            mp[ch]++;
        }
        for(char ch: t){
            mp[ch]--;
        }
        for(auto& it:mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};