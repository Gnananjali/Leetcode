class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for(int x:hand){
            freq[x]++;
        }
            for(int num:hand){
                if(freq[num] == 0){
                    continue;
                }
                for(int i=0;i<groupSize;i++){
                    int current = num+i;
                    if(freq[current] == 0)
                    return false;

                    freq[current]--;
                }
            
        }
        return true;
    }
};