class Solution {
public:
    bool capacityOfShip(vector<int>& weights, int days, int capacity){
        int currentLoad = 0;
        int daysUsed = 1;
        for(int weight:weights){
            if(currentLoad+weight <= capacity){
                
                currentLoad += weight;
            }else{
                daysUsed++;
                currentLoad = weight;
            }
            
        }
        return daysUsed <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        for(int weight:weights){
            sum+=weight;
        }
        int left=*max_element(weights.begin(), weights.end());
        int right=sum;
        while(left<right){
            int mid = left+(right-left)/2;
            if(capacityOfShip(weights, days, mid)){
                right=mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};