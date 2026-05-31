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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    ll cnt = 0;
    rep(i,N) for(int j=i+1; j<N; j++) {
        ll sm = A[i] + A[j];
        int l = lower_bound(A.begin(), A.end(), sm) - A.begin();        
        int tgt = l - 1;
        if(tgt > j) cnt += tgt - j;            
    }
    cout << cnt << endl;
    return 0;
}