#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int t;
    int a=0;
    if((t=s.find("Danil"))  != std::string::npos && (s.substr(t+5).find("Danil"))  == std::string::npos)
        a=1;
    if((t=s.find("Olya"))  != std::string::npos && (s.substr(t+4).find("Olya"))  == std::string::npos)
        a+=2;
    if((t=s.find("Slava"))  != std::string::npos && (s.substr(t+5).find("Slava"))  == std::string::npos)
        a+=4;
        if((t=s.find("Ann"))  != std::string::npos && (s.substr(t+3).find("Ann"))  == std::string::npos)
        a+=8;
        if((t=s.find("Nikita"))  != std::string::npos && (s.substr(t+6).find("Nikita"))  == std::string::npos)
        a+=16;
    //cout<<a<<s.find("Nikita")<<endl;
    if((a&(a-1)) || a==0)
    cout<<"NO";
    else
    cout<<"YES";
        cout<<endl;
    return 0;
}