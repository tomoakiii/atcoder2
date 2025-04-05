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
    ll p2 = 2;
    ll cnt = 0;
    while(p2 <= N) {
        /*ll n2 = sqrt(N/p2);
        cnt += (n2+1)/2;*/
        for(ll k = 1; k*k*p2<=N; k+=2) {
            cnt++;
        }
        p2 *= 2;
    }
    cout << cnt << endl;
    return 0;
}