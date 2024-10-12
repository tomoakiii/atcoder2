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
    ll ans = 0;
    for(char c='A'; c<='Z'; c++){
        ll t = 0, tt = 0;
        bool flg = false;
        rep(i, S.size()) {
            if (S[i] == c) {
                ans += tt;
                t++;
                flg = true;
            }
            if(flg){
                tt += t-1;
            } else {
                tt += t;
            } 
            flg = false;
        }
    }
    cout << ans << endl;
    return 0;
}