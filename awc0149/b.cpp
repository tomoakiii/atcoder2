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
    ll N,M;
    cin >> N >> M;
    vector<ll> P(M);
    rep(i,M) cin>>P[i];
    vector<ll> S(N);
    rep(i,N){
        string s; cin>>s;
        rep(j,M) if(s[j]=='o') S[i]+=P[j];
    }
    CC<ll> cc;
    for(auto s:S) cc.add(s);
    int sz = cc.size();
    vector V(sz, vector<int>{});
    rep(i,N){
        V[cc(S[i])].push_back(i);
    }
    reverse(V.begin(),V.end());
    int rank = 1;
    vector<int> ans(N);
    for(auto vv:V){
        for(auto i:vv){
            ans[i] = rank;
        }
        rank += vv.size();
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}