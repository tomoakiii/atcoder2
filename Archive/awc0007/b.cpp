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
    ll N,K; cin>>N>>K;
    vector<unordered_set<string>> list(N);
    rep(i,N) {
        ll M; cin>>M;
        rep(j,M) {
            string s;cin>>s;
            list[i].insert(s);
        }
    }
    int ans = 0;
    rep(i,N) {
        for(int j=i+1;j<N;j++) {
            int sm = 0;
            for(auto s: list[i]) if(list[j].contains(s)) sm++;
            if(sm>=K) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}