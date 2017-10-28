#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i,j=0,k=0;
    vector<int> v,v1(s.size()+1),v2(s.size()+1),v3(s.size()+1);
    for(i=0;i<s.size();i++){
       if(s[i]=='a')
        v1[i+1]=v1[i]+1;
        else
        v1[i+1]=v1[i];
        if(s[i]=='b')
        v3[i+1]=v3[i]+1;
        else
        v3[i+1]=v3[i];
    }
    int ma=0;
    for(i=s.size()-1;i>=0;i--){
        if(s[i]=='a')
         v2[i]=v2[i+1]+1;
         else
         v2[i]=v2[i+1];
     }
    /*cout<<endl;
    for(i=0;i<=s.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<=s.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<=s.size();i++){
        cout<<v2[i]<<" ";
    }*/
    //cout<<endl;
    for(i=0;i<s.size();i++){
        for(j=i;j<s.size();j++){
           // cout<<v1[i]+v2[j+1]+v3[j+1]-v3[i]<<" ";
            ma=max(ma,v1[i]+v2[j+1]+v3[j+1]-v3[i]);
        }
        //cout<<"\n";
    }
        cout<<ma<<endl;
    return 0;
}