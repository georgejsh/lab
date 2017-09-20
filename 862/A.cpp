#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    int i,j,k;
    cin>>n>>k;
    int a[101];
    for(i=0;i<=100;i++)
        a[i]=0;
    for(i=0;i<n;i++)
        cin>>j,a[j]++;
    j=0;
    for(i=0;i<k;i++)
        if(!a[i])
            j++;
    if(a[k])
        j++;
    cout<<j<<endl;
    return 0;
}