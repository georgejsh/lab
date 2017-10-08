#include <bits/stdc++.h>
using namespace std;
#define p3 pair<int, pair<lli, lli> > 
#define lli long long int 

//pair<lli,lli> seg[500001];
vector<pair<lli ,int > > tt;

lli seg[300001];
void create(int s,int e,int index){
  if(s==e){
    seg[index]=0;
    //single node
    return;
  }
  int mid=(s+e)/2;
  create(s,mid,2*index);
  create(mid+1,e,2*index+1);
 seg[index]=max(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
 //parent node
}
lli get(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return 0;
  if(l<=s && r>=e){
    return seg[index];
  }
  int mid=(s+e)/2;
  return max(get(l,r,s,mid,index*2),get(l,r,mid+1,e,index*2+1));
}
lli update(int l,int r,int s,int e,int index,lli value){
  if(e<l || r<s)
    return 0;
  //cout<<s<<" "<<e<<" "<<index<<endl;
  if(l<=s && r>=e){
    if(seg[index]==1)
      return 0;   //return what if outside
  }
  if(s==e){
    //update single node
    //a[s]=a[s]/seg[index];
    seg[index]=value;
    return seg[index];
  }
  int mid=(s+e)/2;
  int x=update(l,r,s,mid,index*2,value),y;
  y=update(l,r,mid+1,e,index*2+1,value);
//update parent
  seg[index]= max(seg[index*2],seg[index*2+1]);
  return seg[index];
}

// pair<lli, lli> find(pair<lli,lli> a,pair<lli,lli> b){
//     pair<lli,lli> res;
//     res.first=max(a.first,b.first);
//     lli temp=min(a.first,b.first);
//     res.second=max(temp,max(b.second,a.second));
//     return res;
// }
// void create(int s,int e,int index){
//   if(s==e){
//     seg[index].first=lp[x];
//     seg[index].second=0;
//     //single node
//     return;
//   }
//   int mid=(s+e)/2;
//   create(s,mid,2*index);
//   create(mid+1,e,2*index+1);
//   seg[index]=find(seg[2*index],seg[2*index+1]);
//  // seg[index]=maxim(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
//  //parent node
// }
// pair<lli,lli> get(int l,int r,int s,int e,int index){
//   if(e<l || r<s)
//    return make_pair(0,0);
//   if(l<=s && r>=e){
//     return seg[index];
//   }
//   int mid=(s+e)/2;
//   return find(get(l,r,s,mid,index*2),get(l,r,mid+1,e,index*2+1));
// }
#define MAXN 100001
vector<p3> adj[100001];
//vector<int> tree[MAXN];
//vector<int> centroidTree[MAXN];
bool centroidMarked[MAXN];

/* method to add edge between to nodes of the undirected tree */
 // void addEdge(int u, int v)
 // {
 //     tree[u].push_back(v);
 //     tree[v].push_back(u);
 // }
//int clockt=0;
//pair<lli,lli> lp[100001];
//pair<int,int> arraydim[100001];

/* method to setup subtree sizes and nodes in current tree */
void DFS(int src, int p, int subtree_size[], int* n)
{
    /* mark node visited */
    //visited[src] = true;
    
    /* increase count of nodes visited */
    *n += 1;

    /* initialize subtree size for current node*/
    subtree_size[src] = 1;

    vector<p3>::iterator it;

    /* recur on non-visited and non-centroid neighbours */
    for (it = adj[src].begin(); it!=adj[src].end(); it++)
        if (it->first!=p && !centroidMarked[it->first])
        {
            DFS(it->first, src, subtree_size, n);
            subtree_size[src]+=subtree_size[it->first];
        }
}

int getCentroid(int src, int p, int subtree_size[], int n)
{
    /* assume the current node to be centroid */
    bool is_centroid = true;

    /* mark it as visited */
    //visited[src] = true;

    /* track heaviest child of node, to use in case node is 
    not centroid */
    int heaviest_child = 0;

    vector<p3>::iterator it;

    /* iterate over all adjacent nodes which are children 
    (not visited) and not marked as centroid to some 
    subtree */
    for (it = adj[src].begin(); it!=adj[src].end(); it++)
        if (it->first!=p && !centroidMarked[it->first])
        {
            /* If any adjacent node has more than n/2 nodes,
            * current node cannot be centroid */
            if (subtree_size[it->first]>n/2)
                is_centroid=false;

            /* update heaviest child */
            if (heaviest_child==0 ||
                subtree_size[it->first]>subtree_size[heaviest_child])
                heaviest_child = it->first;
        }

    /* if current node is a centroid */
    if (is_centroid && n-subtree_size[src]<=n/2)
        return src;

    /* else recur on heaviest child */
    return getCentroid(heaviest_child, src, subtree_size, n);
}
lli maxprofit=0;
int mapto[MAXN];
//vector<pair<lli,lli> > lp[100001];
void dfs1(int c,int p,lli cost,lli profit){
    //arraydim[c].first=clockt;
    pair<lli ,int > temp;
    temp.first=cost;
    temp.second=c;
    tt.push_back(temp);
    ///lp[cc].push_back(temp);
    for(int i=0;i<adj[c].size();i++){
        if(p!=adj[c][i].first && !centroidMarked[adj[c][i].first])
            dfs1(adj[c][i].first,c,cost+adj[c][i].second.first,profit+adj[c][i].second.second);
    }
    
    //arraydim[c].second=clockt;
}
lli m;
vector<pair<int,lli> > ss;
void dfs2(int c,int p,lli cost,lli profit){
    //arraydim[c].first=clockt;
    pair<int ,lli > temp;
    temp.first=c;
    temp.second=profit;
    ss.push_back(temp);
    
    ///lp[cc].push_back(temp);
    for(int i=0;i<adj[c].size();i++){
        if(p!=adj[c][i].first && !centroidMarked[adj[c][i].first])
            dfs2(adj[c][i].first,c,cost+adj[c][i].second.first,profit+adj[c][i].second.second);
    }
    vector<pair<lli,int> >::iterator tem;
    if(m-cost+1<=0){
        return;
    }
    tem=upper_bound(tt.begin(),tt.end(),make_pair(m-cost+1,0));
    //cout<<"for "<<cost<<" "<<profit<<" found at "<<tem-tt.begin()<<endl;
    if(tem-tt.begin()){
        tem--;
        maxprofit=max(maxprofit,profit+get(0,tem-tt.begin(),0,tt.size(),1));
       // cout<<"PP "<<get(0,tem-tt.begin(),0,tt.size(),1)<<" "<<maxprofit<<endl; 
    }
    //arraydim[c].second=clockt;
}
//bool visited[MAXN];
int maptovector[MAXN];
int subtree_size[MAXN];
//int clockt=0;
/* function to get the centroid of tree rooted at src.
* tree may be the original one or may belong to the forest */
int getCentroid(int src)
{
    
    /* initialize auxiliary arrays */
   // memset(visited, false, sizeof visited);
   // memset(subtree_size, 0, sizeof subtree_size);

    /* variable to hold number of nodes in the current tree */
    int n = 0;

    /* DFS to set up subtree sizes and nodes in current tree */
    DFS(src, 0, subtree_size, &n);

    //for (int i=1; i<MAXN; i++)
    //    visited[i] = false;
    
    int centroid = getCentroid(src, 0, subtree_size, n);
    //cout<<"Tree at "<<centroid<<endl;
    //vector<pair<lli,lli> > temp;
    //set<pair<int,int> > ss;
    //ss.push_back(make_pair(0,0));
    dfs1(centroid,0,0,0);
    sort(tt.begin(),tt.end());
    for(int i=0;i<tt.size();i++){
        mapto[tt[i].second]=i;
        //tt[i].first=0;
    }
    create(0,tt.size(),1);
    //lp.push_back(temp);
    //maptovector[centroid]=clockt;
    //dfs2(centroid,centroid,0,0,0);
    for(int i=0;i<adj[centroid].size();i++){
        ss.clear();
        if(!centroidMarked[adj[centroid][i].first])
            dfs2(adj[centroid][i].first,centroid,adj[centroid][i].second.first,adj[centroid][i].second.second);
        //cout<<"Next neighbour"<<endl;
        for(int j=0;j<ss.size();j++)
            update(mapto[ss[j].first],mapto[ss[j].first],0,tt.size(),1,ss[j].second);//,cout<<ss[j].first<<" "<<ss[j].second<<endl;
    }
    centroidMarked[centroid]=true;

    return centroid;
}

/* function to generate centroid tree of tree rooted at src */
int decomposeTree(int root)
{
    //printf("decomposeTree(%d)\n", root);
    tt.clear();
    /* get sentorid for current tree */
    int cend_tree = getCentroid(root);

    //printf("%d ", cend_tree);

    vector<p3>::iterator it;

    /* for every node adjacent to the found centroid
    * and not already marked as centroid */
    for (it=adj[cend_tree].begin(); it!=adj[cend_tree].end(); it++)
    {
        if (!centroidMarked[it->first])
        {
            /* decompose subtree rooted at adjacent node */
            int cend_subtree = decomposeTree(it->first);

            /* add edge between tree centroid and centroid of subtree */
            //centroidTree[cend_tree].push_back(cend_subtree);
           // centroidTree[cend_subtree].push_back(cend_tree);
        }
    }

    /* return centroid of tree */
    return cend_tree;
}

//int m;

//pair<int,int> arraydim[100001];


lli maxtill[100001];
    
// void dfs(int c,int p,lli cost,lli profit){
//     pair<lli,lli> temp;    
//     temp.first=cost;
//     temp.second=profit;
//     cout<<temp.first<<" "<<temp.second<<endl;
//     arr.push_back(temp);
//     for(int i=0;i<adj[c].size();i++){
//         if(p!=adj[c][i].first && !centroidMarked[adj[c][i].first])
//             dfs(adj[c][i].first,c,cost+adj[c][i].second.first,profit+adj[c][i].second.second);
//     }

// // }
// void dfs2(int c,int p){
//    // int cc=maptovector[c];
//     if(lp[c].size()<=1)
//         return;
//     for(int i=0;i<centroidTree[c].size();i++){
//         if(centroidTree[c][i]!=p){
//             dfs2(centroidTree[c][i],c);
//         }
//     }
//     //if(subtree_size[c]==0)
//       //  return;
//     //arr.clear();
//     //cout<<"tree at "<<c<<endl;
//     //dfs(c,0,0,0);
//     //for(int i=arraydim[c].first;i<arraydim[c].second;i++)
//      //   arr.push_back(lp[i]);//,cout<<lp[i].first<<" "<<lp[i].second<<endl;
//     vector<pair<lli,lli> > &arr=lp[c];
//     sort(arr.begin(),arr.end());
//     //maxtill.clear();
//     //maxtill.push_back(arr[0].second);
//     maxtill[0]=arr[0].second;
//     for(int i=1;i<arr.size();i++){
//         //maxtill.push_back(max(maxtill[i-1],arr[i].second));
//         maxtill[i]=max(maxtill[i-1],arr[i].second);
//     }
//     lli rcost=m;
//     for(int i=1;i<arr.size();i++){
//         vector<pair<lli,lli> >::iterator temp;
//         if(rcost-arr[i].first+1<=0){
//             continue;
//         }
//         temp=upper_bound(arr.begin(),arr.begin()+i,make_pair(rcost-arr[i].first+1,0LL));
//         //cout<<"for "<<arr[i].first<<" "<<arr[i].second<<" found at "<<temp-arr.begin()<<endl;
//         if(temp-arr.begin()){
//             temp--;
//             maxprofit=max(maxprofit,arr[i].second+maxtill[temp-arr.begin()]);
//             //cout<<"PP "<<maxprofit<<endl; 
//         }
//     }
// }
int main(){
    int t,nn;int a,b,c,d;
    
    cin>>nn>>m;
    for(int i=0;i<nn-1;i++)
        cin>>a>>b>>c>>d,adj[a].push_back(make_pair(b,make_pair(c,d))),adj[b].push_back(make_pair(a,make_pair(c,d)));//,addEdge(a,b);
    //dfs1(1,0);
    //create(0,n-1,1);
   // cout<<"End Input"<<endl;
  //  return 0;
    int cc=decomposeTree(1);
    //cout<<endl;
    //dfs2(cc,0);
    cout<<maxprofit<<endl;
    return 0;
}