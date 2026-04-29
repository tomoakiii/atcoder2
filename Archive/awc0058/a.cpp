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
    ll N,P,T,C;
    cin >> N >> P >> T >> C;
    if(P>=T) {
        cout<<0<<endl;
        return 0;
    }
    rep(i,N) {
        ll s; cin>>s;
        if(s>=T) {
            cout<<C<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}