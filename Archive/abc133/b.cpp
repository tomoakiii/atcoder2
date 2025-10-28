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
    ll N,D;
    cin >> N >> D;
    vector X(N, vector<ll>(D));
    rep(i,N) rep(j,D) cin>>X[i][j];
    ll ans = 0;
    auto dist = [&](int a, int b)->ll{
        ll sm = 0;
        rep(i,D) sm+=(X[a][i]-X[b][i])*(X[a][i]-X[b][i]);
        return sm;
    };
    auto issq = [](ll a)->bool{
        ll s = sqrt(a);
        return (s*s == a);
    };
    rep(i,N) for(int j=i+1;j<N;j++) {
        if(issq(dist(i,j)))ans++;
    }
    cout<<ans<<endl;
}