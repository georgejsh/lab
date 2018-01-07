#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m;
    char a[5001],b[5001];
    int dd[5005];
    for(cin>>t;t;t--){
        cin>>n>>m;
        cin>>a>>b;
        dd[n]=0;
       // cout<<"0 ";
        int j; 
        for(j=n-1;j>0;j--){
            if(a[j]!=a[j-1])
                dd[j]=dd[j+1]+1;
            else
                dd[j]=dd[j+1];
          //  cout<<dd[j]<<" ";
        }
        dd[j]=dd[j+1];
        //cout<<endl;
        int k,tmp,l,i,kk;
        for(i=m-1;i>=0;i--){
            k=INT_MAX;tmp=0;
            if(i!=m-1 && b[i+1]!=a[n-1])
                tmp--;
            if(i!=m-1 && b[i+1]!=b[i])
                tmp++;
            if(b[i]!=a[n-1])
                tmp++;
            k=min(k,dd[n]);
            dd[n]=k+tmp;
          //  cout<<i<<"_"<<dd[n]<<" ";
          //  cout<<"k "<<k;
            for(j=n-1;j>0;j--){
                tmp=0;
                l=INT_MAX;
                if(b[i]!=a[j-1])
                    tmp++;
                if(b[i]!=a[j])
                    tmp++;
              //  cout<<" tmp "<<tmp;
                l=min(l,k+tmp);
              //  cout<<" l1 "<<l;
                tmp=0;
                if(i!=m-1 && b[i+1]!=a[j-1])
                    tmp--;
                else if(i==m-1 && a[j-1] != a[j])
                    tmp--;
                if(i!=m-1 && b[i+1]!=b[i])
                    tmp++;    
                else if(i==m-1 && b[i] != a[j])
                    tmp++;
                if(b[i]!=a[j-1])
                    tmp++;
                kk=0;
                if(a[j]!=a[j-1])
                    kk++;
              //  cout<<" kk "<<kk;
              //  cout<<" tmp "<<tmp;    
                l=min(l,dd[j]+tmp);
              //  cout<<" l2 "<<l;
                k=min(k+kk,dd[j]);
               // cout<<" k "<<k;
                dd[j]=l;
               // cout<<" "<<j<<"_"<<dd[j]<<" ";
            }
            l=INT_MAX;
            tmp=0;
            if(b[i]!=a[j])
                tmp++;
            l=min(l,k+tmp);
            tmp=0;
            if(i!=m-1 && b[i+1]!=b[i])
                tmp++;
            else if(i==m-1 && b[i] != a[j])
                tmp++;
            l=min(l,dd[j]+tmp);
            dd[j]=l;
            //cout<<j<<"_"<<dd[j]<<endl;
        }
        k=min(dd[0],dd[1]);
        l=0;
        for(i=1;i<n;i++){
            k=min(k,dd[i]+l);
            if(a[i-1]!=a[i])
                l++;
        }
        k=min(k,dd[i]+l);
        cout<<k+1<<endl;

    }
	
	return 0;
}