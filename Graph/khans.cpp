class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<int>indegree(V,0);
       vector<int>adj[V];
       for(int i=0;i<edges.size();i++){
           int a=edges[i][0];
           int b=edges[i][1];
           adj[a].push_back(b);
           indegree[b]++;
       }
       queue<int>q;
       for(int i=0;i<V;i++){
           if(indegree[i]==0)q.push(i);
       }
       vector<int>ans;
       while(!q.empty()){
           int node=q.front();
           ans.push_back(node);
           q.pop();
           for(auto u:adj[node]){
               indegree[u]--;
               if(indegree[u]==0){
                   q.push(u);
               }
           }
       }
       return ans;
        
    }
};