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
    ll N, C;
    cin >> N >> C;
    vector<ll> T(N+1), A(N+1);
    for(int i=1; i<=N; i++) cin>>T[i]>>A[i];
    vector b(N+1, vector<int>(30)); // 0:must 0, 1:must 1, 2: copy, 3: flip;
    rep(j,30) b[0][j] = 2;
    for(int i=1; i<=N; i++) {
        if(T[i] == 1) {
            rep(j, 30) {
                bool p = (A[i]>>j)&1;
                if (p) {
                    b[i][j] = b[i-1][j];
                } else {
                    b[i][j] = 0;
                }
            }            
        } else if (T[i] == 2) {
            rep(j, 30) {
                bool p = (A[i]>>j)&1;
                if (p) {
                    b[i][j] = 1;
                } else {
                    b[i][j] = b[i-1][j];
                }
            }
        } else {
            rep(j, 30) {
                bool p = (A[i]>>j)&1;
                if (p) {
                    if(b[i-1][j] == 3) b[i][j] = 2;
                    else if (b[i-1][j] == 0) b[i][j] = 1;
                    else if (b[i-1][j] == 1) b[i][j] = 0;
                    else if (b[i-1][j] == 2) b[i][j] = 3;
                } else {
                    b[i][j] = b[i-1][j];
                }
            }
        }        
    }
        
    for(int i=1; i<=N; i++) {
        ll ans = 0;
        rep(j, 30){
            bool p = (C >> j) & 1;
            ll pl = (ll)1<<j;
            if (b[i][j] == 1) ans |= pl;
            else if (b[i][j] == 2 && p) ans |= pl;
            else if (b[i][j] == 3 && !p) ans |= pl;        
        }
        C = ans;
        cout << ans << endl;
    }
    return 0;
}