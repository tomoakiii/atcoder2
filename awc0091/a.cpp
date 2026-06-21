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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll mn = INF;
    ll mx = 0;
    ll last; cin >> last;
    rep(i,N-1){
        ll a; cin >> a;
        chmin(mn, abs(a-last));
        chmax(mx, abs(a-last));
        last = a;
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}