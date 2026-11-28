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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N)cin>>S[i];

    rep(i,N){
        bool flg = true;
        rep(j,M){
            if(S[i][j] == 'o') flg = false;
        }
        if(flg) {
            cout << "Faucet " << i+1 << endl;
            return 0;
        }
    }

    rep(j,M){
        bool flg = true;
        rep(i,N){
            if(S[i][j] == 'o') flg = false;
        }
        if(flg) {
            cout << "Drain " << j+1 << endl;
            return 0;
        }
    }
    return 0;
}