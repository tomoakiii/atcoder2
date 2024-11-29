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
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(N-1), X(M), Y(M);
    rep(i,N-1) cin>>A[i];
    rep(i,M) cin>>X[i]>>Y[i];
    int k = 0;
    rep(i, N-1) {
        if(k < M && X[k] == (i+1)) {
            T += Y[k];
            k++;
        }
        if (T<=A[i]) {
            cout << "No" << endl;
            return 0;
        }
        T-=A[i];
    }
    cout << "Yes" << endl;
    return 0;
}