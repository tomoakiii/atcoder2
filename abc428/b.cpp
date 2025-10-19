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
    ll N,K;
    string S;
    cin>>N>>K>>S;
    map<string, ll> mp;
    ll mx = 0;
    rep(i,N) {
        string s;
        if(i+K>N) break;
        for(int j=i; j<i+K; j++) {
            s = s + S[j];
        }
        mp[s]++;
        chmax(mx, mp[s]);
    }
    
    cout<<mx<<endl;
    for(auto [m, x]:mp) {
        if(x == mx) cout<<m<<endl;
    }
    return 0;
}