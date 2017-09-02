//first code
#include <bits/stdc++.h>
using namespace std;
int a[10];
int ispos(int i){
    int bi=i%10,ai=(i/10)%10;
    if(a[bi]>=1 && a[ai]>=1 && bi!=ai)
        return true;
    else if(a[bi]>=2 && bi==ai)
        return true;
    return false;
}
int main(){
    int t,n,i,k;
    cin>>t; 
    string s;
    for(;t;t--){
        cin>>s;
        for(i=0;i<10;i++)
        a[i]=0;
        for(i=0;i<s.length();i++){
            a[s[i]-'0']++;
        }
        for(i='A';i<='Z';i++){
            if(ispos(i))
                printf("%c",i);
        }
        cout<<endl;
    }
    return 0;
}