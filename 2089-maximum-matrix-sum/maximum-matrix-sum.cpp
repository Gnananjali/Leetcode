class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absSum=0;
        int negativeCount=0;
        int minAbs = INT_MAX;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                absSum += abs(matrix[i][j]);
                minAbs = min(minAbs, abs(matrix[i][j]));
                
                if(matrix[i][j] < 0){
                    negativeCount++;
                }

            }
        }
        if(negativeCount % 2 == 0){
            return absSum;
        }
        return absSum - 2*minAbs;
    }
};