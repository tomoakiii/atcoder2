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

// Coodinate Compression
// https://youtu.be/fR3W5IcBGLQ?t=8550
template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

int main(){
    ll N,Q;
    cin >> N >> Q;
    CC<ll> cc;
    vector<tuple<ll, ll, ll>> v;
    vector<ll> A(N+2,-INF),B(N+2);
    for(int i=1;i<=N; i++) {
        cin>>A[i]>>B[i];
        v.push_back(make_tuple(A[i],B[i],i));
    }

    vector<ll> K(Q);
    rep(i,Q){
        cin>>K[i];
        v.push_back(make_tuple(K[i],-1,i));
    }

    sort(v.begin(),v.end());
    vector<bool> visit(N+2);
    vector<ll> weight(N+2);
    ll ans=0;
    vector<ll> ansv(Q);
    dsu UF(N+2);
    for(auto [q,b,i]:v){
        if(b==-1){
            ansv[i]=ans;
        } else {
            visit[i]=true;
            if(visit[i-1] && visit[i+1]) {
                int pi=UF.leader(i-1);
                int fi=UF.leader(i+1);
                ans-=weight[pi];
                ans-=weight[fi];
                ll w = max(max(B[i], weight[pi]), weight[fi]);
                UF.merge(i,i+1);
                int ni=UF.merge(i,i-1);
                weight[ni]=w;
                ans+=w;
            } else if (visit[i-1]) {
                int pi=UF.leader(i-1);
                ans-=weight[pi];
                ll w = max(B[i], weight[pi]);
                int ni=UF.merge(i,i-1);
                weight[ni]=w;
                ans+=w;
            } else if(visit[i+1]){
                int fi=UF.leader(i+1);
                ans-=weight[fi];
                ll w = max(B[i], weight[fi]);
                int ni=UF.merge(i,i+1);
                weight[ni]=w;
                ans+=w;
            } else {
                weight[i]=B[i];
                ans+=B[i];
            }
        }
    }
    for(auto a:ansv) cout<<a<<endl;
    return 0;
}