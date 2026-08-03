class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            if(st.top() > nums[i]){
                int x = st.top();
                st.pop();
                st.push(max(x, nums[i]));
            }else if(st.top() <= nums[i]){
                st.push(nums[i]);
            }
        }
        return st.size();
    }
};