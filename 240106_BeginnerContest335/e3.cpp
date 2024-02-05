#include<bits/stdc++.h>
using namespace std;
struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> a(n+1);
  for(auto &nx : a){cin >> nx;}
  UnionFind uf(n+1);
  vector<vector<pair<int,int>>> vp(200005);
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    if(a[u]>a[v]){swap(u,v);}
    if(a[u]==a[v]){uf.unionSet(u,v);}
    else{vp[a[u]].push_back({u,v});}
  }
  vector<int> dp(200005,-1e9);
  dp[uf.root(1)]=1;
  for(auto &nx : vp){
    for(auto [u,v] : nx){
      u=uf.root(u);
      v=uf.root(v);
      if(dp[u]>0){
        dp[v]=max(dp[v],dp[u]+1);
      }
    }
  }
  cout << max(0,dp[uf.root(n)]) << "\n";
  return 0;
}
