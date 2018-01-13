#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    int i,j,k;
    cin>>n>>k;
    int a,b;
    a=n-k;
    if(k==1){
        a=min(a,2);
    }
    else if(k>1){
        if(k*3<n)
             a=min(a,k*2);
    }
    else
        a=0;
    if(k>=1)
    b=min(n-k,1);
    else
    b=0;
    cout<<b<<" "<<a<<endl;
    return 0;
}