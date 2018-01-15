#include<bits/stdc++.h>
using namespace std;
int ans=0;
pair<int,int> play_game_10(){
    int x,y,z;
    cin>>x;
    pair<int,int> p2;
    if(x==10){
        cin>>y>>z;
        //cout<<x+y+z<<endl;
        ans+=x+y+z;
        return make_pair(x,y);
    }
    cin>>y;
    if((x+y)==10){
        cin>>z;
        //cout<<x+y+z<<" ";
        ans+=x+y+z;
        return make_pair(x,y);
    }
    //cout<<x+y<<" ";
    ans+=x+y;
    return make_pair(x,y);
}
pair<int,int> play_game(int i){
    int x,y;
    if(i==10){
        return play_game_10();
    }
    cin>>x;
    pair<int,int> p2;
    if(x==10){
        p2=play_game(i+1);
      //  cout<<x+p2.first+p2.second<<" ";
        ans+=x+p2.first+p2.second;
        return make_pair(x,p2.first);
    }
    cin>>y;
    if((x+y)==10){
        p2=play_game(i+1);
        //cout<<x+y+p2.first<<" ";
        ans+=x+y+p2.first;
        return make_pair(x,y);
    }
    //cout<<x+y<<" ";
    play_game(i+1);
    ans+=x+y;
    return make_pair(x,y);
}

int main(){
    play_game(1);
    cout<<ans<<endl;
    return 0;
}