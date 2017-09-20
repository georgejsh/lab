#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[100001];
vector<int> s[2];
void dfs(int i,int p,int l){
    int j;
    s[l].push_back(i);
    for(j=0;j<a[i].size();j++){
        if(a[i][j]==p)
            continue;
        dfs(a[i][j],i,(l+1)%2);
    }
}

int main(){
    int t;
    int i,k,l;
    cin>>n;
    for(i=0;i<100001;i++)
        a[i].clear();
    for(i=0;i<n-1;i++)
        cin>>l>>k,a[l].push_back(k),a[k].push_back(l);
    dfs(1,-1,0);
    long long int j=0;
    for(i=0;i<s[0].size();i++)
        j+=s[1].size()-a[s[0][i]].size();
    cout<<j<<endl;
    return 0;
}