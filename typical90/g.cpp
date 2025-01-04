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
    int N;
    cin >> N;
    vector<ll> A(N+2, -INF);
    rep(i,N) cin>>A[i+1];
    A[N+1] = INF;
    int Q;
    cin >> Q;
    sort(A.begin(), A.end());
    while(Q--){
        ll b;
        cin >> b;
        int it = lower_bound(A.begin(), A.end(), b) - A.begin();
        ll ans = min(abs(A[it]-b), abs(A[it-1]-b));
        cout << ans << endl;
    }
    return 0;
}