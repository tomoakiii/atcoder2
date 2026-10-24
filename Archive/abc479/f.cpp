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
using S = ll;
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    CC<ll> cc;
    vector<ll> A(N);
    vector<pair<ll,int>> B(N);
    rep(i,N) {
        cin>>A[i];
        cc.add(A[i]);
    }
    rep(i,N) {
        cin>>B[i].first;
        cc.add(B[i].first);
        B[i].second=i;
    }
    sort(B.begin(),B.end());
    int sz = cc.size();
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<ll>(sz,0));
    ll ans=0;
    rep(i,N){
        int j = B[i].second;
        ll pos = cc(A[j]);
        ll cb=cc(B[i].first);
        ans += abs(LS.get(cb) + B[i].first - A[j]);
        if(pos < cb) LS.apply(pos, cb+1, 1);
        else if(pos > cb) LS.apply(cb, pos+1, -1);
    }
    cout << ans << endl;

    return 0;
}