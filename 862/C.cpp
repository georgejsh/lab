#include <bits/stdc++.h>
#include <iterator>

using namespace std;

int main(){
    int t,n;
    int i,j,k;
    cin>>n>>k;
    j=k;
     int a[100001];
    for(i=0;i<n-1;i++)
        a[i]=i,j^=i;
    a[i]=j;
    if(n==2 && k==0){
        
                        cout<<"NO\n";
                        return 0;
                    }
    if(j<n-1)
    {
        if(n%2==1){
            for(i=0;i<n-1;i++)
            a[i]+=(1<<18);    
        }
        else{
            for(i=0;i<n-2;i++)
            a[i]+=(1<<18);
            if(a[n-1]==a[n-2]){
                if(n>=3){
                    a[n-3]+=1<<17;
                    a[n-1]+=1<<17;
                }
            }
        }
    }
    cout<<"YES\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
/*set<pair<int,int> > ss,tt;
    set<pair<int,int> >::iterator it,itt;
    ss.insert(make_pair(1,n));
    long long int a[100001];
    for(i=0;i<100001;i++)
        a[i]=0;
    long long int vv=1;
    int pflag=0;
    int safe=-1;
    while(1){
        int l=j%2;
        int flag=0;
        {
            for(it=ss.begin();it!=ss.end();it++){
                int nn=it->second-it->first+1,mid;
                //cout<<nn<<" nn "<<it->first<<" "<<it->second<<endl;
                if(nn!=1)        {
                    mid=(it->second+it->first)/2;
                    itt=next(it,1);
                    if((itt)==ss.end()){
                        if(l && (mid-(it->first)+1)%2==0)
                            mid--;
                        else if(!l && ((it->second)-mid)%2==1)
                            mid--;
                    }
                    if(mid<it->first){
                        if(safe!=-1){
                            a[safe]+=vv;
                            mid++;
                        }
                        else{
                            tt.insert(make_pair(it->first,it->second));
                            flag=2;
                                        continue;    
                        }
                        
                    }
                    
                    //cout<<"l "<<l<<" mid "<<mid<<endl;
                    if(l){
                        for(k=it->first;k<=mid;k++)      
                            a[k]+=vv;
                    }
                    else{
                        for(k=mid+1;k<=it->second;k++)      
                            a[k]+=vv;
                    }
                    if((mid-(it->first)+1)%2==1 && l){
                            l=(l+1)%2;
                    }
                    else if(((it->second)-mid)%2==1 && !l){
                        l=(l+1)%2;
                    }
                    if((mid-(it->first)+1)!=1)
                    tt.insert(make_pair(it->first,mid));
                    else if(!l)
                        safe=it->first;
                    if(((it->second)-mid)!=1)
                    tt.insert(make_pair(mid+1,it->second));
                    else if(l)
                    safe=it->second;
                    flag=1;
                }
                else
                    safe=it->first;
                
            }
            ss.clear();
            ss.insert(tt.begin(),tt.end());
            tt.clear();
        }
        
        if(!flag)
        break;
        if(pflag==flag && flag==2 && j==0)
            break;
        pflag=flag;
        vv*=2;
        j=j/2;
        if(vv>1000000LL){
            cout<<"NO\n";//<<nn;
            return 0;
        }
 // for(i=1;i<=n;i++)
  //      cout<<a[i]<<" ";
  //  cout<<endl;
    }
    for(it=ss.begin();it!=ss.end();it++){
        int nn=it->second-it->first+1;
        if(nn!=1) 
            {
                cout<<"NO\n";//<<nn;
                return 0;
            }
    }
    
    cout<<"YES\n";
    vv/=2;
    while(vv){
        j*=2;
        vv/=2;
    }
    if(j)
        a[1]+=j;
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
  */  return 0;
}