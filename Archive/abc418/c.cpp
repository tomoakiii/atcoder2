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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    vector Asum = A;
    rep(i,N-1) Asum[i+1] += Asum[i];
    while(Q--) {
        ll b; cin>>b;
        int it = lower_bound(A.begin(), A.end(), b) - A.begin();
        if(it == N) {
            cout << -1 << endl;
            continue;
        }        
        ll of = 0;
        if(it > 0) {
            of += Asum[it-1];
        }        
        of += (b-1)*(N-it);
        
        cout<<of+1<<endl;
    }
    return 0;
}