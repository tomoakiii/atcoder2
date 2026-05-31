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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N), W(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>W[i];
    if(N==1) {
        ll ans = INF;
        rep(i,M) chmin(ans, abs(W[i]-A[0]));
        cout << ans << endl;
        return 0;
    }
    sort(A.begin(), A.end());
    vector<ll> P0, P1;
    for(int i=0; i<N-1; i+=2) P0.push_back(A[i+1] - A[i]);    
    for(int i=1; i<N-1; i+=2) P1.push_back(A[i+1] - A[i]); 
    for(int i = 0; i < P0.size()-1; i++) P0[i+1] += P0[i];
    for(int i = 0; i < P1.size()-1; i++) P1[i+1] += P1[i];
    ll ans = INF;
    rep(k,M) {
        ll w = W[k];
        int it = lower_bound(A.begin(), A.end(), w) - A.begin();
        ll sm = 0;
        if(it <= 1) {
            sm += P1[P1.size()-1];
            sm += abs(A[0] - w);
        } else if (it >= N - 1) {
            sm += P0[P0.size() - 1];
            sm += abs(A[N-1] - w);
        } else {            
            sm += P0[it/2 - 1] + P1[P1.size()-1] - P1[it/2 - 1];
            if(it%2==1) sm += abs(A[it-1] - w);
            else sm += abs(A[it] - w);
        }
        chmin(ans, sm);
    }
    cout << ans << endl;
    return 0;
} 
