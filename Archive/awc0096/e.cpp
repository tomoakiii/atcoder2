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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> H(N);
    rep(i,N){
        cin>>H[i];
    }
    deque<pair<ll,int>> st;
    st.push_front({INF,N});
    vector quer(N,vector<pair<ll,ll>>{});
    rep(i,Q){
        ll l,r; cin>>l>>r;
        l--,r--;
        quer[l].push_back({r,i});
    }
    vector<ll> ans(Q);
    for(int i=N-1;i>=0; i--){
        while(true){
            auto [a,r] = st.front();
            if(a>=H[i]) break;
            else st.pop_front();
        }
        st.push_front({H[i], i});
        for(auto [r,j]:quer[i]){
            ll ng=st.size()-1, ok=0;
            while(ng-ok>1){
                ll c=(ok+ng)/2;
                if(st[c].second > r) ng=c;
                else ok=c;
            }
            ans[j] = ok+1;
        }
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}