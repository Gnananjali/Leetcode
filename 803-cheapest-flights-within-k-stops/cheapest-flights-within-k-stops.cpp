class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        vector<int> temp = dist;
        for(int i=0;i<=k;i++){
            for(auto &it : flights){
                int from = it[0];
                int to = it[1];
                int weight = it[2];

                if(dist[from]!=INT_MAX && dist[from]+weight < temp[to]){
                    temp[to] = dist[from]+weight;
                }


            }
            dist = temp;
        }
        return dist[dst]!=INT_MAX?dist[dst]:-1;
    }
};