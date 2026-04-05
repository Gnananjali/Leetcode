class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> st;

        for(char string:s){
            st[string]++;
        }
        for(char string:t){
            st[string]--;
            if(st[string] < 0) return false;
        }
        return true;
    }
};