#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    string S,T; cin>>S>>T;
    ll ans = 0;
    rep(i,N) {
        if(S[i]!=T[i])ans++;
    }
    ans-=K;
    cout<<max(ans,0ll)<<endl;
    return 0;
}