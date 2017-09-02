//first code
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,k;
    cin>>t; 
    long long int a[100001];
    long long int b[100001];
    long long int c[100001];
    for(;t;t--){
        cin>>n;
        b[0]=0;
        for(i=0;i<n;i++)
            cin>>a[i],b[i+1]=b[i]+a[i];
        c[n]=0;
        for(i=n-1;i>=0;i--)
            c[i]=c[i+1]+a[i];
        long long int ans=LONG_MAX;
        int ind;
        for(i=0;i<n;i++){
            if(ans>b[i+1]+c[i])
                ans=b[i+1]+c[i],ind=i;
            //cout<<b[i+1]+c[i]<<endl;
            }
        cout<<ind+1<<endl;
    }
    return 0;
}