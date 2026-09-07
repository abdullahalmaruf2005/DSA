#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl 
ll gcd(ll x, ll y)
{
    while (y)
    {
        ll t = y;
        y = x % y;
        x = t;
    }
    return x;
}

class disjointset{
    vector<ll>parent;
    vector<ll>sz;
    public:
    disjointset(int n){
        parent.resize(n+1,0);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    ll find_parent(int node){
        if(node==parent[node])return node;
        return parent[node]=find_parent(parent[node]);
    }

    void unionbysize(int u,int v){
        int a=find_parent(u);
        int b=find_parent(v);
        if(a==b)return;
        if(sz[a]<sz[b]){
            parent[a]=b;
            sz[b]+=sz[a];
        }else{
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
};

int main() {
disjointset ds(7);
ds.unionbysize(1,2);
ds.unionbysize(2,3);
ds.unionbysize(4,5);
ds.unionbysize(6,7);
ds.unionbysize(5,6);
if(ds.find_parent(3)==ds.find_parent(7)){
    cout<<"sm"<<endl;
}else{
    cout<<"no"<<endl;
}
ds.unionbysize(3,7);
if(ds.find_parent(3)==ds.find_parent(7)){
    cout<<"sm"<<endl;
}else{
    cout<<"no"<<endl;
}

}