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
    vector<ll> H(N);
    H.push_back(INF);
    rep(i,N) cin>>H[i+1];
    H.push_back(INF);
    vector<ll> L(N),R(N);
    rep(kkk,2) {
        deque<pair<ll,int>> que;
        que.push_back({INF,0});
        rep(i,N) {
            while(que.back().first <= H[i+1]) que.pop_back();
            auto [h,j]=que.back();
            L[i]=j;
            que.push_back({H[i+1],i+1});
        }
        swap(L,R);
        reverse(H.begin(),H.end());
    }
    reverse(R.begin(),R.end());
    rep(i,N) R[i]=N+1-R[i];
    vector<ll> cnt(2*N);
    rep(i,N) {
        ll p=R[i]-L[i]-1;
        cnt[p]++;
    }
    for(ll i=2*N-1; i>0; i--) {
        cnt[i-1]+=cnt[i];
    }
    while(Q--) {
        ll x; cin>>x; cout<<cnt[x]<<endl;
    }
    return 0;
}