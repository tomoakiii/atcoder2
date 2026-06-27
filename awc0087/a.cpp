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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T,X,Y;
    cin >> T >> X >> Y;
    string A,B; cin>>A>>B;
    auto cset=[](char c, ll x)->ll{
        if(c=='L') return x-1;
        if(c=='R') return x+1;
        return x;
    };
    ll ans=0;
    rep(i,T){
        X = cset(A[i], X);
        Y = cset(B[i], Y);
        if(X==Y) ans++;
    }
    cout<<ans<<endl;

    return 0;
}