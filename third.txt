//first code
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int r,d;
    cin>>r>>d;
    int n,c=0,x,y,l;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>l;
        if(l*2>d)
            continue;
        if(sqrt(x*x+y*y+0.0)>=(r-d+l) && sqrt(x*x+y*y+0.0)<=r-l)
            c++;
    }  
    cout<<c<<endl;
    return 0;
}