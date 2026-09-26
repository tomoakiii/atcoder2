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
    ll N,M,D,T;
    cin >> N >> M >> D >> T;
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    map<ll,pair<ll,ll>> mp;
    mp[T+1]={0,0};
    rep(i,N) {
        mp[A[i]].first++;
        mp[A[i]+D].first--;
    }
    rep(i,M) {
        mp[B[i]].second++;
        mp[B[i]+D].second--;
    }
    ll Tak=0,Aok=0;
    ll ans = 0;
    ll last = -1;
    bool flg = false;
    for(auto [k,f]:mp){
        Tak += f.first;
        Aok += f.second;
        if(flg){
            ll len = k - last;
            ans+=len;
        }
        if(Tak>Aok){
            flg= true;
            last = k;
        } else {
            flg = false;
            last = -1;
        }
        if(k>T) break;
    }
    cout<<ans<<"\n";
    return 0;
}