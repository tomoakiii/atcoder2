#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    vector B = A;
    ll rm = K - sm;
    if(M==N) {
        rep(i, N) cout << 0 << " ";
        cout << endl;
    }
    sort(B.begin(), B.end());
    vector Bs = B;
    rep(i, N-1) Bs[i+1] += Bs[i];
    map<int, ll> ans;

    rep(i, N){
        auto f1 = [&](ll c)->bool{
            int ind = upper_bound(B.begin(), B.end(), B[i]+c+1) - B.begin();
            int rt = ind - 1;
            ll ad1 = (Bs[rt] - Bs[N-M-1]);
            ll cnt = (rt-(N-M-1));
            if(cnt<0) return false;
            if (rt >= i && i >= N-M) {
                ad1 -= B[i];
                ad1 += B[N-M-1];
            }
            ll pay = (B[i]+c+1) * cnt - ad1; 
            return (pay > rm - c); 
        };
        ll l, r;
        l = -1, r = rm + 1;
        while (r-l > 1) {
            ll c = (l+r)/2;        
            if (f1(c)) r = c;
            else l = c;
        }
        if(r > rm) ans[B[i]] = -1;
        else ans[B[i]] = r;
    }
    
    rep(i, N) cout << ans[A[i]] << " ";
    cout << endl;
    return 0;
}