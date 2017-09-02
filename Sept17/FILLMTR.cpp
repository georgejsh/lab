//first code
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adjl[100001];
int visited[100001];
int ans[100001];
int n;
bool check(int i,bool v){
    if(visited[i])
        return true;
    visited[i]=true;
    ans[i]=v;
    bool flag=true;
    for(int j=0;j<adjl[i].size();j++){
        if(visited[adjl[i][j].first]){
            if(ans[adjl[i][j].first]^ans[i]^adjl[i][j].second)
                return false;
        }
        else{
            flag&=check(adjl[i][j].first,v^adjl[i][j].second);
        }
    }
    return flag;
}
int main(){
    int t,i,j,k,q;
    cin>>t; 
    map<pair<int,int>,int> gr;
    for(;t;t--){
        gr.clear();
        cin>>n>>q;
        for(i=0;i<n+1;i++)
            visited[i]=false,adjl[i].clear();
        bool flag=true;
        int val;
        for(i=0;i<q;i++){
            cin>>j>>k>>val;
            if(gr.find(make_pair(k,j))!=gr.end()){
                if(gr[make_pair(k,j)]!=val)
                    flag=false;
            }
            else {
                gr[make_pair(j,k)]=val;
                adjl[j].push_back(make_pair(k,val));
                adjl[k].push_back(make_pair(j,val));
            }
            if(j==k && val!=0)
                flag=false;            
        }
        if(!flag){
            cout<<"no"<<endl;
            continue;
        }
        for(i=0;i<n+1;i++)
            flag&=check(i,0);
        if(flag){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}