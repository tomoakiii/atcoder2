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
    ll H; cin >> H;
    unordered_map<ll, ll> mp;
    auto func = [&](auto func, ll h)->ll{
        if(mp.contains(h)) return mp[h];
        if(h==1) return 1;        
        mp[h] = 1 + 2*func(func, h/2);
        return mp[h];
    };
    cout<<func(func, H)<<endl;
    return 0;
}