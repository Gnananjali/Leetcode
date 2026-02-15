class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int actSum = 0;
        
        int maxSum = (n * (n+1))/2;
        for(int i:nums){
            actSum += i;
                    }
        return maxSum-actSum;
    }
};