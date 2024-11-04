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
    map<ll, vector<int>> mp;
    rep(i,N) {
        ll a;
        cin>>a;
        mp[a].emplace_back(i);
    }
    vector<ll> ans(N);
    int k = 0;
    for(auto m: mp) {
        for(auto c: m.second) {
            ans[c] = k;
        }
        k+=m.second.size();
    }
    rep(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}