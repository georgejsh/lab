#include <bits/stdc++.h>
using namespace std;
int seg[3200001];
int left[3200001];
int right[3200001];
int NEXT_FREE=0;
void create(int s,int e,int index){
  if(s==e){
    //seg[index]=lp[x];
    //single node
    seg[index]=0;
    return;
  }
  left[index]=NEXT_FREE++;
  right[index]=NEXT_FREE++;
  int mid=(s+e)/2;
  create(s,mid,left[index]);
  create(mid+1,e,right[index]);
 // seg[index]=maxim(seg[2*index],seg[2*index+1]);//maxim(seg[index*2].max,seg[index*2+1].max);
 //parent node
}
int get(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return 1;
  if(l<=s && r>=e){
    return seg[index];
  }
  int mid=(s+e)/2;
  return maxim(get(l,r,s,mid,left[index]),get(l,r,mid+1,e,right[index]));
}
int update(int l,int r,int s,int e,int index){
  if(e<l || r<s)
    return index;
  //cout<<s<<" "<<e<<" "<<index<<endl;
  int ID=NEXT_FREE++;
  /*if(l<=s && r>=e){
      //seg[ID]=  //change for lazy 
    //if(seg[index]==1)
      //return 1;   //return what if inside
  }*/
  if(s==e){
    //update single node
    //a[s]=a[s]/seg[index];
    //seg[index]=lp[a[s]];
    //seg[ID]=/1 node update;
    seg[ID]=1;
    return ID;
  }
  int mid=(s+e)/2;
  left[ID]=update(l,r,s,mid,left[index]),y;
  right[ID]=update(l,r,mid+1,e,right[index]);
//update parent
  //seg[index]= maxim(seg[index*2],seg[index*2+1]);
  seg[ID]=seg[left[ID]]+seg[right[ID]];
  return ID;
}
int main(){

}