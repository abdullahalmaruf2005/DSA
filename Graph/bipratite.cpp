bool dfs(vector<vector<int>>& graph,vector<int>&color,int col,int node){
       color[node]=col;
       for(auto u:graph[node]){
        if(color[u]==-1){
           if( dfs(graph,color,!col,u))return true;
        }else if(color[u]==color[node]){
            return true;
        }
       }
       return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);

        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(dfs(graph,color,0,i))return false;
            }
        }
        return true;

    }