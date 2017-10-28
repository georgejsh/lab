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
#define pa(a,n,t)  for(int i=0;i<n;i++) printf("%"#t"",a[i]);
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
#define n 17
int main(){
    long long int a[500],i,j,k;
    cout<<n<<" "<<(n<<2)<<" ";
    rep(i,n-1){
        cout<<i<<" "<<i+1<<" ";
    }    
    rep(i,n)
        a[i]=i;
   rep(i,n){
            cout<<i<<" ";
        }
    rep(i,(n<<2)){
        cout<<i+1<<" ";
    }
    cout<<endl;
    rep(i,(n<<2)){
        long long int k=0;
        rrep(j,n){
            k^=a[j];
            a[j]=k;
        }
        printf("%lld ",k);
    }
}