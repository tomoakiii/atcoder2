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
    ll MX = 1E18;
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll st = 1;
    bool flg = true;
    rep(i,N) {
        if(A[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
        if(flg && A[i] > MX/st)  {
            flg = false;
        }
        st *= A[i];
    }
    if(flg) cout << st << endl;
    else cout << -1 << endl;
    return 0;
}