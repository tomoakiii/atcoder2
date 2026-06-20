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
    ll N,K,M,X;
    cin >> N >> K >> M >> X;
    vector<deque<ll>> dq(M+1, deque<ll>(N,0));
    int ind=0;
    while(X){
        dq[0][ind++]=X%2;
        X/=2;
    }
    rep(i,M) {
        ll x; cin>>x;
        ind=0;
        while(x){
            dq[i+1][ind++]=x%2;
            x/=2;
        }
    }
    rep(i,K){
        if(dq[0].front()==1) break;
        dq[0].pop_front();
        dq[0].push_back(1);
    }
    ll ans=0;
    for(auto i=1; i<N; i++){
        int N2 = N-i;
        ll p=1;
        ll sm=0;
        for(auto c:dq){
            p=1;
            rep(k,i){
                sm+=p*c[k];
                p*=2;
            }
            p=1;
            for(int k=i;k<N;k++){
                sm+=p*c[k];
                p*=2;
            }
        }
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}