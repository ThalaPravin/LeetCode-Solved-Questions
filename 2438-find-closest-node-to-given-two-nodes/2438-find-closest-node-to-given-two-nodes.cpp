class Solution {
public:

    void dfs( int curnode, int dis, vector<int> &dist, vector<int>&edges){
        while(curnode!=-1 && dist[curnode]==-1){
            dist[curnode]= dis++;
            curnode= edges[curnode];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dis1(n,-1);
        vector<int>dis2(n,-1);

        int mn= INT_MAX; 
        
        dfs(node1, 0 , dis1, edges);
        dfs(node2, 0, dis2 , edges);

        int ans=-1;
    
        for(int i=0; i<n; i++){
            if(dis1[i]>=0 && dis2[i]>=0){
                int tempmn= max(dis1[i],dis2[i]);
                if(tempmn< mn){
                    mn=tempmn;
                    ans=i;
                }
            }
        }
      

        return ans;

    }
};

