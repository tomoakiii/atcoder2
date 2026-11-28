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
    ll N,W,H;
    cin >> N >> W >> H;
    vector<ll> X(N),Y(N);

    rep(i,N) cin>>X[i]>>Y[i];

    ll ans = 0;
    rep(kkk,1){
        CC<ll> cc;
        CC<ll> ccy;
        rep(i,N){
            cc.add(X[i]);
            //cc.add(X[i]-W);
            ccy.add(Y[i]);
            ccy.add(Y[i]-H);
        }
        ll sz = cc.size();
        vector<vector<ll>> XY(sz);
        rep(i,N){
            XY[cc(X[i])].push_back(ccy(Y[i]));
        }
        rep(i,sz){
            sort(XY[i].begin(), XY[i].end());
        }

        vector<ll> list;
        deque<ll> xs;

        ll szy = ccy.size();
        fenwick_tree<ll> FT(szy);
        rep(i,sz){
            xs.push_back(cc[i]);
            while(xs.front() < cc[i]-W){
                auto x2 = cc(xs.front());
                for(auto y:XY[x2]){
                    FT.add(y,-1);
                }
                xs.pop_front();
            }

            for(auto y:XY[i]) FT.add(y,1);

            for(auto y : Y){
                ll cnt = FT.sum(ccy(y-H), ccy(y)+1);
                chmax(ans, cnt);
            }
        }
        swap(X,Y);swap(H,W);
    }
    cout << ans << endl;
    return 0;
}