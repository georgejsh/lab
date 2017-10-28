#include <bits/stdc++.h>
#define lli long long int
#define llu unsigned long long int
#define sa(a,n,t) for(int ii=0;ii<n;ii++) scanf("%"#t"",&a[ii]);
#define rep(i,n) for(i=0;i<n;i++) 
#define reps(i,a,n) for(i=a;i<n;i++) 
#define repss(i,a,b,n) for(i=a;i<n;i+=b) 
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rreps(i,a,n) for(i=n-1;i>=a;i--)
#define validl(i,a,b) ((i>=a)&&(i<=b))?1:0
#define validmat(x,y,a,b,c,d) (validl(x,a,b) && validl(y,a,b))?1:0
#define validmn(x,y,m,n) validmat(x,y,0,m,0,n)
#define valid(i,n) validl(i,0,n)
#define vv(t) vector<vector<t> >
#define v(t) vector<t >
#define mk make_pair
#define pb push_back
#define pa(a,n,t)  for(int i=0;i<n;i++) printf("%"#t" ",a[i]); cout<<endl;
#define p2 pair<int,int>
#define p3 pair<p2,int>
#define fi first
#define se second
#define sd(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pl(a) printf("%lld",a)
#define pd(a) printf("%d",a)
#define sf(a) scanf("%lf",&a)
#define pf(a) printf("%lf",a)
#define nline printf("\n")
#define ss(a) scanf("%s",a)
#define ps(a) printf("%s",a)
#define sc(a) scanf("%c",&a)
#define pc(a) printf("%c",&a)
#define mf(m,f) m.find(f)!=m.end()
#define pp3(m) cout<<m.fi.fi<<" "<<m.fi.se<<" "<<m.se<<" ";
#define pp2(m) cout<<m.fi<<" "<<m.se<<" ";
using namespace std;
lli ati[262144];
lli a[200001];
v(int) adjl[200001];
void dfs(int u,int p,int d){
    int j;
    ati[d]^=a[u];

    rep(j,adjl[u].size()){
        if(adjl[u][j]==p)
            continue;
        dfs(adjl[u][j],u,d+1);
    }
}
void doit(int l,int r){
    if(l==r)
        return;
    int mid=(l+r)/2;
    for(int j=mid+1,k=l;j<=r;j++,k++){
        ati[j]^=ati[k];
    }    
    doit(l,mid);
    doit(mid+1,r);
}
int main(){
    int i,j;
    int n,q;
    int u,v;
    lli m,p;
    
    cin>>n>>q;
    rep(i,n-1){
        cin>>u>>v;
        adjl[v].pb(u);
        adjl[u].pb(v);
    }
    rep(i,200001)
        ati[i]=0;
    rep(i,n)
        cin>>a[i];
    dfs(0,-1,0);
    //pa(ati,n,lld);
    doit(0,262143);
    //pa(ati,n,lld);
    n=262144;
    rep(j,q){
        cin>>m;
        if(m==0)
            cout<<a[0];
        else
        {
            m--;
            m=m%n;
            cout<<ati[n-m-1];
        }
        cout<<endl;
    }
    return 0;
}