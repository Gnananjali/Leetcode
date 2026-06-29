class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int L=m-1, R=n-1, K=m+n-1;
        while(L>=0 && R>=0){
            if(nums2[R] >= nums1[L]){
                nums1[K] = nums2[R];
                K--;
                R--;
            }else{
                nums1[K] = nums1[L];
                K--;
                L--;
            }
        }
            while(R >= 0){
                nums1[K] = nums2[R];
                R--;
                K--;
        }

    }
};