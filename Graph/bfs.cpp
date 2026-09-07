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
int lvl[mx];
vector<int> adj[mx];

void bfs(int s){
    memset(lvl,-1,sizeof(lvl));
    queue<int> q;
    lvl[s]=0;
    q.push(s);
    while (!q.empty())
    {
       int u=q.front();
       q.pop();
       for(auto v:adj[u])
       {
        if(lvl[v]==-1){
            lvl[v]=lvl[u]+1;
            q.push(v);
        }
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
  bfs(1);
  cout<<lvl[n]<<endl;
}