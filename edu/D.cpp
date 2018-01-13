#include <bits/stdc++.h>
using namespace std;
int a[100001];
int k;
void find(int i,int j) {
    if((j-i)==1)
        return;
    if(k){
        int mid=(i+j)/2;
        //cout<<mid<<endl;
        int t=a[mid];
        a[mid]=a[mid-1];
        a[mid-1]=t;
        k--;
        find(i,mid);
        find(mid,j);
    }
    else
        return;
    
}
int main(){
    int t,n,x;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        a[i]=i+1;
    if(k%2==0){
        cout<<-1<<endl;
        return 0;
    }
    k--;
    k=(k+1)/2;
    find(0,n);
    if(k){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}