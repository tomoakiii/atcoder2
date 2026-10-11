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
    ll N,K;
    cin >> N >> K;
    if(K>N-1)K=N-1;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    if(A[0] > A[N-1]) reverse(A.begin(),A.end());
    while(A.size()>1){
        ll sz = A.size();
        ll x=A.back(); A.pop_back();
        x+=A.back(); A.pop_back();
        if(sz-1 <= K) {
            A.push_back(2*x);
            K--;
        } else {
            A.push_back(x);
        }
    }
    cout<<A[0]<<endl;
    return 0;
}