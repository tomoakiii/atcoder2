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
    ll N, K;
    cin >> N >> K;
    vector A(N, vector<ll>(N));
    vector J(N+1, vector<ll>(N+1));
    multiset<ll> allst;
    rep(i,N) rep(j,N) {     
        cin>>A[i][j];
        allst.insert(A[i][j]);
    }
    // cを小さくするほどJは増える
    auto judge = [&](ll c)->bool{
        rep(i,N) {
            rep(j,N) J[i+1][j+1] = A[i][j] > c;
            rep(j,N) J[i+1][j+1] += J[i+1][j];
        }
        rep(j,N){
            rep(i,N) J[i+1][j+1] += J[i][j+1];
        }
        ll mn = INF;
        // c以下の要素の数
        rep(i,N-K+1) {
            rep(j, N-K+1) {
                ll x = J[i+K][j+K] - J[i][j+K] - J[i+K][j] + J[i][j];
                chmin(mn, x);
            }
        }
        if(mn > K*K/2) return true;
        return false;
    };

    ll l = -1, r = (ll)1E9 + 1;    
    while(r > l + 1) {
        ll c = (r+l)/2;
        if(judge(c)) l = c;
        else r = c;
    }
    cout << r << endl;
    return 0;
}