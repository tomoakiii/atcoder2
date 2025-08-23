#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    rep(i,N) for(int j = i+1; j<N; j++) for(int k = j+1; k < N; k++){
        if(A[i] == A[j] || A[j] == A[k]) continue;
        if(A[k] < A[i] + A[j]) ans++;
    }
    cout << ans << endl;
    return 0;
}