class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       set<pair<int,int>>pq;
        pq.insert({0,src});
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        vector<int>distance(V,INT_MAX);
        distance[src]=0;
        while(!pq.empty()){
            int d=pq.begin()->first;
            int node=pq.begin()->second;
            pq.erase(pq.begin());
            if(d > distance[node]) continue;
            for(auto u:adj[node]){
                int a=u.first;
                int b=u.second;
                if(b+d<distance[a]){
                    pq.insert({b+d,a});
                    distance[a]=b+d;
                }
            }
        }
        return distance;
    }
};