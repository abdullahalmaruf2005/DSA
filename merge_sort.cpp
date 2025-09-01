#include<bits/stdc++.h>
using namespace std;
const int mx=2e5;
int a[mx];
void merges(int l,int mid, int r){
    int p=l;
    int q=mid+1;
    int temp[r-l+1];
    int k=0;
    while (p<=mid&&q<=r)
    {
        if(a[p]<=a[q]){
            temp[k]=a[p];
            p++;k++;
        }
        else{
            temp[k]=a[q];
            k++;
            q++;
        }
    }
    while (p<=mid)
    {
        temp[k]=a[p];
        p++;
        k++;
    }
     while (q<=r)
    {
        temp[k]=a[q];
        q++;
        k++;
    }
    k=0;
    for(int i=l;i<=r;i++){
        a[i]=temp[k];
        k++;
    }    
    
}
void mergesort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merges(l,mid,r);
}
int main(){
    

    int n;
    cin>>n;

    for(int i=1;i<=n;i++)cin>>a[i];
    mergesort(1,n);
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}