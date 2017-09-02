#include <bits/stdc++.h>
using namespace std;
int a[1001],n;

pair<long long int,long long int> slope(int x1,int y1,int x2,int y2){
    return make_pair((y2-y1),(x2-x1));
}
pair<long long int,long long int> fc(pair<long long int,long long int> s,int x1,int y1){
    return make_pair((y1*s.second-s.first*x1),s.second);
}
bool checkp(pair<long long int,long long int> s,int x1,int y1){
    pair<long long int,long long int> c=fc(s,x1,y1);
    int ok[1001];
    for(int i=0;i<n+1;i++)
        ok[i]=0;
    int j=-1,k=-1;
    for(int i=0;i<n;i++){
        if(a[i]*s.second==(s.first*(i+1)+c.first))
            ok[i]=1;
        else if(j==-1)
            j=i;
        else if(k==-1)
            k=i;
            
    }
    if(j==-1 && k==-1)
        return false;
    if(j==-1 || k==-1)
        return true;
    pair<long long int,long long int> s1=slope(j+1,a[j],k+1,a[k]);
    pair<long long int,long long int> c1=fc(s1,j+1,a[j]);
    if(s.first*s1.second!=s.second*s1.first)
        return false;
    bool flag=true;
    for(int i=0;i<n;i++){
        if((a[i]*s1.second==(s1.first*(i+1)+c1.first)) && ok[i]!=1)
            ok[i]=1;
        else if(a[i]*s1.second==(s1.first*(i+1)+c1.first))
            flag=false;
    }
    for(int i=0;i<n;i++){
        if(!ok[i])
            flag=false;
    }
    
    return flag;
}
int check(int x,int y,int z){
    pair<long long int,long long int> s1,s2,s3;
    s1=slope(1,x,2,y);
    s2=slope(1,x,3,z);
    s3=slope(2,y,3,z);
    if(checkp(s1,1,x))
    return true;
    if(checkp(s2,1,x))
        return true;
    if(checkp(s3,2,y))
        return true;
}
int main(){
    int t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(check(a[0],a[1],a[2]))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}