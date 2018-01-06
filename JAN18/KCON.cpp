#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    vector<long long int> a(100001);
    for(cin>>t;t;t--){
        cin>>n>>k;
        long long int s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        long long int maxhere,mx=maxhere=a[0];
        for(int i=1;i<n;i++){
            maxhere=max(a[i],maxhere+a[i]);
            mx=max(mx,maxhere);
        }
        if(k==1){
            cout<<mx<<endl;
            continue;
        }
        long long int mxf=mx;
        for(int i=0;i<n;i++){
            maxhere=max(a[i],maxhere+a[i]);
            mx=max(mx,maxhere);
        }
        if(k==2 || mxf==mx){
            cout<<mx<<endl;
            continue;
        }
        long long int mxs=mx;
        for(int i=0;i<n;i++){
            maxhere=max(a[i],maxhere+a[i]);
            mx=max(mx,maxhere);
        }
        if(k==3 || mxs==mx){
            cout<<mx<<endl;
            continue;
        }
        cout<<mxs+(k-2)*s<<endl;
    }
	return 0;
}