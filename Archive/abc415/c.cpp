#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll T; cin>>T;
    while(T--){
        ll N; string S; cin>>N>>S;
        S = "0" + S;
        ll M = 1<<N;
        vector<bool> Sok(M);
        Sok[0] = true;
        rep(i, M) {            
            if(!Sok[i]) continue;
            rep(j, N) {
                ll p = 1<<j;
                ll nx = i|p;
                if(nx == i) continue;
                if(S[nx] == '1') continue;
                Sok[nx] = true;
            }
        }        
        if(Sok[M-1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}