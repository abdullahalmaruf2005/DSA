class Solution {
  public:
    void dfs(vector<vector<int>>&adj, vector<int>&vis,int node,stack<int>&st){
        vis[node]=1;
        for(auto u:adj[node]){
            if(vis[u]==-1){
                dfs(adj,vis,u,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       stack<int>st;
       vector<vector<int>>adj(V);
       vector<int>vis(V+1,-1);
       for(int i=0;i<edges.size();i++){
           int a=edges[i][0];
           int b=edges[i][1];
           adj[a].push_back(b);
       }  
       for(int i=0;i<V;i++){
           if(vis[i]==-1){
               dfs(adj,vis,i,st);
           }
       }
       vector<int>ans;
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
       return ans; 
    }
};