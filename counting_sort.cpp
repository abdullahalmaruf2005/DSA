#include<bits/stdc++.h>
using namespace std;
vector<int> temp;
void counting(vector<int> &v,int n){
    int mx=*max_element(v.begin(),v.end());
     vector<int> p(mx+1,0);
     for(int i=0;i<n;i++){
        p[v[i]]++;
     }
     temp=p;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    counting(v,n);
    for(int i=0;i<=n;i++){
        if(temp[i]>0){
            for(int j=0;j<temp[i];j++)cout<<i<<" ";
        }
    }
}