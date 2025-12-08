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
    ll N,K;
    cin >> N >> K;
    deque<ll> A(N);
    rep(i,N) cin>>A[i];
    ll mn = INF;
    int mnc;
    rep(i,N) {
        if (chmin(mn, A[i])) {
            mnc = i;
        }
    }
    while(!A.empty() && A.front() == mn) {
        A.pop_front();
    }
    if(A.empty()) {
        cout << 0 << endl;
        return 0;
    }
    reverse(A.begin(), A.end());
    while(A.front() == mn) {
        A.pop_front();
    }

    ll ans = 1;
    int ct = K;
    while(ct < A.size()) {
        ct += K-1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}