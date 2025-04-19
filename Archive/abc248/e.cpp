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
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    if(K==1) {
        cout << "Infinity" << endl;
        return 0;
    }
    rep(i,N) {
        ll x, y;
        cin >> x >> y;
        X[i] = x, Y[i] = y;
    }

    auto FracRed = [](ll a, ll b) -> pair<ll, ll> {
        if (b == 0) return {1, 0};
        if (a == 0) return {0, 1};        
        if(b < 0) a *= -1, b *= -1;
        ll g = gcd(a, b);
        return {a/g, b/g};
    };

    map<pair<ll, ll>, map<pair<ll, ll>, int>> mpab;    
    rep(i, N) for(int j=i+1; j<N; j++) {                
        if(X[i] - X[j] == 0) {
            auto a = FracRed(1, 0);
            pair<ll, ll> b = {X[i], 0};
            mpab[a][b]++;
        } else {
            auto a = FracRed(Y[i] - Y[j], X[i] - X[j]);
            auto [axn, axd] = FracRed(a.first*X[i], a.second);
            auto b = FracRed(Y[i]*axd - axn, axd);
            mpab[a][b]++;
        }
    }
    ll ans = 0;
    for(auto [a, mm]: mpab) for(auto [b, cnt]: mm) {        
        if (cnt >= K * (K-1) / 2) ans++;
    }
    cout << ans << endl;
}