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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    fenwick_tree<ll> FT[3];
    rep(i,N) FT[A[i]].add(i,1);
    vector<ll> B(N);
    ll cnt[3];
    rep(i,N){
        cnt[A[i]]++;
        if(A[i]==0)B[i]=cnt[1]+cnt[2];
        if(A[i]==1)B[i]=cnt[2];
    }
    
    while(Q--){
        int op; cin>>op;
        
        if(op==1){
            int i;
            ll x; cin>>i>>x; i--;
            FT[A[i]].add(i,-1);
            A[i] = x;
            FT[A[i]].add(i,1);
        } else if(op == 2){
            int l, r; cin>>l>>r; l--,r--;
            
        }
    }
    return 0;
}