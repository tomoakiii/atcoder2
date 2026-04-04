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
typedef pair<ll,pair<ll,int>> pll;
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
    vector<pair<ll,ll>> XV(N);
    CC cc;
    CC cv;
    rep(i,N) {
        cin>>XV[i].first>>XV[i].second;
        cc.add(XV[i].first);
        cv.add(XV[i].second);
    }
    sort(XV.begin(),XV.end());
    priority_queue<pll, vector<pll>, greater<pll>> que;
    rep(i,Q){
        ll l,r; cin>>l>>r;
        que.push({l,{r,i}});
        cc.add(l);
        cc.add(r);
    }
    ll M=cc.size();
    ll Mv=cv.size();
    vector uv(Mv, deque<int>{});
    fenwick_tree<ll> FT(M),FT2(M);
    rep(i,N) {
        auto [x,v]=XV[i];
        uv[cv(v)].push_back(x);
    }
    for(auto vv:uv)  {
        int k=0;
        for(auto x:vv) {
            FT2.add(cc(x),1);
            FT.add(cc(x),k++);
        }
    }

    vector<ll> ans(Q);
    int i=0;
    while(!que.empty()) {
        auto [l,rj] = que.top();
        auto [r,j] = rj;
        que.pop();
        while(i<N) {
            auto [x,v]=XV[i];
            if(x>=l) break;
            int k=0;
            for(auto x:uv[cv(v)]) {
                FT.add(cc(x),-1);
            }
            uv[cv(v)].pop_front();
            i++;
        }
        ll sm=FT2.sum(cc(l),cc(r)+1);
        sm=sm*(sm+1)/2;
        sm-=FT.sum(cc(l),cc(r)+1);
        ans[j]=sm;
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}