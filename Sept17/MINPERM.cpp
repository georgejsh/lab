//first code
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,k;
    cin>>t; 
    //priority_queue<int,vector<int>,std::greater<int> > pq;
    for(;t;t--){
        cin>>n;
       // for(i=0;i<n;i++)
         //   pq.push(i+1);
       // for(i=0;i<n-2;i++){
          /*  int j=pq.top();
            pq.pop();
            if(j==i+1){
                k=pq.top();
                pq.pop();
                cout<<k<<" ";
                pq.push(j);
            }
            else
                cout<<j<<" ";
        }*/
        if(n%2==0)
            for(i=0;i<n;i+=2)
                cout<<i+2<<" "<<i+1<<" ";
        else{
            for(i=0;i<n-4;i+=2)
                cout<<i+2<<" "<<i+1<<" ";
            cout<<i+2<<" "<<i+3<<" "<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}