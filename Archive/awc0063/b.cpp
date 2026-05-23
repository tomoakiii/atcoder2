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
    ll N,M;
    cin >> N >> M;
    ll L = 1;
    rep(i,N) {
        ll p; cin>>p;
        ll L2 = lcm(L, p);
        if(L2<L || L2<p || L2>M) {
            cout<<"No"<<endl;
            return 0;
        }
        L=L2;
    }
    cout<<"Yes"<<endl;
    return 0;
}