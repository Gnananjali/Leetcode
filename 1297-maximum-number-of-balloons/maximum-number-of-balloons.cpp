class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mp;
        for(char ch:text){
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n' ){
            mp[ch]++;
        }else{
            continue;
        }
        }
        return min({
            mp['b'],
            mp['a'],
            mp['l']/2,
            mp['o']/2,
            mp['n']
        });
        
    }
};