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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    fenwick_tree<ll> FT(N);
    vector<ll> A(N);
    ll tot = 0;
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    rep(i,N) {
        FT.add(i,A[i]);
        tot += A[i];
    }

    ll ok = N, ng = 0;
    while(ok-ng > 1){
        ll c=(ok+ng)/2;
        ll sm = FT.sum(0,c);
        ll nx = A[c];
        if(c*nx > sm+K){
            ok = c;
        } else {
            ng = c;
        }
    }
    if(ok == N){
        ll av = (tot+K)/N;
        ll cnt = 0;
        rep(i,N){
            cnt += av - A[i];
        }
        ll rm = K - cnt;
        vector<ll> B(N, av);
        rep(i,rm){
            B[i]++;
        }
        mint ans = 1;
        rep(i,N) ans *= B[i];
        cout << ans.val() << endl;
    } else {
        ll sm = FT.sum(0,ok);
        ll av = (sm + K) / ok;
        vector<ll> B(N, av);
        ll rm = K - (av*ok - sm);
        rep(i,rm){
            B[i]++;
        }
        for(int i=ok; i<N; i++){
            B[i] = A[i];
        }
        mint ans = 1;
        rep(i,N) ans *= B[i];
        cout << ans.val() << endl;
    }

    return 0;
}