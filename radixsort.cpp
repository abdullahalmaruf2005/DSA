#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int getMax(vector<int>&a){
    int mx=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>mx)mx=a[i];
    }
    return mx;
}

void callsort(vector<int>&a,int e){
    int n=a.size();
    int cnt[10]={0};
    int ans[n];
    for(int i=0;i<n;i++){
        cnt[(a[i]/e)%10]++;
    }
    for(int i=1;i<10;i++){
        cnt[i]+=cnt[i-1];
    }

    for(int i=n-1;i>=0;i--){
        ans[cnt[((a[i]/e)%10)]-1]=a[i];
        cnt[(a[i]/e)%10]--;
    }
    for(int i=0;i<n;i++)a[i]=ans[i];
    
}



void radixSort(vector<int>&a){
    int mx=getMax(a);

    for(int i=1;mx/i>0;i*=10){
        callsort(a,i);
    }
}
int main(){
   
    vector<int>a={170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(a);

    for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
}