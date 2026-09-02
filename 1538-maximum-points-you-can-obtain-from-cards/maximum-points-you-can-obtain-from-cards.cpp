class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0;
        int minSum = INT_MAX;
        int sum = 0;
        int size = cardPoints.size() - k;
        int total = 0;
        for(int i=0;i<cardPoints.size();i++){
            total += cardPoints[i];
        }
        for(int right=0;right<cardPoints.size();right++){
            sum += cardPoints[right];

            while(right-left+1 > size){
                sum -= cardPoints[left];
                left++;
            }
            if(right-left+1 == size){
                minSum = min(minSum, sum);
            }
        }
        return total - minSum;
    }
};