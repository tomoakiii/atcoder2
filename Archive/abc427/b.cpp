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
    ll a = 1;
    auto func = [](ll x)->ll{
        ll nx = 0;
        while(x) {
            nx += x%10;
            x/=10;
        }
        return nx;
    };
    vector<ll> sm(N+1);
    sm[1] = 1;
    for(int i=2; i<=N; i++) {
        sm[i] = sm[i-1] + func(sm[i-1]);
    }
    cout << sm[N] << endl;
    return 0;
}