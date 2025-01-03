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
    string S;
    cin >> S;
    string T = "atcoder";
    ll ans = 0;
    rep(i, 6) {
        while(S[i] != T[i]){
            rep(j, T.size()) {
                if(S[j] == T[i]) {
                    swap(S[j], S[j-1]);
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}