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
    ll Top;
    cin >> Top;
    while(Top--){
        ll N,S,K;
        cin>>N>>S>>K;
        ll a = K%N;
        vector<ll> ret;
        for (ll i = 1; i * i <= S; i++) {
            if (S % i == 0) {
                ret.push_back(i);
                if (i * i != S) ret.push_back(S/i);
            }
        }
        ll ans = INF;
        for(auto v: ret) {
            ll g = gcd(v, N);
            ll NN = N/g;
            ll p = NN - S/v;
            chmin(ans, p);
        }
        cout << ans << endl;
    }
    return 0;
}