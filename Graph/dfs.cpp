#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll gcd(ll a, ll b)
{
  while (b != 0)
  {
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
const int mx=1e5+123;
bool vis[mx];
vector<int> adj[mx];
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}
int main()
{
  int n,e;
  cin>>n>>e;
  for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int c=0;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
        c++;
        dfs(i);
    }
  }
  cout<<c<<endl;
}