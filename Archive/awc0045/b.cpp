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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N),B(M);
    rep(i,N)cin>>A[i];
    rep(i,M)cin>>B[i];
    vector<mint> As(N+1), Bs(M+1);
    ll p=1e6;
    mint q=1;
    rep(i,N) {
        As[i+1]=As[i]+A[i]*q;
        q*=p;
    }
    q=1;
    rep(i,M) {
        Bs[i+1]=Bs[i]+B[i]*q;
        q*=p;
    }
    q=1;
    rep(i,N) q*=p;
    vector<mint> qs(N+1);
    qs[N] = (mint)1/q;
    for(int i=N-1; i>=0; i--) qs[i] = qs[i+1] * p;

    for(int i=M; i<=N; i++) {
        mint a = As[i] - As[i-M];
        a *= qs[i-M];
        mint b = Bs[M];
        //cerr << a.val() << " " << b.val() << endl;
        if(a.val() == b.val()) {
            cout << i-M+1 << endl;
            return 0;
        }
    }

    cout<<-1<<endl;

    return 0;
}