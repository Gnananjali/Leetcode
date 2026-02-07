class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;

        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]>nums[right])
            left = mid+1;
            else
            right = mid;
        }
        return nums[left];
    }
};




Algorithm:
• Initialize two pointers:
  left = 0
  right = n - 1

• Repeat while left < right:

  • Find middle index
    → mid = (left + right) / 2

  • If nums[mid] > nums[right]
    → Minimum is in the right half
    → Move left = mid + 1

  • Else
    → Minimum is in left half (including mid)
    → Move right = mid

• When loop ends, left points to minimum element

• Return nums[left]
