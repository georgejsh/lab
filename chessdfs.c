#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int check(int a,int b){
    if(a<0 || b< 0 )
        return 0;
    if(a>7 || b>7)
        return 0;
    return 1;
}
int ar[8][8]={0};
int bfs(int a,int b,int x,int y){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(a,make_pair(b,0)));
    int c;
    while(!q.empty()){
        pair<int ,pair<int, int> > p=q.front();
        q.pop();
        a=p.first;b=p.second.first;c=p.second.second;
        //cout<<a<<" "<<b<<endl;
        if(ar[a][b])
            continue;
        ar[a][b]=c;
        if(a==x && b==y)
            return c;
        if(check(a+2,b+1))
            q.push(make_pair(a+2,make_pair(b+1,c+1)));
        if(check(a+2,b-1))
            q.push(make_pair(a+2,make_pair(b-1,c+1)));
        if(check(a-2,b+1))
            q.push(make_pair(a-2,make_pair(b+1,c+1)));
        if(check(a-2,b-1))
            q.push(make_pair(a-2,make_pair(b-1,c+1)));
        if(check(a+1,b+2))
            q.push(make_pair(a+1,make_pair(b+2,c+1)));
        if(check(a+1,b-2))
            q.push(make_pair(a+1,make_pair(b-2,c+1)));
        if(check(a-1,b+2))
            q.push(make_pair(a-1,make_pair(b+2,c+1)));
        
        if(check(a-1,b-2))
            q.push(make_pair(a-1,make_pair(b-2,c+1)));
        
        
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;int i,a,b,x,y;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b>>x>>y;
        for(int j=0;j<8;j++)
            for(int k=0;k<8;k++)
                ar[k][j]=0;
        cout<<bfs(a,b,x,y)<<endl;
    }
    return 0;
}
