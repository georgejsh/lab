#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>n;
    int a[101];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    if(n%2==0)
        cout<<"No";
    else if(a[0]%2==0 || a[n-1]%2==0)
    cout<<"No";
    else
        cout<<"Yes";
        cout<<endl;
    return 0;
}