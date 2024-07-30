class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int ans=1;
        int n= rooms.size();
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0]=true;

        while(!q.empty()){
            // int s=q.size();
            int nd=q.front();
            q.pop();
            
            for(auto it: rooms[nd]){
                if(!vis[it]){
                    ans++;
                    vis[it]=true;
                    q.push(it);
                }
            }
        }

        for(auto i: vis) {
            if(!i) return false;
        }

        return true;
        // if(ans==n) return true;
        // else return false;
    }
};