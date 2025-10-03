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
    string S; cin>>S;
    map<char, ll> mp;
    rep(i,N) {
        mp[S[i]]++;
    }
    ll exc = 0;
    for(int step=1; step<N; step++) {
        rep(i,N) {
            int j = i+step;
            int k = j+step;
            if(k>=N)break;
            if(S[i] != S[j] && S[j] != S[k] && S[i] != S[k]) exc++;
        }
    }
    ll ans = mp['R']*mp['G']*mp['B']-exc;
    cout<<ans<<endl;
    return 0;
}