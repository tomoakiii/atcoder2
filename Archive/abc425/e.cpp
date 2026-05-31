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
    ll T,M; cin>>T>>M;
    int K = 5001;
    vector Comb(K, vector<ll>(K));
    rep(i,K) {
        Comb[i][0] = 1;
        Comb[0][i] = 1;
        Comb[i][1] = 1;
        Comb[1][i] = 1;
    }
    for (int i = 0; i < K; i++) {
        Comb[i][0] = Comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % M;
        }
    }

    while(T--){
        ll N; cin>>N;
        vector<ll> C(N);
        int total = 0;
        rep(i,N) {
            cin>>C[i];
            total += C[i];
        }
        ll ans = 1;        
        rep(i, N){
            ans *= Comb[total][C[i]];
            ans %= M;
            total -= C[i];
        }
        cout << ans << endl;
    }

    return 0;
}