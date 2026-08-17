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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,V;
    cin >> N >> V;
    vector<pair<ll,ll>> vec;
    rep(i,N){
        ll x,d; cin>>x>>d;
        vec.push_back({x,d});
        chmin(mnx,x);
    }
    sort(vec.begin(), vec.end());
    ll mnx = vec[0].first;
    rep(i,N) {
        vec[i].first -= mnx;
        chmax(mxx,vec[i].first);
    }
    ll mxx = vec[N-1].first;
    ll ok = 9e18, ng = 0;
    whike(ok-ng>1){
        ll c = (ok+ng)/2;
        ll range[2] = {0, mxx};
        bool flg = true;
        for(auto [x,d]:vec){
            ll nrange[2] = {x-c, x+c};
            range = {max(range[0],nrange[0]), min(range[1],nrange[1])};
            if(range[1]<range[0]) flg=false;
        }
        if(flg) ok=c;
        else ng=c;
    }

    cout << ans << endl;
    return 0;
}