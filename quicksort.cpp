#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(int *a,int l,int r){
    int i=l,j=r;
    int pivot=a[l];
    while (i<j)
    {
       while (a[i]<=pivot)
       {
        i++;
       }
       while (a[j]>pivot)
       {
        j--;
       }
       if(i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}


void quick(int a[],int l, int h){
    if(l<h){
        int pi=partition(a,l,h);
        quick(a,l,pi-1);
        quick(a,pi+1,h);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    quick(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}