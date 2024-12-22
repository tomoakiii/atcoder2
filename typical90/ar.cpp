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
typedef modint1000000007 mint;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ac = 0;
    while(Q--) {
        ll T, x, y;
        cin >> T >> x >> y;
        x--, y--;
        if(T == 1){
            x = (x + ac)%N;
            y = (y + ac)%N;
            swap(A[x], A[y]);
        } else if(T == 2) {
            ac += N - 1;
        } else {
            x = (x + ac)%N;
            cout << A[x] << endl;
        }
    }
    return 0;
}