//first code
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
set<int> a;
int findmin(int l){
    int k;
    for(k=0;;k++){
        if(a.find(k^l)!=a.end())
            continue;
        else
            return k;
    }
}
int main(){
    int n,m;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>j,a.insert(j);
    int k=0;
    int v=findmin(k),vv=v;
    for(i=0;i<m;i++){
        cin>>j;
        if(j==0){
            cout<<v<<endl;
            continue;
        }
        if(k==0){
            cout<<vv<<endl;
            continue;
        }
        k=k^j;
        v=findmin(k)
        cout<<v<<endl;
    }
    return 0;
}