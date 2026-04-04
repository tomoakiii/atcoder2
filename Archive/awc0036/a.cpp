#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector S(N, vector<ll>{});
    rep(i,N) {
        ll M; cin>>M;
        rep(j,M) {
            ll s; cin>>s; S[i].push_back(s);
        }
    }
    int Q; cin>>Q;
    int ng=0;
    while(Q--) {
        int u,d; cin>>u>>d;
        u--,d--;
        if(S[u][d]>0) S[u][d]--;
        else ng++;
    }
    rep(i,N) {
        for(auto s:S[i]) cout<<s<<" ";
        cout<<endl;
    }
    cout<<ng<<endl;
    return 0;
}