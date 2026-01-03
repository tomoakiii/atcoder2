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
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
    }
    if(sm % N != 0) {
        cout<<-1<<endl;
        return 0;
    }
    ll rm = 0;
    sm /= N;
    ll ans = 0;
    rep(i,N) {
        rm += A[i];
        rm -= sm;
        if(rm != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}