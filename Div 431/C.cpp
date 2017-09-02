#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,j;
    vector<int> a;
    for(i=1,j=0;i<1000;i++){
        j+=i;
        a.push_back(j);
  //      cout<<j<<" ";
    }
    cin>>n;
    if(n==0){
        cout<<"a"<<endl;
        return 0;
    }
    int l[26];i=0;
    vector<int>::iterator low;
    while(n){
        if(n==1){            
            l[i++]=2;
            break;
        }
        low=lower_bound(a.begin(),a.end(),n);
        if(*low>n)
        low--;
        l[i++]=(low-a.begin())+2;
        n-=*low;
    }
    for(j=0;j<i;j++){
        while(l[j]--)
        printf("%c",j+'a');
    }
        //cout<<l[j]<<" ";
        cout<<endl;
    return 0;
}
//a a a a a a
//aa aa aa 