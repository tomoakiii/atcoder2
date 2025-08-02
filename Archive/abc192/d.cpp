#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string X;
    ll M;
    cin>>X>>M;
    if(X.size()==1){
        ll x = X[0]-'0';
        if(x>M) cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    ll d = 0;
    vector<ll> Xi(X.size());
    rep(i, X.size()) {
        Xi[i] = X[i]-'0';
        chmax(d, Xi[i]);
    }
    ll l = d+1, r=M+1;
    auto chk = [&](ll c)->bool{
        ll ans = 0;
        for(ll x: Xi) {
            if(ans > M/c) return false;
            ans *= c;
            ans += x;
        }
        return ans <= M;
    };
    if(!chk(l)) {
        cout<<0<<endl;
        return 0;
    }
    while(r-l>1) {
        ll c = (r+l)/2;
        if(chk(c)) l=c;
        else r=c;
    }
    cout<<l-d<<endl;
    return 0;
}
