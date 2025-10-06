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
typedef modint1000000007 mint;

int main(){
    ll N;
    cin >> N;
    int M = 61;
    vector A(N, vector<ll>(M));
    rep(i,N) {
        ll a; cin>>a;
        int k = 0;
        while(a) {
            A[i][k++] = a%2;
            a /= 2;
        }
    }
    vector sm = A;
    rep(i,N-1) {
        rep(j, M) {
            sm[i+1][j] += sm[i][j];
        }
    }
    mint p = 1;
    mint ans = 0;
    
    rep(j,M) {
        rep(i,N) {
            ll cnt1 = sm[N-1][j] - sm[i][j];
            ll len = N - 1 - i;
            if(A[i][j] == 0) {
                ans += p * cnt1;
            } else {
                ans += p * (len - cnt1);
            }
        }
        p *= 2;
    }
    cout << ans.val() << endl;
    return 0;
}