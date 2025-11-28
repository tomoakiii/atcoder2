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

ll toi(char c) {return c-'0';}

int main(){
    string S; cin>>S;
    ll ans = INF;
    int N = S.size();
    for(int l = 0; l+2<N; l++) {
        ll p = toi(S[l+2])  + toi(S[l+1])*10 + toi(S[l])*100;
        chmin(ans, abs(753-p));
    }
    cout<<ans<<endl;
    return 0;
}