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
typedef pair<ll, ll> pll;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pll> A(M);    
    map<int, ll> mp;
    rep(i,M) {
        cin>>A[i].first>>A[i].second;        
        mp[(A[i].first + A[i].second)%N]++;
        
    }
    ll cnt = 0;
    for(auto m:mp){
        cnt += m.second * (m.second-1) / 2;
    }
    ll ans = M*(M-1)/2 - cnt;
    cout << ans << endl;
    return 0;
}