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
    ll N, M;
    cin >> N >> M;
    vector S(M, vector<int>{});
    rep(i,M) {
        int k;
        cin>>k;
        S[i].resize(k);
        rep(j,k) {
            cin>>S[i][j];
            S[i][j]--;
        }
    }
    ll ans=0;
    rep(i, 1<<M){
        vector<bool> o2n(N, false);
        rep(j, M){
            if(!(i & 1<<j)) continue;
            for(int c: S[j]) {
                o2n[c] = true;
            }
        }
        bool flg = true;
        rep(i,N) {
            if (!o2n[i]) flg = false;
        }
        if(flg) ans++;
    }   
    cout << ans << endl;
    return 0;
}