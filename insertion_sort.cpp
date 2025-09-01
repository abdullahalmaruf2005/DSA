#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int step=1;step<n;step++){
        int key=v[step];
        int i=step-1;
        while(i>=0&&v[i]>key){
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=key;
    }

    for(auto u:v)cout<<u<<" ";
    cout<<endl;
}