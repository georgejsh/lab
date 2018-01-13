#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==1 || b==1)
    return 1;
 if(a==0)
  return b;
 if(b==0) return a;
 
 if(b>a)
  return gcd(b,a);
 if(a%b==0)
  return b;
  return gcd(b,a%b);
}
int main(){
    int t,n;
    int i,j,k;
    cin>>n;
    int a,b;
    for(int i=1;i<=n/2;i++){
        if(gcd(i,n-i)==1)
            a=i,b=n-i;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}