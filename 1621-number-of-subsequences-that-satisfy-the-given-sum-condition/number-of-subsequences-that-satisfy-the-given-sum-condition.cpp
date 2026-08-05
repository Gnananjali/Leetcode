class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        int left=0, right=nums.size()-1;
        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%MOD;
        }
        while(left<=right){
            if(nums[right]+nums[left] <= target){
                count = (count+power[right-left])%MOD;
                left++;
            }else{

            right--;
            }
        }
        return count;
    }
};