#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,q,x,y;
    int a[300000];
    vector<pair<int,int> >  b[500000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        x=x&0x3FFFF;
        b[x].push_back(make_pair(i,y));
    }
    make(0,0x3FFFF);
	return 0;
}