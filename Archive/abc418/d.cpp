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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll cnt0=0;
    ll od = 0, ev = 1;
    for(auto c: S) {        
        if(c == '0') {
            cnt0++;
        }
        if(cnt0 % 2 == 0) ev++;
        else od++;
    }
    ll ans = 0;
    ans += ev * (ev-1) / 2;
    ans += od * (od-1) / 2;
    cout<<ans<<endl;
    return 0;
}