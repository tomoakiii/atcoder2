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
    int A, B;
    cin>>A>>B;
    int ans = 0;
    for(int i=A; i<=B; i++) {
        string s = to_string(i);
        bool flg = true;
        int sz = s.size();
        rep(i, sz/2) {
            if(s[i] != s[sz-1-i]) flg = false;
        }
        if(flg) ans++;
    }
    cout << ans << endl;
    return 0;
}