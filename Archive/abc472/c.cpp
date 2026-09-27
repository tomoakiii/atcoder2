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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    fenwick_tree<ll> FT(N);
    rep(i,N){
        ll st=max(i-M+1,0ll);
        ll sm=FT.sum(st,i);
        if(sm+A[i]<=K){
            cout<<"Yes"<<endl;
            FT.add(i,A[i]);
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}