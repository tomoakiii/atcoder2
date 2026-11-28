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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    ll ma=0, mb=0;
    map<ll,ll> mpa, mpb;
    rep(i,N) {
        cin>>A[i]>>B[i];
        chmax(ma,A[i]);
        chmax(mb,B[i]);
        mpa[A[i]]++;
        mpb[B[i]]++;

    }
    ll ans=INF;
    rep(i,N){
        ll sm = ma-A[i] + mb-B[i] + 2;
        if(A[i]==ma && mpa[A[i]]==1)sm--;
        if(B[i]==mb && mpb[B[i]]==1)sm--;
        chmin(ans,sm);
    }
    cout << ans << endl;
    return 0;
}