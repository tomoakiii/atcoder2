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
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i,N) cin >> S[i];
    int ans = 0;
    rep(i, 1<<N){
        vector<int> cnt('z'-'a'+1);
        rep(j, N) {
            if(i>>j & 1) {
                for(auto c: S[j]) {
                    cnt[c-'a']++;
                }
            }
        }
        int t=0;
        for(auto n: cnt) {
            if(n == K) {
                t++;
            }
        }
        chmax(ans, t);
    } 
    cout << ans << endl;
    return 0;
}