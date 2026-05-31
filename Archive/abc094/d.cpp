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
    ll N;
    cin >> N;
    vector<ll> X(N);
    rep(i,N) cin>>X[i];
    sort(X.rbegin(), X.rend());
    ll ID = X[0]/2;
    ll mn = INF;
    ll ans = 0;
    for(int i=1;i<N;i++) {
        ll d = abs(ID - (X[0] - X[i]));
        if(chmin(mn, d)) ans = X[i];
    }
    cout << X[0] << " " << ans << endl;
    return 0;
}