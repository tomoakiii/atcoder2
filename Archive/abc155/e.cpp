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
    cin>>S;
    ll dp0=0, dp1=1;
    for(auto c:S){
        int x=c-'0';
        ll dp0n,dp1n;
        dp0n = dp1 + 10 - x;
        chmin(dp0n, dp0 + x);
        if(x == 9) {
            dp1n = dp0 + 1;
            dp1n = dp1;
        } else {
            x++;
            dp1n = dp1 + 10 - x;
            chmin(dp1n, dp0 + x);
        }
        swap(dp0, dp0n);
        swap(dp1, dp1n);
    }
    cout << min(dp0, dp1+1) << endl;
    return 0;
}