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
    string S,T; cin>>S>>T;
    int N=S.size();
    vector G(26, vector<ll>(N+100,N+1));
    rep(i,N) {
        int c=S[i]-'a';
        G[c][i] = i+1;
    }
    for(auto t:T) {
        int ti = t-'a';
        for(int i=N+98; i>=0; i--) {
            chmin(G[ti][i], G[ti][i+1]);
        }
    }
    ll ans=0;
    rep(i,N) {
        int c=i;
        for(auto t:T) {
            int ti = t-'a';
            c=G[ti][c];
        }
        ans+=c-1-i;
    }
    cout<<ans<<endl;
    return 0;
}