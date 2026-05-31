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
    int N = S.size();
    ll ans = INF;
    rep(k,2) {
        int st = k;
        ll cnt = 0;
        rep(i,N) {
            int c = S[i] - '0';
            if(c != st)cnt++;
            st++;
            st %= 2;
        }
        chmin(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}