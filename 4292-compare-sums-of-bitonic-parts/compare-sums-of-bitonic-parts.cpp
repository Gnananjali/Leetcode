class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        int maxVal = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > nums[maxVal])
                maxVal = i;
        }
        long long ascSum = 0, dscSum = 0;
        for(int j=0;j<=maxVal;j++){
            ascSum += nums[j];
        }
        for(int k=maxVal;k<n;k++){
            dscSum += nums[k];
        }
        if(ascSum == dscSum) return -1;
        else if (ascSum > dscSum) return 0;
        else return 1;
    }
};