#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m;
    char a[5001],b[5001];
    int dd[5005],cc[5005];
    for(cin>>t;t;t--){
        cin>>n>>m;
        cin>>a>>b;
        dd[n-1]=dd[n]=0;
        cout<<"0 0 "; 
        for(int j=n-2;j>=0;j--){
            if(a[j]!=a[j+1])
                dd[j]=dd[j+1]+1;
            else
                dd[j]=dd[j+1];
            cout<<dd[j]<<" ";
        }
        cout<<endl;
        int k,tmp,l,j,i;
        for(i=m-1;i>=0;i--){
            k=0;tmp=0;
            if(i!=m-1 && b[i+1]!=a[n-1])
                tmp--;
            if(i!=m-1 && b[i+1]!=b[i])
                tmp++;
            if(b[i]!=a[n-1])
                tmp++;
            k=max(k,dd[n]);
            dd[n]=k+tmp;
            cout<<i<<"_"<<dd[n]<<" ";
            for(j=n-1;j>0;j--){
                tmp=0;
                l=0;
                if(b[i]!=a[j-1])
                    tmp++;
                if(b[i]!=a[j])
                    tmp++;
                l=max(l,k+tmp);
                tmp=0;
                if(i!=m-1 && b[i+1]!=a[j-1])
                    tmp--;
                else if(i==m-1 && a[j-1] != a[j])
                    tmp--;
                if(i!=m-1 && b[i+1]!=b[i])
                    tmp++;    
                if(b[i]!=a[j-1])
                    tmp++;
                l=max(l,dd[j]+tmp);
                k=max(k,dd[j]);
                dd[j]=l;
                cout<<j<<"_"<<dd[j]<<" ";
            }
            l=0;
            tmp=0;
            if(b[i]!=a[j])
                tmp++;
            l=max(l,k+tmp);
            tmp=0;
            if(i!=m-1 && b[i+1]!=b[i])
                tmp++;
            l=max(l,dd[j]+tmp);
            dd[j]=l;
            cout<<j<<"_"<<dd[j]<<endl;
        }
        k=max(dd[0],dd[1]);
        l=0;
        for(i=1;i<n;i++){
            k=max(k,dd[i]+l);
            if(a[i-1]!=a[i])
                l++;
        }
        k=max(k,dd[i]+l);
        cout<<k<<endl;

    }
	
	return 0;
}