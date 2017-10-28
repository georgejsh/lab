#include <bits/stdc++.h>
#define lli long long int
#define llu unsigned long long int
#define sa(a,n,t) for(int ii=0;ii<n;ii++) scanf("%"#t"",&a[ii]);
#define rep(i,n) for(i=0;i<n;i++) 
#define reps(i,a,n) for(i=a;i<n;i++) 
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rreps(i,a,n) for(i=n-1;i>=a;i--)
#define validl(i,a,b) ((i>=a)&&(i<=b))?1:0
#define validmat(x,y,a,b,c,d) (validl(x,a,b) && validl(y,a,b))?1:0
#define validmn(x,y,m,n) validmat(x,y,0,m,0,n)
#define valid(i,n) validl(i,0,n)
#define vv(t) vector<vector<t> >
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
#define MAX 1000000007LL
using namespace std;
lli maxim(lli a,lli b){
    return (a+b)%MAX;
}
lli seg[500001];
lli lazy[500001];
void create(int s,int e,int index){
  if(s==e){
    seg[index]=1;
    lazy[index]=0;
    //single node
    return;
  }
  int mid=(s+e)/2;
  create(s,mid,2*index);
  create(mid+1,e,2*index+1);
  seg[index]=0;//maxim(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
  lazy[index]=0;
 //parent node
}
void processlazy(int index,int l,int r){
    if(!lazy[index])
        return;
    if(l!=r){
        lazy[index*2+1]+=lazy[index];
        lazy[index*2+1]%=MAX;
        lazy[index*2]+=lazy[index];
        lazy[index*2]%=MAX;
    }
    if(l==r){
        seg[index]+=lazy[index];
        seg[index]%=MAX;    
    }
    lazy[index]=0;
}
int get(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return 0;
  processlazy(index,s,e);
  if(l<=s && r>=e){
    return seg[index];
  }
  int mid=(s+e)/2;
  return maxim(get(l,r,s,mid,index*2),get(l,r,mid+1,e,index*2+1));
}
void update(int l,int r,int s,int e,int index,lli value){
  if(e<l || r<s)
    return ;  //return what if outside
    //
  //cout<<s<<" "<<e<<" "<<index<<endl;
  if(l<=s && r>=e){
    //if(seg[index]==1)
        lazy[index]+=value;
        lazy[index]%=MAX;
        //processlazy(index,s,e);
      return ;   
  }
  processlazy(index,s,e);
  if(s==e){
    //update single node
    //a[s]=a[s]/seg[index];
    lazy[index]+=value;
    lazy[index]%=MAX;
    //return seg[index];
  }
  int mid=(s+e)/2;
  update(l,r,s,mid,index*2,value);
  update(l,r,mid+1,e,index*2+1,value);
//update parent
  //seg[index]= maxim(seg[index*2],seg[index*2+1]);
  return ;
}
int main(){
    int T,n,m;
    cin>>T;
    int i,j,t;
    vector<p3 > v; 
    lli ans[100002];
    rep(i,T){
        lli k;
        cin>>n>>m;
        v.clear();
        int l,r;
        rep(j,m){
            cin>>t>>l>>r;
            l--;r--;
            v.pb(mk(mk(t,l),r));
        }
        create(0,m-1,1);
        rep(j,n+1)
            ans[j]=0;
        rrep(j,m){
                k=get(j,j,0,m-1,1);
                //cout<<k<<endl;
                if(v[j].fi.fi==1){
                    
                    ans[v[j].fi.se]+=k;
                    ans[v[j].fi.se]%=MAX;
                    //ans[v[j].se+1]-=;
                    ans[v[j].se+1]=(ans[v[j].se+1]-k+MAX)%MAX;
                }
                else{
                    update(v[j].fi.se,v[j].se,0,m-1,1,k);
                }
        }
        lli ll=0;
        rep(j,n){
            ll+=ans[j];
            ll=((ll)%MAX);
            cout<<ll<<' ';
        }
        cout<<endl;
    }

}