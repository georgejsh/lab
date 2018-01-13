#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,kk,m;
    cin>>n>>kk>>m;
    int a[100001];
    vector<pair<int,int> > vv;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int j=a[0],k=1;int i=1;
    for(;i<n;i++){
        if(a[i]!=j){
            if(k%kk)
                vv.push_back(make_pair(j,k%kk)),j=a[i],k=1;
            else if(vv.size()>=1){
                j=vv.back().first,k=vv.back().second;
                i--;
                vv.pop_back();
            }
            else{
                j=a[i],k=1;
            }
            
        }
        else
            k++;
    }
    long long int bal=0;
    if(k%kk)
        vv.push_back(make_pair(j,k%kk));
    if(vv.size()==0){
        cout<<0<<endl;
        return 0;
    }
    if(m==1){
        for(i=0;i<vv.size();i++){
            bal+=(vv[i].second*1LL*m);
        }
        cout<<bal<<endl;
        return 0;
    }
    if(kk>=n && vv.size()!=1){
        cout<<m*1LL*n<<endl;
        return 0;
    }
    if(vv.size()==1){
        cout<<(m*1LL*n)%kk<<endl;
        return 0;
    }

    j=vv.size()-1;
    //cout<<vv.size();
    bool flag=true;
    for(i=0;i<j;i++){
        //cout<<vv[i].second<<" "<<vv[j].second<<endl;
        if(vv[i].first==vv[j].first && (vv[i].second+vv[j].second)==kk){
            j--;
            //if(i==0)
            bal+=kk;
        } 
        else if(vv[i].first==vv[j].first && (vv[i].second+vv[j].second)>kk){
            bal+=vv[i].second+vv[j].second;
            bal+=((vv[i].second+vv[j].second)%kk)*1LL*(m-1);
            i++;j--;
            flag=false;
            break;
        }
         else
         break;   
         //cout<<i<<" "<<j<<endl;
    }
    //cout<<i<<" "<<bal<<" "<<j<<endl;
    if(i==j && flag){
        if((vv[i].second*1LL*m)%kk==0){
            cout<<bal%kk<<endl;
           // cout<<"H";
            return 0;
        }
        else{
            cout<<((vv[i].second*1LL*m)%kk)+bal<<endl;
           // cout<<"Hi";
            return 0;
        }
    }
    
   // if(i!=0)
     //   bal+=kk;
    for(;i<=j;i++){
        bal+=(vv[i].second*1LL*m);
    }
    cout<<bal;
        cout<<endl;
    return 0;
}