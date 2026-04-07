class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0], minPro = nums[0], result = nums[0];

        for(int i=1;i<nums.size();i++){
            int num = nums[i];

            if(num < 0) swap(minPro, maxPro);

            maxPro = max(num, maxPro*num);
            minPro = min(num, minPro*num);
result = max(result, maxPro);
  
        }
        return result;
    }
};