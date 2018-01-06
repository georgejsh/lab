#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
    vector<long long int> a[1000];
    vector<long long int> b[1000];
    for(cin>>t;t;t--){
        cin>>n;
        for(int i=0;i<n;i++){
            a[i]=vector<long long int>(n);
            b[i]=vector<long long int>(n);
            for(int j=0;j<n;j++)
                cin>>a[i][j];
            sort(a[i].begin(),a[i].end());
        }
        for(int i=0;i<n;i++){
            b[0][i]=a[0][i];
            //cout<<b[0][i]<<" ";
        }
        //cout<<endl;
        int i;
        for(i=1;i<n;i++){
            for(int j=0;j<n;j++){
                vector<long long int>::iterator k=lower_bound(a[i-1].begin(),a[i-1].end(),a[i][j]);
                //cout<<"Found k "<<*(k-1)<<"\n ";
                if(b[i-1][k-a[i-1].begin()-1]==-1)
                    b[i][j]=-1;
                else
                b[i][j]=(k-a[i-1].begin())>0?b[i-1][k-a[i-1].begin()-1]+a[i][j]:-1;
                //cout<<b[i][j]<<" ";
            }
            //cout<<endl;
            if(b[i][n-1]==-1){
                i++;
                 break;
                }
        }
        cout<<b[i-1][n-1]<<endl;
        
	}
	
	return 0;
}