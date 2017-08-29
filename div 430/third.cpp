//first code
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int ans[200001];
vector<int>  adjlist[200001];
int gcd(int a,int b) {
                if(a==0)
                    return b;
                if(b==0)
                    return a;
    			if(b>a)
    				return gcd(b,a);
    			if(a%b==0)
    			    return b;
    			return gcd(b,a%b);
    		}
int visited[200001];
int a[200001];
void dfs(int i,set<int> v1,set<int> v2){
    if(visited[i]==1)
        return ;
        
    visited[i]=1;
    set<int> v3,v4;
    for(set<int>::iterator it=v1.begin();it!=v1.end();++it){
        v3.insert(gcd(*it,a[i]));
        v4.insert(*it);
    }
    for(set<int>::iterator it=v2.begin();it!=v2.end();++it){
        v4.insert(gcd(*it,a[i]));
    }
    if(v4.size()==0)
        v4.insert(0);
    if(v3.size()==0)
        v3.insert(a[i]);
    for(int j=0;j<adjlist[i].size();j++){
        dfs(adjlist[i][j],v3,v4);
    }
    //cout<<i<<"\n";
    /*for(set<int>::iterator it=v3.begin();it!=v3.end();++it)
        cout<<*it<<" ";
        cout<<endl;
        for(set<int>::iterator it=v4.begin();it!=v4.end();++it)
        cout<<*it<<" ";
        cout<<endl;
    */ans[i]=max(*(v3.rbegin()),*(v4.rbegin()));
}
int main(){
   
   int n;
   int i;
   cin>>n;
   for(i=0;i<n;i++){
       cin>>a[i+1];
   }    
   //cout<<"k\n";
    for(i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    set<int> v3,v4;
    //v3.insert(a[1]);
    //v4.insert(0);

    dfs(1,v3,v4);
    for(i=0;i<n;i++){
        cout<<ans[i+1]<<" ";
    }
    cout<<"\n";
    return 0;
}