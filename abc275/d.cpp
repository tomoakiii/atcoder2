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
    map<ll, ll> mp;
    auto f = [&](auto f, ll a)->ll{
        if (mp.count(a) != 0) return mp[a];
        if (a == 0) return 1;
        mp[a] = f(f, a/2) + f(f, a/3); 
        return mp[a];
    };
    
    cout << f(f, N) << endl;
    return 0;
}