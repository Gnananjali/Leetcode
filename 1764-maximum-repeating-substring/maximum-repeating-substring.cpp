class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int m = sequence.size();
        int n = word.size();

        vector<int> dp(m+1, 0);
        
        for(int i=n;i<=m;i++){
            if(sequence.substr(i-n, n) == word){
                dp[i] = dp[i-n]+1;
            }
            
        }
        return *max_element(dp.begin(), dp.end());
    }
};