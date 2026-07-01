class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hadFreq(26,0);
        vector<int> window(26,0);

        for(char c:p){
            hadFreq[c-'a']++;
        }
        int left=0;
        vector<int> ans;
        for(int right=0;right<s.size();right++){
            window[s[right]-'a']++;

            if(right-left+1 == p.size()){
            if(window == hadFreq){
                ans.push_back(left);
            }
                window[s[left]-'a']--;
                left++;
        }
        }
        return ans;
    }
};