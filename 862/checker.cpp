#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    int i,j,k;
    cin>>n;
    k=0;
    for(i=0;i<n;i++)
        cin>>j,k^=j;
    cout<<k<<endl;
    return 0;
}