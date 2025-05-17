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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), P(N);
    rep(i,N) {
        ll a;
        cin>>a;
        a--;
        P[a]++;
        A[i] = a;
    }
    int cnt = 0;
    rep(i,M) {
        if(P[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=N-1; i>=0; i--) {
        P[A[i]]--;
        cnt++;
        if(A[i] < M && P[A[i]] == 0) {
            cout << cnt << endl;
            return 0;
        }
    }

    return 0;
}