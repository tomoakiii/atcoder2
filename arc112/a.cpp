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
typedef modint998244353 mint;

int main(){
    int T;cin>>T;
    while(T--){
        int L,R; cin>>L>>R;
        if(2*L > R) cout<<0<<endl;
        else {
            ll p=R-2*L+1;
            cout<<p*(p+1)/2<<endl;
        }
    }
    return 0;
}