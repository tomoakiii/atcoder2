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
    int s = 0;
    while(s < N && A[s] == 0) {
        s++;
    }
    int t = N-1;
    while(t >= 0 && A[t] == 0) {
        t--;
    }
    if(s >= t) cout << 0 << endl;
    else {
        cout << t - s << endl;
    }
    return 0;
}