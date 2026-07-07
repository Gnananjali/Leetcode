class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum){
        int currentSum = 0, subarrays=1;
        for(int num:nums){
            if(currentSum+num <= maxSum){
                currentSum += num;
            }else{
                subarrays++;
                currentSum=num;
            }
        }
        return subarrays<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        int left = *max_element(nums.begin(), nums.end());
        int right = sum;
        while(left<right){
            int mid = left+(right-left)/2;
            if(canSplit(nums, k, mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};