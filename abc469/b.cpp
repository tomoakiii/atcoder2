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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; string S;
    cin >> N >> S;
    vector<ll> A(S.size());
    ll ans = 0;

    rep(i,N){
        ll cnt = 3;
        if(i>0) if(S[i-1]=='o') cnt--;
        if(i<N-1) if(S[i+1]=='o') cnt--;
        if(S[i]=='o')cnt--;
        ans += (cnt == 3);
    }
    cout<<ans<<endl;
    return 0;
}