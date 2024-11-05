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
    vector A(N, vector<bool>(N));
    rep(i,N) A[i][i] = true;
    rep(i,M) {
        int K;
        cin >> K;
        vector<int> v(K);
        rep(k, K) {
            int a;
            cin>>a;
            a--;
            v[k] = a;
            rep(k2, k) {
                A[a][v[k2]] = true;
                A[v[k2]][a] = true;
            }            
        }        
    }
    rep(i, N) rep(j, N) {
        if (!A[i][j]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}