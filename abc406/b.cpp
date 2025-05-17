#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    ll s = 1;
    ll lmt = 1;
    
    rep(i,K) {
        lmt *= 10;
    }
    rep(i,N) {
        ll a;
        cin>>a;
        if(lmt/a < s) {
            s = 1;
        } else {
            s *= a;
            if(s>=lmt) s=1;
        }        
    }

    cout<<s<<endl;
    return 0;
}