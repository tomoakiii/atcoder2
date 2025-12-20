#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


// Cartesian Tree
// https://youtu.be/XVu8-ZnuOiA?t=9291
template<class T=long long>
struct CartesianTree {
  int n, root;
  vector<int> l, r;
  CartesianTree() {}
  CartesianTree(const vector<T>& a, bool _max=true) {
    n = a.size();
    l = r = vector<int>(n,-1);
    vector<int> st;
    rep(i,n) {
      int p = -1;
      while (st.size() && !((a[st.back()] < a[i])^_max)) {
        int j = st.back(); st.pop_back();
        r[j] = p; p = j;
      }
      l[i] = p;
      st.push_back(i);
    }
    rep(i,st.size()-1) r[st[i]] = st[i+1];
    root = st[0];
  }
};

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i] *= -1;
    }

    ll ans = N*(N+1)/2;
    CartesianTree TR(A);
    auto dfs = [&](auto dfs, int cur)->void{
        ll l = TR.l[cur];
        ll r = TR.r[cur];
        if(l==-1 || r==-1) return;
        ll lc = cur - l;
        ll rc = r - cur;
        ans += lc * rc;
    };
    dfs(dfs, TR.root);
    cout<<ans<<endl;
    return 0;
}