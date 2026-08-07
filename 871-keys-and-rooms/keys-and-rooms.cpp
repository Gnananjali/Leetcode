class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<bool>& vis, int& count){
        vis[node] = true;
        count++;

        for(int key:rooms[node]){
            if(!vis[key]){
                dfs(key, rooms, vis, count);
            }
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int count=0;
        vector<bool> vis(n, false);
        dfs(0, rooms, vis, count);

        if(count == n) return true;
        return false;
    }
};