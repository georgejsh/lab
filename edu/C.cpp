#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k,m;
    cin>>n>>m>>k;
    int a[101][101];
    //int b[101][101];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    int ans=0,move=0;
    int count=0;
    for(int i=0;i<m;i++){
        int temp=0,tm=INT_MAX;
        for(int j=n-1;j>=0;j--){
            int c=0;
            
      //      b[j][i]=0;
            for(int l=0;l<k;l++){
                if(l+j<n && a[l+j][i])
                    c++;
            }
            int cc=0;
            for(int l=0;l<j;l++){
                if(a[l][i])
                    cc++;
            }
          //  cout<<c<<endl;
            temp=max(temp,c);
            if(temp==c)
                tm=min(tm,cc);
        //    b[j][i]=c;
        }
        //cout<<endl;
        ans+=temp;
        move+=tm;
    }
    cout<<ans<<" "<<move;
        cout<<endl;
    return 0;
}