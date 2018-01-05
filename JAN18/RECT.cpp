#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c,d;
	for(cin>>n;n;n--){
		cin>>a>>b>>c>>d;
		if((a==b && c==d) || (a==c && b==d) || (a==d && b==c))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	
	return 0;
}