#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    long long int ll;
    cin>>n>>ll;
    int a[501];
    deque<int> q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];  
        
        q.push_back(a[i]);
    }
    
    vector<int> vv(n+1);
    int win;
    for(;;){
        int j=q.front();
        q.pop_front();
        int k=q.front();
        q.pop_front();
        win=max(j,k);
        if(j==n)
            break;
         
        int loss=min(j,k);
        q.push_back(loss);
        q.push_front(win);
        vv[win]++;
        if(vv[win]==ll)
            break;
    }
    cout<<win;
        cout<<endl;
    return 0;
}