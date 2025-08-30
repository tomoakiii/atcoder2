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
    ll X,N;
    cin >> X >> N;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    sort(P.begin(), P.end());
    ll st=0, ans, mn=INF;
    for(auto p:P) {
        while(st<p) {
            if(chmin(mn, abs(st-X))) ans=st;
            st++;
        }
        st = p+1;
    }
    for(int i=st; i<=101; i++) {
        if(chmin(mn, abs(i-X))) ans=i;    
    }
    cout << ans << endl;
    return 0;
}