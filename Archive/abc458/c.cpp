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
    ll l=1, r=N;
    ll ans=0;
    rep(i,N) {
        ll c= min(r,l);
        if(S[i]=='C') {
            ans += c;
        }
        r--, l++;
    }
    cout<<ans<<endl;
    return 0;
}