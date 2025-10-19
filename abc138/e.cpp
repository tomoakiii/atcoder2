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
    string S, T; cin>>S>>T;
    map<char, int> mp;
    rep(i,S.size()) {
        if(mp.contains(S[i])) continue;
        mp[S[i]] = i;
    }
    vector<int> Tind(T.size());
    rep(i,T.size()) Tind[i] = mp[T[i]];
    int cnt = 0;
    rep(i,T.size()-1) if(Tind[i+1] < Tind[i]) 
    return 0;
}