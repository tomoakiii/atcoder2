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
    vector<ll> A(N), B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    vector<ll> T{}, P{};
    ll last = INF;
    rep(i,N) {
        if(A[i] < last) {            
            P.emplace_back(i);
            T.emplace_back(A[i]);
            last = A[i];
        }
    }
    reverse(P.begin(), P.end());
    reverse(T.begin(), T.end());
    rep(i,M) {
        if(B[i] < T[0]) {
            cout << -1 << endl;
            continue;
        }
        int it = lower_bound(T.begin(), T.end(), B[i]) - T.begin();
        if(it == T.size()) {
            cout<< 1 << endl;
            continue;
        }
        if(T[it] == B[i]) {
            cout << 1+P[it] << endl;
        }
        else {
            cout << 1+P[it-1] << endl;
        }
        
    }
    return 0;
}