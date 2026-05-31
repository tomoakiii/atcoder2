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
typedef modint998244353 mint;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    for(int d=1; d<N; d++) {
        vector<bool> match(N-d, 0);
        rep(i, N-d) {
            match[i] = (S[i] == S[i+d]);
        }
        vector<ll> cL(N-d), cR(N-d);
        rep(k,2) {
            int cnt=0;
            rep(i, N-d) {
                if(match[i]) cnt++;
                else {
                    cL[i] = cnt+1;
                    cnt = 0;
                }
            }
            swap(cL, cR);
            reverse(match.begin(), match.end());
        }
        reverse(cR.begin(), cR.end());
        rep(i,N-d) {
            ans += cR[i] * cL[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}