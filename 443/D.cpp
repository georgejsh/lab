#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>n;
    char c;
    int x;
    vector< pair<char,int> > vv;
    vector<int > uu(1025);
    int j,l=0,i;
    for(int i=0;i<n;i++)
    {
        cin>>c>>x;
      //  cout<<c<<' '<<x<<endl;
        vv.push_back(make_pair(c,x));
        if(vv[i].first=='|')
            l=l|vv[i].second;
        else if(vv[i].first=='&')
        l=l&vv[i].second;
        else  
        l=l^vv[i].second;
    }
    uu[0]=l;
    //return 0;
    int a[11];
    int _or=0,_and=0,_xor=0;
    for(j=0;j<10;j++){
        l=1<<j;
        for(i=0;i<n;i++)
        {
            if(vv[i].first=='|')
                l=l|vv[i].second;
            else if(vv[i].first=='&')
            l=l&vv[i].second;
            else  
            l=l^vv[i].second;
        }
        l=l&(0x3FF);
        //cout<<l<<" ";
        uu[1<<j]=l;
    }
    
    for(i=0;i<10;i++){
        int check=true;
        /*for(j=0;j<1024;j++){
            if(uu[j]&(1<<i))
                check=false;
        }
        if(check)
            a[i]=0,continue;
        check=true;
        for(j=0;j<1024;j++){
            if(!(uu[j]&(1<<i)))
                check=false;
        }
        if(check)
            a[i]=1,continue;*/
        if((uu[0]&(1<<i))==0 && (uu[1<<i]&(1<<i))==0)
            _and|=(1<<i);
        else if((uu[0]&(1<<i)) && (uu[1<<i]&(1<<i)))
        _or|=(1<<i);
        else if((uu[0]&(1<<i))==0 && (uu[1<<i]&(1<<i)))
            _xor|=(0<<i);
        else   
            _xor|=(1<<i);
    }
        cout<<3<<endl;
        _and=(~_and)&(0x3FF);    
        cout<<"^ "<<_xor;
        cout<<endl;
        cout<<"& "<<_and;
        cout<<endl;
        cout<<"| "<<_or;
        cout<<endl;
    return 0;
}