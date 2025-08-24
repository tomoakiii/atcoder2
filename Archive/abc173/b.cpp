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
    ll N; cin>>N;
    unordered_map<string, ll> mp;
    vector<string> st = {"AC", "WA", "TLE", "RE"};
    mp["AC"] = 0;
    mp["WA"] = 0;
    mp["TLE"] = 0;
    mp["RE"] = 0;
    rep(i,N) {
        string t; cin >> t;
        mp[t]++;
    }
    for(auto t: st) {
        cout << t << " x " << mp[t] << endl;
    }
    
    return 0;
}