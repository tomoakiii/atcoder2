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
    ll cnt = 0;
    for(ll a = 1; a*a*a <= N; a++) {        
        for(ll b = a; a*b*b <= N; b++) {
            ll cmn = b;
            ll cmx = N / b / a;
            cnt += (cmx - cmn + 1);
        }
    }
    cout<<cnt<<endl;
    return 0;
}