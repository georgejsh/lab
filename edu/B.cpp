#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,x;
    cin>>n;
    vector<pair<int,int> > a;
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
            j++;
        else
            j--;
        a.push_back(make_pair(j,i));
        //cout<<i<<" "<<j<<endl;
    }
    sort(a.begin(),a.end());
    //for(int i=0;i<n;i++)
        //cout<<a[i].first<<' '<<a[i].second<<endl;
    int ans=0;
    
    for(int i=0;i<n;){
        if(a[i].first==0)
            ans=max(ans,a[i].second+1);
        for(j=i+1;j<n && a[j].first==a[i].first;j++){
            ans=max(ans,a[j].second-a[i].second);
            if(a[j].first==0)
                ans=max(ans,a[j].second+1);
        }

        i=j;
    }
        cout<<ans<<endl;
    return 0;
}