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
    ll N, Y;
    cin >> N >> Y;
    rep(a, N+1) for(ll b = 0; (a+b)<=N; b++) {
        ll c = (N-a-b);
        ll sm = a*10000 + b*5000 + c*1000;
        if(sm == Y) {
            cout<<a<<" "<<b<<" "<<c<<endl;
            return 0;
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}