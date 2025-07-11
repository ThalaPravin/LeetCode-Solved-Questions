class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>graphs(num,vector<int>());
        vector<int>indegree(num);
        for(vector<int>&ans : prerequisites){
            graphs[ans[0]].push_back(ans[1]);
            indegree[ans[1]]++;
        }
        queue<int>zero;
        for(int i=0;i<num;i++){
            if(indegree[i] == 0) zero.push(i);
        }
        int visited = 0;
        while(!zero.empty()){
            int temp = zero.front();
            zero.pop();
            visited++;
            for(int v:graphs[temp]){
                indegree[v]--;
                if(indegree[v] == 0){
                    zero.push(v);
                }
            }
        }
        return visited == num? true:false; 
    }
};