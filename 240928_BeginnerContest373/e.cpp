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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(N);
    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    B = A;
    ll rm = K - sm;
    
    vector<ll> ans(N);
    sort(B.rbegin(), B.rend());
    ll pTgt = B[M-1];
    ll smB = 0;
    rep(i, N){
        smB += B[i];
        if (i == M-1) break;
    }

    rep(i, N){
        ll rrm = rm;
        if (A[i] < pTgt) {
            rrm -= (pTgt - A[i]);
        }
        auto f= [&](int c)->bool{
            ll p1M = M * c;
            ll p1Mr = p1M - smB;            
            if (p1Mr > rrm) return true;
            if (p1Mr < 0) return false;
            if (c > B[M] + rrm - p1Mr) return true;
            else return false;

        };
        int l, r;    
        l = 0, r = K;
        while (r-l > 1) {
            int c = (l+r)/2;
            if (f(c)) r = c;
            else l = c;
        }
        ll tans = (r - A[i]);
        if (tans > rm) {
            tans = -1;
        }
        ans[i] = tans;
    }
    
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
    return 0;
}