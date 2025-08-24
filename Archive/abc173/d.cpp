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
    rep(i,N) cin>>A[i];
    sort(A.rbegin(), A.rend());
    queue<ll> que;
    que.push(A[0]);
    ll ans = 0;
    for(int i=1; i<N; i++) {
        ll q = que.front();
        ans += q;
        que.pop();
        que.push(A[i]);
        que.push(A[i]);
    }
    cout << ans << endl;
    return 0;
}