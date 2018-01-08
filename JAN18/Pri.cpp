#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,x,n;
    long long int a,b,c,d;
    int ar[1000001];
	for(cin>>t;t;t--){
        cin>>x>>n;
        for(int i=0;i<=n;i++)
            ar[i]=0;
        a=(n*1LL*(n+1))/2;
        b=(x*1LL*(x-1))/2;
        a-=x;
        if(a%2==1 || n<=3){
            cout<<"impossible"<<endl;
            continue;
        }
        
        a=a/2;
        //cout<<a<<endl;
        int ii=0;
        for(int i=n;(i>=1) && a;i--,(i=(i>a)?a:i)){
            if(x==2 && a==x){

                ar[ii]=0;
                ar[ii-1]=1;
                ar[3]=1;
                a=a-2;
                continue;
            }
            else if(x==1 && a==x){
                ar[ii]=0;
                ar[ii-1]=1;
                ar[2]=1;
                a=a-1;
                continue;
            }
            if(i==x || i>a)
                continue;
            ar[i]=1;
            a=a-i;
            ii=i;
        }
        
        if(a){
            cout<<"impossible"<<endl;
        }
        else{
            for(int i=1;i<=n;i++)
                if(i!=x)
                cout<<ar[i];
                else
                    cout<<2;
            cout<<endl;
        }


    }
	
	return 0;
}