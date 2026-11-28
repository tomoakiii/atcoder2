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
    ll N,L,R;
    cin >> N >> L >> R;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) A[i+1]+=A[i];
    CC<ll> cc;
    rep(i,N+1){
        cc.add(A[i]);
        cc.add(A[i]-L);
        cc.add(A[i]-R);
    }
    auto sz = cc.size();
    fenwick_tree<ll> FT(sz);
    FT.add(cc(0), 1);
    ll ans = 0;
    for(int i=1; i<=N; i++){
        auto l = cc(A[i] - R);
        auto r = cc(A[i] - L);
        ans += FT.sum(l,r+1);
        FT.add(cc(A[i]), 1);
    }
    cout << ans << endl;
    return 0;
}