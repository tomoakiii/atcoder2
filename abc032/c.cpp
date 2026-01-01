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
    ll N,K;
    cin >> N>>K;
    bool isz = false;
    vector<ll> S(N);
    rep(i,N) {
        cin>>S[i];
        if(S[i] == 0) isz = true;
    }
    if(isz) {
        cout << N << endl;
        return 0;
    }
    int l = 0, r = 0;
    ll v = S[0];
    int ans = 0;
    while(r < N){
        if(l==r || v < K) {
            r++;
            if(r == N) break;
            v *= S[r];
        } else {
            v /= S[l];
            l++;
        }
        if(v <= K) {
            // cout << l << " " << r << " " << v << endl;
            chmax(ans, r-l+1);
        }
    }
    cout << ans << endl;
    return 0;
}