#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,x;
    cin>>n>>k>>x;
    int a[101];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n-k;i++){
        ans+=a[i];
    }
    cout<<ans+k*x;
        cout<<endl;
    return 0;
}