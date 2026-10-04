class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp1;
        for(char c:s){
            mp1[c]++;
        }
        unordered_map<char, int> mp2;
        for(char c:t){
            mp2[c]++;
        }
        for(auto &p : mp1){
            if(p.second != mp2[p.first])
                return false;
        }
        return true;        
    }
};