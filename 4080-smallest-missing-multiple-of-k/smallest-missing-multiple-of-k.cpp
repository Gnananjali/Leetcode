class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp;
        for(int num : nums){
            mp.insert(num);
        }
        
        for(int i=1;i<=INT_MAX;i++){
            
            int num = i * k;
            if(mp.count(num)){
                continue;
            }else{
                return num;
            }
        }
        return 0;
    }
};