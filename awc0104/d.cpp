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
    ll N,M;
    cin >> N >> M;
    vector<ll> T(N);
    rep(i,N) cin>>T[i];
    vector<pair<ll,int>> X(N),Y(N);
    vector<ll> Z(N), P(N);

    rep(i,M) {
        ll p,b; cin>>p>>b;
        p--;
        Z[p] += b;
        X[p].first += b;
        X[p].second++;
        Y[p].first += b;
        Y[p].second++;
        if(p+b<N) X[p+b].second--;
        if(p-b>=0) Y[p-b].second--;
    }

    reverse(Y.begin(), Y.end());
    rep(kkk,2){
        ll cnt = 0;
        ll pl = 0;
        rep(i,N) {
            pl -= cnt;
            chmax(pl,0ll);
            X[i].first += pl;
            pl = X[i].first;
            cnt += X[i].second;
        }
        swap(X,Y);
    }
    reverse(Y.begin(), Y.end());

    ll ans = 0;
    rep(i,N) {
        ll p = X[i].first + Y[i].first - Z[i];
        if(p>T[i]) continue;
        chmax(ans, p);
    }
    cout<<ans<<endl;

    return 0;
}