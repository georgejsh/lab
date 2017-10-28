#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>n;
    long long int a,b;
    cin>>a>>b;  
    long long int next=a;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;  
        if(a<=next)
        next=ceil(((next-a+1)*1.0)/b)*b+a;
        else
        next=a;

    }
    cout<<next;
        cout<<endl;
    return 0;
}