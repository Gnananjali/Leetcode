class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int left=0;
        int have=0;
        int start=0;
        int minlen = INT_MAX;
        for(int right=0;right<t.size();right++){
            need[t[right]]++;
        }
        int required = need.size();
        for(int right=0;right<s.size();right++){
            window[s[right]]++;
            if(need.count(s[right]) && need[s[right]] == window[s[right]]) have++;

            while(have == required){
                if(right-left+1 < minlen){
                minlen = right-left+1;
                start=left;
                }
            if(need.count(s[left]) && need[s[left]]==window[s[left]]) have--;
            

            window[s[left]]--;
                left++;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};