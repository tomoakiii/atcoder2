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
    string S; cin>>S;
    bool zf = false;
    ll ans = 0;
    for(auto c:S) {
        if('0'<=c && c<='9'){
            if(c == '0') zf = true;
        } else if (c == '+') {
            if(!zf) ans++;
            zf = false;
        }
    }
    if(!zf) ans++;
    cout << ans << endl;
    return 0;
}