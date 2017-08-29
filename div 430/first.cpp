//first code
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    int i;
    for(i=l;i<=r;i++){
        if(i%k!=0)
            continue;
        int j=i/k;
        if(x<=j && j<=y){
            cout<<"YES\n";
            break;
        }            
    }
    if(i>r)
        cout<<"NO\n";   
    return 0;
}