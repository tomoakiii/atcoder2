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
    ll N;
    cin >> N;
    ll mn = INF;
    for(ll p = 1; p*p <= N; p++) {
        if(N%p != 0) continue;
        ll d = 0;
        ll pp = N/p;
        while(pp) {
            d++;
            pp/=10;
        }
        chmin(mn, d);
    }
    cout<<mn<<endl;
    return 0;
}