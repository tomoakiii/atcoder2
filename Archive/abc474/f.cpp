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
    ll mxa = 0;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        chmax(mxa, A[i]);
    }
    vector Dv(N+1, vector<ll>{});
    vector<bool> is_prime(N + 1, true );
    for( ll i = 1; i <= N; i++ )
    {
        for( ll j = i; j <= N; j += i )
        {
            Dv[j].push_back(i);
        }
    }
    vector Mat()
    ll ans = 0;
    for(int i=N-1;i>=0;i--){
        if(A[i] > mxa) {
            cout << -1 << endl;
            return 0;
        }
        ll tgt = mxa - A[i];
        ans += tgt;
        for(auto a: Dv[i+1]) {
            A[a-1] += tgt;
        }
    }
    cout << ans << endl;
    return 0;
}